import os
import shlex
import sys

from tools import ninja_syntax

# To build a matching executable or not
NON_MATCHING = False

# Extension constants
ELF_EXT = ".elf"
LD_EXT = ".ld"
MAP_EXT = ".map"
O_EXT = ".o"
YAML_EXT = ".yaml"
SHA_EXT = ".sha"

# Config
GAME_ID = "SLPS01556"
GAME_BIN = GAME_ID[:7] + "." + GAME_ID[7:]

# Paths
CONFIG_DIR = "config"
TOOLS_DIR = "tools"
BUILD_DIR = "build"

LD_SCRIPT = BUILD_DIR + "/" + GAME_ID + LD_EXT
MAP_FILE = BUILD_DIR + "/" + GAME_ID + MAP_EXT
ELF = BUILD_DIR + "/" + GAME_ID + ELF_EXT
EXE = BUILD_DIR + "/" + GAME_BIN
UNDEF_SYMS = BUILD_DIR + "/undefined_syms_auto.txt"
UNDEF_FUNCS = BUILD_DIR + "/undefined_funcs_auto.txt"
SPLAT_CONFIG = CONFIG_DIR + "/" + GAME_ID + YAML_EXT
EXE_HASH = CONFIG_DIR + "/" + GAME_ID + SHA_EXT

GCC_DIR = TOOLS_DIR + "/GCC263"

# Tools
CROSS = "mipsel-linux-gnu-"
AS = CROSS + "as -EL"
LD = CROSS + "ld -EL"
CPP = CROSS + "cpp"
OBJCOPY = CROSS + "objcopy"
CC = os.path.abspath(f"./{GCC_DIR}/cc1")
CPP263 = os.path.abspath(f"./{GCC_DIR}/cpp")
CPLUS = os.path.abspath(f"./{GCC_DIR}/cc1plus")

PYTHON = sys.executable
MASPSX = TOOLS_DIR + "/maspsx/maspsx.py"
SPLAT = "-m splat split"

# Tool Flags
INCLUDE_FLAGS = ["-Iinclude/asm", "-Iinclude"]
AS_FLAGS = INCLUDE_FLAGS + ["-march=r3000", "-mtune=r3000", "-no-pad-sections"]
CPP_FLAGS = INCLUDE_FLAGS + ["-undef", "-Wall", "-lang-c", "-fno-builtin"]
CPPPLUS_FLAGS = INCLUDE_FLAGS + ["-lang-c++"]
C_FLAGS = ["-quiet", "-Wall", "-fno-builtin", "-mno-abicalls", "-funsigned-char", "-G0", "-O2"]
C_FLAGS_G8 = [flag for flag in C_FLAGS if not flag.startswith("-G")] + ["-G8"]
CPLUS_FLAGS = C_FLAGS + []
MASPSX_FLAGS = ["--dont-force-G0", "--expand-div", "--aspsx-version=2.34", "-G8"]
LD_FLAGS = ["--no-check-sections", "-nostdlib", "-s"]

if NON_MATCHING:
    CPP_FLAGS.append("-DNON_MATCHING=1")

