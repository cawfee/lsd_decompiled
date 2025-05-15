import re

import idc
import idautils
import ida_kernwin


def parse_symbols(file_path):
    symbols = {}

    with open(file_path, "r", encoding="utf8") as f:
        for line in f:
            line = line.strip()

            if line and not line.startswith("//"):
                found = re.search(r"(.+?)\s+\=\s+0x([0-9-a-zA-Z]+);?", line)

                if found:
                    name = found.group(1).strip()
                    addr = int(found.group(2), 16)
                    assert addr not in symbols, f"Duplicate symbol found: {name}"
                    symbols[addr] = name

    return symbols


if __name__ == "__main__":
    symbol_file = ida_kernwin.ask_file(0, "*.txt", "Select Symbol File")

    if symbol_file:
        renamed = 0
        symbols = parse_symbols(symbol_file)
        print(f"Parsed {len(symbols)} symbols from {symbol_file}")

        for function in idautils.Functions():
            function_name = idc.get_func_name(function)

            if symbols.get(function) and function_name != symbols[function]:
                # print(f"Renaming function {function_name} to {symbols[function]}")
                idc.set_name(function, symbols[function], idc.SN_AUTO)
                renamed += 1

        print(f"Renamed {renamed} functions")
