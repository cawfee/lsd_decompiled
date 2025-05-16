import os
import re
import subprocess

from rich.console import Console
from rich.progress import Progress, TextColumn, BarColumn
from rich.table import Table
from rich.text import Text

BUILD_DIR = "build"
NON_MATCHING_DIR = "asm/nonmatchings"
BUILD_SRC_DIR = f"{BUILD_DIR}/src"

OBJDUMP = "mips-linux-gnu-objdump"
TEXT_SIZE_RE = re.compile(r"\.text\s+([0-9a-fA-F]{8})")
FUNCTIONS_RE = re.compile(r"([0-9a-fA-F]{8})\s+<(.+)>:")

CONSOLE = Console()


def get_object_size(fp: str) -> int:
    out = subprocess.check_output([OBJDUMP, "-h", fp], encoding="utf-8")
    size = TEXT_SIZE_RE.search(out)
    return int(size.group(1), 16)


def parse_c_obj(fp: str):
    out = subprocess.check_output([OBJDUMP, "-drwh", fp], encoding="utf-8")
    total_size = int(TEXT_SIZE_RE.search(out).group(1), 16)
    functions = FUNCTIONS_RE.findall(out)

    decompiled_amount = 0

    end_size = total_size
    for start_size, name in functions[::-1]:
        start_size = int(start_size, 16)
        func_size = end_size - start_size
        non_matching_path = os.path.join(
            NON_MATCHING_DIR,
            os.path.relpath(fp, BUILD_SRC_DIR).replace(".c.o", "")
        )

        if not os.path.isfile(os.path.join(non_matching_path, name + ".s")):
            decompiled_amount += func_size

        end_size = start_size

    return decompiled_amount, total_size


def main():
    total_size = 0
    total_decompiled = 0
    psyq_size = 0
    file_stats = []

    for root, _, files in os.walk(BUILD_DIR):
        for file in files:
            fp = os.path.join(root, file)

            if file.endswith(".s.o"):
                obj_size = get_object_size(fp)

                if "src/" not in fp:
                    # Skip default libs
                    if file.startswith("psyq_"):
                        psyq_size += obj_size
                    else:
                        file_stats.append({"path": fp, "decompiled": 0, "total": obj_size, "type": "asm"})
                else:
                    # Assume hasm is 100%
                    file_stats.append({"path": fp, "decompiled": obj_size, "total": obj_size, "type": "hasm"})

                total_size += obj_size
            elif file.endswith(".c.o"):
                decompiled_size, obj_size = parse_c_obj(fp)
                file_stats.append({"path": fp, "decompiled": decompiled_size, "total": obj_size, "type": "C"})
                total_size += obj_size
                total_decompiled += decompiled_size
            # else:
            #     print("Skip", fp)

    CONSOLE.print("\n[bold underline cyan]Progress Report[/]")

    total_progress = (total_decompiled / total_size) * 100
    color = "green" if total_progress > 75 else ("yellow" if total_progress > 25 else "red")

    CONSOLE.print("\n[bold]Overall Progress:[/]")

    with Progress(
        TextColumn("[progress.description]{task.description}"),
        BarColumn(),
        TextColumn("[progress.percentage]{task.percentage:>3.1f}%"),
        TextColumn(f"({total_decompiled:,} / {total_size:,} bytes)"),
        console=CONSOLE,
        transient=False
    ) as progress:
        progress.add_task(f"[{color}]Total Decompiled", total=total_size, completed=total_decompiled)

    CONSOLE.print(f"\n[default]PSYQ Size: {psyq_size}/{total_size} ({psyq_size / total_size * 100:.2f}%)")

    CONSOLE.print("\n[bold]File Breakdown:[/]")
    table = Table(show_header=True, header_style="bold magenta")
    table.add_column("Source File", style="dim", width=60)
    table.add_column("Type", justify="center")
    table.add_column("Decompiled Bytes", justify="right")
    table.add_column("Total Bytes", justify="right")
    table.add_column("Percentage", justify="right")

    def sort_key(item):
        is_c = item["type"] == "C"
        perc = (item["decompiled"] / item["total"] * 100) if item["total"] > 0 else 0
        return not is_c, -perc

    file_stats.sort(key=sort_key)

    for stat in file_stats:
        path = stat["path"]
        decompiled = stat["decompiled"]
        total = stat["total"]
        file_type = stat["type"]

        display_path = os.path.relpath(path, BUILD_SRC_DIR).rpartition(".o")[0]
        percentage = (decompiled / total * 100) if total > 0 else 0.0

        if file_type == "asm":
            perc_text = Text("N/A", style="dim")
        elif percentage == 100.0:
            perc_text = Text(f"{percentage:.2f}%", style="bold green")
        elif percentage > 50.0:
            perc_text = Text(f"{percentage:.2f}%", style="green")
        elif percentage > 0.0:
            perc_text = Text(f"{percentage:.2f}%", style="yellow")
        else:
            perc_text = Text(f"{percentage:.2f}%", style="red")

        table.add_row(
            display_path,
            file_type,
            f"{decompiled:,}",
            f"{total:,}",
            perc_text
        )

    CONSOLE.print(table)


if __name__ == "__main__":
    main()