# Sources
asm_auto_targets = [
    "asm/1145C.s",
    "asm/179D8.s",
    "asm/1D41C.s",
    "asm/2A85C.s",
    "asm/2BA1C.s",
    "asm/2BE24.s",
    "asm/2FAAC.s",
    "asm/317C0.s",
    "asm/3244C.s",
    "asm/3328C.s",
    "asm/36654.s",
    "asm/psyq_libcd_c002.s",
    "asm/psyq_libcd_c003.s",
    "asm/psyq_libcd_c005.s",
    "asm/psyq_libcd_c008.s",
    "asm/psyq_libcd_c011.s",
    "asm/psyq_libcd_c010.s",
    "asm/psyq_libcd_c009.s",
    "asm/psyq_libcd_c007.s",
    "asm/psyq_libcd_cdrom.s",
    "asm/psyq_libcd_read2.s",
    "asm/40FF8.s",
    "asm/44CE4.s",
    "asm/4775C.s",
    "asm/4E960.s",
    "asm/4cd08.s",
    "asm/8BDC.s",
    "asm/ED8C.s",
    "asm/FB94.s",
    "asm/GsSetAmbient.s",
    "asm/data/1764.rodata.s",
    "asm/data/17EC.rodata.s",
    "asm/data/1818.rodata.s",
    "asm/data/1890.rodata.s",
    "asm/data/19DC.rodata.s",
    "asm/data/1A90.rodata.s",
    "asm/data/1C08.rodata.s",
    "asm/data/1C0C.rodata.s",
    "asm/data/1D0C.rodata.s",
    "asm/data/1E28.rodata.s",
    "asm/data/1EF4.rodata.s",
    "asm/data/1F88.rodata.s",
    "asm/data/2048.rodata.s",
    "asm/data/206C.rodata.s",
    "asm/data/57040.data.s",
    "asm/data/76A44.data.s",
    "asm/data/76DC8.data.s",
    "asm/data/775C4.data.s",
    "asm/data/783DC.data.s",
    "asm/data/79528.data.s",
    "asm/data/7B00C.sdata.s",
    "asm/data/7B020.sdata.s",
    "asm/data/7B050.sdata.s",
    "asm/data/7B0D4.sdata.s",
    "asm/data/7B0DC.sdata.s",
    "asm/data/7B16C.sdata.s",
    "asm/data/7B230.sdata.s",
    "asm/data/7B3C0.sdata.s",
    "asm/data/7B3F8.sdata.s",
    "asm/data/7B424.sbss.s",
    "asm/data/7B468.sbss.s",
    "asm/data/7B46C.sbss.s",
    "asm/data/7B4B4.sbss.s",
    "asm/data/7B4CC.sbss.s",
    "asm/data/800.rodata.s",
    "asm/data/ABC.rodata.s",
    "asm/data/F28.rodata.s",
    "asm/data/FD8.rodata.s",
    "asm/header.s",
    "asm/psyq_libetc_vmode.s",
    "asm/psyq_libetc_vsync.s",
    "asm/psyq_2258.s",
    "asm/psyq_libetc_pad.s",
    "asm/psyq_libetc_intr.s",
    "asm/psyq_libetc_intr_dma.s",
    "asm/psyq_libetc_intr_vb.s",
    "asm/psyq_SpuSetMute.s",
    "asm/psyq_libapi_write.s",
    "asm/psyq_libc_ctype.s",
    "asm/psyq_libc_memchr.s",
    "asm/psyq_libc_printf.s",
    "asm/psyq_libc_prnt.s",
    "asm/psyq_libc_putchar.s",
    "asm/psyq_libc_strlen.s",
    "asm/psyq_libgs_119.s",
    "asm/psyq_libgs_120.s",
    "asm/psyq_libgs_127.s",
    "asm/psyq_libgs_13.s",
    "asm/psyq_libgs_134.s",
    "asm/psyq_libgs_135.s",
    "asm/psyq_libgs_2d_bg0.s",
    "asm/psyq_libgs_2d_com1.s",
    "asm/psyq_libgs_2d_sp0.s",
    "asm/psyq_libgs_box0.s",
    "asm/psyq_libgs_com0.s",
    "asm/psyq_libgs_matrix.s",
    "asm/psyq_libgs_objt.s",
    "asm/psyq_libgte_cmb0.s",
    "asm/psyq_libgte_divf3a.s",
    "asm/psyq_libgte_divf4a.s",
    "asm/psyq_libgte_divft3a.s",
    "asm/psyq_libgte_divft4a.s",
    "asm/psyq_libgte_divg3a.s",
    "asm/psyq_libgte_divg4a.s",
    "asm/psyq_libgte_divgt3a.s",
    "asm/psyq_libgte_divgt4a.s",
    "asm/psyq_libgte_fgo01.s",
    "asm/psyq_libgte_geo.s",
    "asm/psyq_libgte_geo00.s",
    "asm/psyq_libgte_geo02.s",
    "asm/psyq_libgte_geo03.s",
    "asm/psyq_libgte_msc02.s",
    "asm/psyq_libgte_mtx0.s",
    "asm/psyq_libgte_mtx003.s",
    "asm/psyq_libgte_mtx03.s",
    "asm/psyq_libgte_mtx04.s",
    "asm/psyq_libgte_mtx05.s",
    "asm/psyq_libgte_mtx06.s",
    "asm/psyq_libgte_mtx07.s",
    "asm/psyq_libgte_mtx08.s",
    "asm/psyq_libgte_mtx09.s",
    "asm/psyq_libgte_mtx1.s",
    "asm/psyq_libgte_mtx10.s",
    "asm/psyq_libgte_mtx11.s",
    "asm/psyq_libgte_mtx12.s",
    "asm/psyq_libgte_mtx2.s",
    "asm/psyq_libgte_mtx4.s",
    "asm/psyq_libgte_mtx5.s",
    "asm/psyq_libgte_mtx6.s",
    "asm/psyq_libgte_mtx7.s",
    "asm/psyq_libgte_mtx8.s",
    "asm/psyq_libgte_mtx9.s",
    "asm/psyq_libgte_mtxa.s",
    "asm/psyq_libgte_mtxb.s",
    "asm/psyq_libgte_ratan.s",
    "asm/psyq_libgte_reg04.s",
    "asm/psyq_libgte_reg05.s",
    "asm/psyq_libgte_reg06.s",
    "asm/psyq_libgte_reg07.s",
    "asm/psyq_libgte_reg08.s",
    "asm/psyq_libgte_reg09.s",
    "asm/psyq_libgte_smp00.s",
    "asm/psyq_memset.s",
    "asm/psyq_libc_rand.s",
    "asm/psyq_unk1.s",
    "asm/psyq_unk2.s",
    "asm/psyq_libc_strcat.s",
    "asm/psyq_libcd_bios.s",
    "asm/psyq_libcd_iso9660.s",

    "src/psx/SetMem.s",
]
asm_targets = []
c_targets = [
    "src/psx/memory.c",

    "src/timer.c",
    "src/2B78C.c",
    "src/game_flow.c",
    "src/memory_card.c",
    "src/texture_helper.c",
    "src/asset_player.c",
    "src/renderer.c",
    "src/stage_grid.c",
    
    "src/D294.c",
    "src/FA50.c",
    "src/gs_helper.c",
    "src/16334.c",
    "src/1C92C.c",
    "src/sound_engine.c",
    "src/2C694.c",
    "src/305B0.c",
    "src/30CD0.c",
    "src/310CC.c",
    "src/322B4.c",
    "src/3249C.c",
    "src/326E8.c",
    "src/32ACC.c",
    "src/32C00.c",
    "src/32E94.c",
    "src/3311C.c",
    "src/33808.c",
    "src/34040.c",
    "src/34388.c",
    "src/34684.c",
    "src/349B4.c",
    "src/34E8C.c",
    "src/3520C.c",
    "src/354D4.c",
    "src/35730.c",
    "src/359B8.c",
    "src/35C38.c",
    "src/3770C.c",
    "src/39094.c",
    "src/dream_context.c",
    "src/3A930.c",
    "src/3ACC8.c",
    "src/3DA54.c",
    "src/3DB8C.c",
    "src/413A8.c",
    "src/4225C.c",
    "src/43370.c",
    "src/46B20.c",
    "src/477E4.c",
    "src/48494.c",
    "src/48768.c",
    "src/entity.c",
    "src/55DD4.c",
    "src/base_class.c",
    "src/dream_sys.c",
    "src/1CBB8.c",
]
c_targets_g8 = [
    "src/main.c",

    "src/memory.c",
    "src/utils/path_helper.c",

    "src/main_menu.c",
    "src/171F0.c",
    "src/2A0E0.c",
]
cpp_targets = [

]
clean_files = [
    UNDEF_SYMS,
    UNDEF_FUNCS,
    LD_SCRIPT,
    MAP_FILE,
    EXE,
    ELF
] + asm_auto_targets

# Create writer
with open("build.ninja", "w", encoding="utf-8") as f:
    n = ninja_syntax.Writer(f)

    n.variable("ninja_required_version", "1.3")
    n.newline()

    n.variable("as", AS)
    n.variable("ld", LD)
    n.variable("cc", CC)
    n.variable("cpp", CPP)
    n.variable("cpp263", CPP263)
    n.variable("cplus", CPLUS)
    n.variable("objcopy", OBJCOPY)
    n.variable("python", PYTHON)
    n.variable("maspsx", MASPSX)
    n.variable("splat", SPLAT)

    n.variable("asflags", " ".join(AS_FLAGS))
    n.variable("ldflags", " ".join(LD_FLAGS))
    n.variable("cppflags", " ".join(CPP_FLAGS))
    n.variable("cflags", " ".join(C_FLAGS))
    n.variable("cflags_g8", " ".join(C_FLAGS_G8))
    n.variable("cppplusflags", " ".join(CPPPLUS_FLAGS))
    n.variable("cplusflags", " ".join(CPLUS_FLAGS))
    n.variable("maspsxflags", " ".join(MASPSX_FLAGS))

    # Keep ninja_log out of working dir
    n.variable("builddir", BUILD_DIR)
    n.newline()

    # Rule for .s files
    n.rule(
        "asm",
        command="$as $asflags -o $out $in",
        description="AS $out"
    )
    n.newline()

    # Rule for .c files
    n.rule(
        "cc",
        command="$cpp $cppflags $in | $cc $cflags | $python $maspsx $maspsxflags | $as $asflags -o $out",
        description="CC $out",
        depfile="$out.asmproc.d"
    )

    # G8 files
    n.rule(
        "cc_g8",
        command="$cpp $cppflags -DCCG8 $in | $cc $cflags_g8 | $python $maspsx $maspsxflags | $as $asflags -o $out",
        description="CC $out",
        depfile="$out.asmproc.d"
    )
    n.newline()

    # Rule for .cpp files
    n.rule(
        "cplus",
        command="$cpp263 $cppplusflags $in | $cplus $cplusflags | $python $maspsx $maspsxflags | $as $asflags -o $out",
        description="CXX $out",
        depfile="$out.asmproc.d"
    )

    n.rule(
        "link",
        command=f"$ld -o $out -Map {shlex.quote(MAP_FILE)} -T {shlex.quote(LD_SCRIPT)}"
                f" -T {shlex.quote(UNDEF_SYMS)} -T {shlex.quote(UNDEF_FUNCS)} $ldflags $in",
        description="LINK $out"
    )
    n.newline()

    n.rule(
        "objcopy",
        command="$objcopy -O binary $in $out",
        description="OBJCOPY $out"
    )
    n.newline()

    n.rule(
        "splat",
        command="$python $splat $in",
        description="SPLAT $in"
    )
    n.newline()

    quoted_clean_files = " ".join([shlex.quote(f) for f in clean_files])
    n.rule(
        "clean_custom",
        command=f"rm -rf {quoted_clean_files}",
        description="CLEAN"
    )
    n.newline()

    n.rule(
        "checksha",
        command="sha1sum --check $in",
        description="CHECK $in"
    )
    n.newline()

    n.build([LD_SCRIPT, UNDEF_SYMS, UNDEF_FUNCS], "splat", SPLAT_CONFIG)
    n.newline()

    obj_files = []

    for filename in asm_auto_targets + asm_targets:
        out_file = BUILD_DIR + "/" + filename + O_EXT
        obj_files.append(out_file)
        n.build(out_file, "asm", filename)

    for filename in c_targets:
        out_file = BUILD_DIR + "/" + filename + O_EXT
        obj_files.append(out_file)
        n.build(out_file, "cc", filename)

    for filename in c_targets_g8:
        out_file = BUILD_DIR + "/" + filename + O_EXT
        obj_files.append(out_file)
        n.build(out_file, "cc_g8", filename)

    for filename in cpp_targets:
        out_file = BUILD_DIR + "/" + filename + O_EXT
        obj_files.append(out_file)
        n.build(out_file, "cplus", filename)

    n.newline()

    # Link binary to elf
    n.build(
        ELF,
        rule="link",
        inputs=obj_files,
        implicit=[LD_SCRIPT, UNDEF_SYMS, UNDEF_FUNCS]
    )
    n.newline()

    # Build final exe
    n.build(
        EXE,
        rule="objcopy",
        inputs=ELF,
    )
    n.newline()

    # Default rule
    n.build("all", "phony", EXE)
    n.default("all")
    n.newline()

    # Alias to all
    n.build("build", "phony", "all")
    n.newline()

    # Split rom
    n.build("split", "splat", SPLAT_CONFIG)
    n.newline()

    # Clean helper
    n.build("clean", "clean_custom")
    n.newline()

    # Check hash
    n.build("check", "checksha", EXE_HASH, implicit=EXE)
    n.newline()

    # n.build("test", "cplus", "tests/test.cpp")
    # n.newline()


def setup():
    """Install any missing dependencies"""
    import subprocess

    req_file = os.path.join(TOOLS_DIR, "requirements.txt")

    if os.path.exists(req_file):
        print("Installing requirements...")
        subprocess.check_call([PYTHON, "-m", "pip", "install", "-r", req_file])

    maspsx_dir = os.path.dirname(MASPSX)
    if not os.path.isdir(maspsx_dir):
        print(f"Installing maspsx to {maspsx_dir}...")

        subprocess.check_call(["git", "clone", "--recursive", "https://github.com/mkst/maspsx", maspsx_dir])


def check_dependencies():
    """Check for any missing dependencies"""
    import shutil

    if not os.path.isfile(SPLAT_CONFIG):
        print(f"[!] Splat config file not found: {SPLAT_CONFIG}, run \"configure.py setup\"")

    if not os.path.isfile(MASPSX):
        print(f"[!] MASPSX is not found: {MASPSX}, run \"configure.py setup\"")

    if not os.path.isfile(CC):
        print(f"[!] CC is not found: {CC}, run \"configure.py setup\"")

    if not shutil.which(CPP):
        print(f"[!] CPP is not found: {CPP}, run \"configure.py setup\"")

    if not shutil.which(OBJCOPY):
        print(f"[!] OBJCOPY is not found: {OBJCOPY}")


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "setup":
        setup()
    else:
        check_dependencies()
