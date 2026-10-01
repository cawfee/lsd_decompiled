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
INCLUDE_FLAGS = ["-Iinclude/asm", "-Iinclude", "-Isrc"]
AS_FLAGS = INCLUDE_FLAGS + ["-march=r3000", "-mtune=r3000", "-no-pad-sections"]
CPP_FLAGS = INCLUDE_FLAGS + ["-undef", "-Wall", "-lang-c", "-fno-builtin"]
CPPPLUS_FLAGS = INCLUDE_FLAGS + ["-lang-c++"]
C_FLAGS = [
    "-quiet",
    "-Wall",
    "-fno-builtin",
    "-mno-abicalls",
    "-funsigned-char",
    "-G0",
    "-O2",
]
C_FLAGS_G8 = [flag for flag in C_FLAGS if not flag.startswith("-G")] + ["-G8"]
CPLUS_FLAGS = C_FLAGS + []
MASPSX_FLAGS = ["--dont-force-G0", "--expand-div", "--aspsx-version=2.21", "-G8"]
LD_FLAGS = ["--no-check-sections", "-nostdlib", "-s"]

CLANG_FORMAT = "clang-format"
CLANG_TIDY = "clang-tidy"
TIDY_FLAGS = INCLUDE_FLAGS + ["-std=c99"]

if NON_MATCHING:
    CPP_FLAGS.append("-DNON_MATCHING=1")

# Sources
asm_game_targets = [

]

asm_psyq_targets = [
    "asm/psyq_unk2.s",
    "asm/psyq_unk3.s",
    "asm/21180.s",
    "asm/22244.s",
    "asm/40FF8.s",
]

asm_data_targets = [
    "asm/data/1764.rodata.s",
    "asm/data/1818.rodata.s",
    "asm/data/1908.rodata.s",
    "asm/data/19DC.rodata.s",
    "asm/data/1AA4.rodata.s",
    "asm/data/1D0C.rodata.s",
    "asm/data/1DD0.rodata.s",
    "asm/data/1E28.rodata.s",
    "asm/data/206C.rodata.s",
    "asm/data/57040.data.s",
    "asm/data/5BDCC.data.s",
    "asm/data/5C6F0.data.s",
    "asm/data/5C8F8.data.s",
    "asm/data/5DCE8.data.s",
    "asm/data/5E234.data.s",
    "asm/data/5ED58.data.s",
    "asm/data/5EF30.data.s",
    "asm/data/5F0E4.data.s",
    "asm/data/5F468.data.s",
    "asm/data/5F540.data.s",
    "asm/data/5F610.data.s",
    "asm/data/5F8B8.data.s",
    "asm/data/5FA40.data.s",
    "asm/data/5FE14.data.s",
    "asm/data/76EE8.data.s",
    "asm/data/775C4.data.s",
    "asm/data/77EFC.data.s",
    "asm/data/783DC.data.s",
    "asm/data/79528.data.s",
    "asm/data/7B00C.sdata.s",
    "asm/data/7B024.sdata.s",
    "asm/data/7B040.sdata.s",
    "asm/data/7B058.sdata.s",
    "asm/data/7B0B8.sdata.s",
    "asm/data/7B0D4.sdata.s",
    "asm/data/7B0E8.sdata.s",
    "asm/data/7B138.sdata.s",
    "asm/data/7B16C.sdata.s",
    "asm/data/7B180.sdata.s",
    "asm/data/7B234.sdata.s",
    "asm/data/7B394.sdata.s",
    "asm/data/7B3C0.sdata.s",
    "asm/data/7B40C.sdata.s",
    "asm/data/7B424.sbss.s",
    "asm/data/7B468.sbss.s",
    "asm/data/7B46C.sbss.s",
    "asm/data/7B4B4.sbss.s",
    "asm/data/7B4CC.sbss.s",
    "asm/data/800.rodata.s",
    "asm/data/ABC.rodata.s",
    "asm/data/F28.rodata.s",
    "asm/data/FD8.rodata.s",
]

asm_header_targets = [
    "asm/header.s",
]

# Hand written assembly
hasm_targets = [
    "src/psyq/write.s",
    "src/psyq/SetMem.s",
    "src/start.s",
]

asm_auto_targets = (
    asm_game_targets
    + asm_psyq_targets
    + asm_data_targets
    + asm_header_targets
    + hasm_targets
)
asm_targets = []

# Psy-Q SDK units, compiled with -G0.
c_psyq_targets = [
    "src/psyq/libc/memory.c",
    "src/psyq/libc/printf.c",
    "src/psyq/libc/prnt.c",
    "src/psyq/libc/memchr.c",
    "src/psyq/libc/strlen.c",
    "src/psyq/libc/ctype.c",
    "src/psyq/libc/putchar.c",
    "src/psyq/libc/strcat.c",
    "src/psyq/malloc.c",
    "src/psyq/gs/matrix.c",
    "src/psyq/gs/134.c",
    "src/psyq/gs/127.c",
    "src/psyq/gs/13.c",
    "src/psyq/gs/2d_sp0.c",
    "src/psyq/gs/2d_com1.c",
    "src/psyq/gs/2d_bg0.c",
    "src/psyq/gs/119.c",
    "src/psyq/gs/120.c",
    "src/psyq/gs/135.c",
    "src/psyq/gs/box0.c",
    "src/psyq/gs/com0.c",
    "src/psyq/gs/objt.c",
    "src/psyq/gs/GsMapModelingData.c",
    "src/psyq/gte/mtx003.c",
    "src/psyq/gte/mtx0.c",
    "src/psyq/gte/mtx2.c",
    "src/psyq/gte/mtx1.c",
    "src/psyq/gte/mtxb.c",
    "src/psyq/gte/mtx4.c",
    "src/psyq/gte/mtx5.c",
    "src/psyq/gte/mtxa.c",
    "src/psyq/gte/mtx6.c",
    "src/psyq/gte/mtx9.c",
    "src/psyq/gte/mtx7.c",
    "src/psyq/gte/mtx8.c",
    "src/psyq/gte/mtx03.c",
    "src/psyq/gte/mtx04.c",
    "src/psyq/gte/mtx05.c",
    "src/psyq/gte/mtx06.c",
    "src/psyq/gte/mtx07.c",
    "src/psyq/gte/mtx08.c",
    "src/psyq/gte/mtx09.c",
    "src/psyq/gte/mtx10.c",
    "src/psyq/gte/mtx11.c",
    "src/psyq/gte/mtx12.c",
    "src/psyq/gte/cmb0.c",
    "src/psyq/gte/reg04.c",
    "src/psyq/gte/reg05.c",
    "src/psyq/gte/reg06.c",
    "src/psyq/gte/reg07.c",
    "src/psyq/gte/reg08.c",
    "src/psyq/gte/reg09.c",
    "src/psyq/gte/fgo01.c",
    "src/psyq/gte/geo.c",
    "src/psyq/gte/geo00.c",
    "src/psyq/gte/geo02.c",
    "src/psyq/gte/geo03.c",
    "src/psyq/gte/msc02.c",
    "src/psyq/gte/divf3a.c",
    "src/psyq/gte/divf4a.c",
    "src/psyq/gte/divg3a.c",
    "src/psyq/gte/divg4a.c",
    "src/psyq/gte/divft3a.c",
    "src/psyq/gte/divft4a.c",
    "src/psyq/gte/divgt3a.c",
    "src/psyq/gte/divgt4a.c",
    "src/psyq/gte/ratan.c",
    "src/psyq/gte/SquareRoot0.c",
    "src/psyq/gpu/sys.c",
    "src/psyq/gs/001.c",
    "src/psyq/gpu/prim.c",
    "src/psyq/gs/003.c",
    "src/psyq/gs/103.c",
    "src/psyq/gs/121.c",
    "src/psyq/gs/002.c",
    "src/psyq/gs/010.c",
    "src/psyq/gte/reg03.c",
    "src/psyq/etc/intr.c",
    "src/psyq/etc/vmode.c",
    "src/psyq/etc/intr_dma.c",
    "src/psyq/etc/intr_vb.c",
    "src/psyq/etc/vsync.c",
    "src/psyq/etc/pad.c",
    "src/psyq/gte/smp00.c",
    "src/psyq/libc/strcpy.c",
    "src/psyq/libc/strstr.c",
    "src/psyq/cd/lib.c",
    "src/psyq/spu/SpuVmSetProgVol.c",
    "src/psyq/snd/SsUtPitchBend.c",
    "src/psyq/spu/SpuVmVSetUp.c",
    "src/psyq/snd/SsSetTableSize.c",
    "src/psyq/snd/SsVabOpenHead.c",
    "src/psyq/snd/SsUtGetVabHdr.c",
    "src/psyq/snd/SsUtGetVagAtr.c",
    "src/psyq/snd/SsSetMVol.c",
    "src/psyq/snd/SsUtGetProgAtr.c",
    "src/psyq/snd/SsVabTransBody.c",
    "src/psyq/snd/SsSetMute.c",
    "src/psyq/snd/SsVabTransCompleted.c",
    "src/psyq/snd/SsSeqCalledTbyT.c",
    "src/psyq/snd/Snd_pause.c",
    "src/psyq/snd/Snd_tempo.c",
    "src/psyq/snd/Snd_replay.c",
    "src/psyq/snd/SsVabClose.c",
    "src/psyq/snd/_SsUtResolveADSR.c",
    "src/psyq/snd/SsUtReverbOn.c",
    "src/psyq/snd/SsUtSetVagAtr.c",
    "src/psyq/snd/_SsSndNextSep.c",
    "src/psyq/snd/_SsReadDeltaValue.c",
    "src/psyq/snd/Snd_stop.c",
    "src/psyq/spu/SpuSetMute.c",
    "src/psyq/spu/SpuVmDamperOn.c",
    "src/psyq/spu/SpuVmDamperOff.c",
    "src/psyq/snd/SsSeqSetVol.c",
    "src/psyq/snd/Snd_SetReplayMode.c",
    "src/psyq/snd/Snd_setvol_data.c",
    "src/psyq/snd/SsSeqOpen.c",
    "src/psyq/snd/Snd_SetPlayMode.c",
    "src/psyq/snd/seq_close.c",
    "src/psyq/snd/Snd_SetPauseMode.c",
    "src/psyq/gs/GsInit3D.c",
    "src/psyq/cd/CdInit.c",
    "src/psyq/gs/GsGetTimInfo.c",
    "src/psyq/libc/memset.c",
    "src/psyq/gs/110.c",
    "src/psyq/gs/GsSetFlatLight.c",
    "src/psyq/gs/Gssub_make_matrix.c",
    "src/psyq/libc/rand.c",
    "src/psyq/gs/GsSetRefView2.c",
    "src/psyq/gs/GsGetLw.c",
    "src/psyq/gs/GsDrawOt.c",
    "src/psyq/gs/GsClearOt.c",
    "src/psyq/gs/GsSetLightMode.c",
    "src/psyq/gs/TransposeMatrix.c",
    "src/psyq/gs/SetFogNear.c",
    "src/psyq/libpress/libpress.c",
    "src/psyq/libc/exit.c",
    "src/psyq/libpress/vlc.c",
    "src/psyq/libpress/vlc2.c",
    "src/psyq/cd/c002.c",
    "src/psyq/cd/c003.c",
    "src/psyq/cd/read2.c",
    "src/psyq/cd/c005.c",
    "src/psyq/cd/c008.c",
    "src/psyq/cd/c011.c",
    "src/psyq/cd/c010.c",
    "src/psyq/cd/cdrom.c",
    "src/psyq/cd/c009.c",
    "src/psyq/cd/c007.c",
    "src/psyq/libc/atoi.c",
    "src/psyq/libc/todigit.c",
    "src/psyq/card/c172.c",
    "src/psyq/card/c171.c",
    "src/psyq/card/card.c",
    "src/psyq/card/a78.c",
    "src/psyq/card/a74.c",
    "src/psyq/card/a75.c",
    "src/psyq/card/c112.c",
    "src/psyq/card/a80.c",
]

# Game units, compiled with -G8.
c_game_targets = [
    "src/file/tim_list.c",
    "src/main.c",
    "src/memory/memory.c",
    "src/utils/cd_paths.c",
    "src/menu/main_menu.c",
    "src/menu/card/memory_card.c",
    "src/file/file_buf.c",
    "src/sound/bgm.c",
    "src/sound/sound.c",
    "src/sys/system.c",
    "src/sys/screen.c",
    "src/dream/dream_sys.c",
    "src/dream/dream_session_path.c",
    "src/file/debug_file_driver.c",
    "src/menu/mdec_movie.c",
    "src/scene/render_context.c",
    "src/file/str_stream.c",
    "src/sys/pad.c",
    "src/sys/display_ref.c",
    "src/base/base_class.c",
    "src/file/cd_file_driver.c",
    "src/file/tmd_prim_geom.c",
    "src/base/object_math.c",
    "src/dream/dream_generation.c",
    "src/dream/dream_generation_sdata.c",
    "src/dream/generation_structure.c",
    "src/menu/card/comment_input.c",
    "src/scene/map_scene.c",
    "src/scene/link.c",
    "src/dream/generation_apply.c",
    "src/graphics/renderer.c",
    "src/base/timer.c",
    "src/sys/game_flow.c",
    "src/menu/movie_screen.c",
    "src/scene/stage_grid.c",
    "src/file/tmd_prim.c",
    "src/graphics/display.c",
    "src/file/file_object.c",
    "src/graphics/effect.c",
    "src/graphics/effect_base.c",
    "src/menu/text_line.c",
    "src/menu/glyph.c",
    "src/menu/sprite.c",
    "src/sound/seq_file.c",
    "src/base/frame_phase.c",
    "src/graphics/light.c",
    "src/graphics/flat_light.c",
    "src/file/tmd_model.c",
    "src/file/model_part.c",
    "src/menu/ui_sprite.c",
    "src/file/object_model.c",
    "src/file/object_model_list.c",
    "src/menu/tile_buffer.c",
    "src/menu/sprite_atlas.c",
    "src/file/model_part_list.c",
    "src/file/cd_stream.c",
    "src/dream/dream_session.c",
    "src/scene/scene.c",
    "src/graphics/scene_renderer.c",
    "src/scene/notify_node.c",
    "src/scene/scene_node.c",
    "src/dream/generation_sprite.c",
    "src/scene/actor.c",
    "src/base/render_sort.c",
    "src/psyq/spu/S_I.c",
    "src/psyq/snd/24490.c",
    "src/psyq/snd/272A8.c",
    "src/sys/display_border.c",
    "src/base/transform.c",
    "src/scene/stage_texture.c",
    "src/file/tim_image.c",
    "src/menu/ui_screen.c",
    "src/menu/sprite_node.c",
    "src/menu/graph_screen.c",
    "src/menu/card/select_menu.c",
    "src/scene/map_scene_post.c",
    "src/scene/entity.c",
    "src/psyq/snd/22D88.c",
]

cpp_targets = []


def _find_c_sources(*roots):
    """All .c/.h files under the given roots, used by clang-format."""
    found = []
    for root in roots:
        for dirpath, _dirnames, filenames in os.walk(root):
            for name in filenames:
                if name.endswith((".c", ".h")):
                    found.append(os.path.join(dirpath, name))
    return sorted(found)


format_targets = _find_c_sources("src", "include")
tidy_targets = sorted(set(c_psyq_targets + c_game_targets + cpp_targets))

clean_files = [
    UNDEF_SYMS,
    UNDEF_FUNCS,
    LD_SCRIPT,
    MAP_FILE,
    EXE,
    ELF,
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
    n.variable("clang_format", CLANG_FORMAT)
    n.variable("clang_tidy", CLANG_TIDY)
    n.variable("formatfiles", " ".join(shlex.quote(f) for f in format_targets))
    n.variable("tidyfiles", " ".join(shlex.quote(f) for f in tidy_targets))
    n.variable("tidyflags", " ".join(TIDY_FLAGS))

    # Keep ninja_log out of working dir
    n.variable("builddir", BUILD_DIR)
    n.newline()

    # Rule for .s files
    n.rule("asm", command="$as $asflags -o $out $in", description="AS $out")
    n.newline()

    # Rule for .c files
    n.rule(
        "cc",
        command="$cpp $cppflags $in | $cc $cflags | $python $maspsx $maspsxflags | $as $asflags -o $out",
        description="CC $out",
        depfile="$out.asmproc.d",
    )

    # G8 files
    n.rule(
        "cc_g8",
        command="$cpp $cppflags -DCCG8 $in | $cc $cflags_g8 | $python $maspsx $maspsxflags | $as $asflags -o $out",
        description="CC $out",
        depfile="$out.asmproc.d",
    )
    n.newline()

    # Rule for .cpp files
    n.rule(
        "cplus",
        command="$cpp263 $cppplusflags $in | $cplus $cplusflags | $python $maspsx $maspsxflags | $as $asflags -o $out",
        description="CXX $out",
        depfile="$out.asmproc.d",
    )

    n.rule(
        "link",
        command=f"$ld -o $out -Map {shlex.quote(MAP_FILE)} -T {shlex.quote(LD_SCRIPT)}"
        f" -T {shlex.quote(UNDEF_SYMS)} -T {shlex.quote(UNDEF_FUNCS)} $ldflags $in",
        description="LINK $out",
    )
    n.newline()

    n.rule("objcopy", command="$objcopy -O binary $in $out", description="OBJCOPY $out")
    n.newline()

    # TQDM_DISABLE=1 drops splat progress bars (token noise for agents / CI logs)
    n.rule(
        "splat",
        command="env TQDM_DISABLE=1 $python $splat $in",
        description="SPLAT $in",
    )
    n.newline()

    quoted_clean_files = " ".join([shlex.quote(f) for f in clean_files])
    n.rule("clean_custom", command=f"rm -rf {quoted_clean_files}", description="CLEAN")
    n.newline()

    # Full resplit: wipe generated asm/ then splat (use after symbol/map changes)
    n.rule(
        "resplit_custom",
        command="rm -rf asm && env TQDM_DISABLE=1 $python $splat $in",
        description="RESPLIT $in",
    )
    n.newline()

    n.rule("checksha", command="sha1sum --check $in", description="CHECK $in")
    n.newline()

    n.rule("format", command="$clang_format -i $formatfiles", description="FORMAT")
    n.newline()
    n.rule(
        "format_check",
        command="$clang_format --dry-run --Werror $formatfiles",
        description="FORMAT-CHECK",
    )
    n.newline()
    n.rule("tidy", command="$clang_tidy $tidyfiles -- $tidyflags", description="TIDY")
    n.newline()

    n.build([LD_SCRIPT, UNDEF_SYMS, UNDEF_FUNCS], "splat", SPLAT_CONFIG)
    n.newline()

    obj_files = []

    for filename in asm_auto_targets + asm_targets:
        out_file = BUILD_DIR + "/" + filename + O_EXT
        obj_files.append(out_file)
        n.build(out_file, "asm", filename)

    for filename in c_psyq_targets:
        out_file = BUILD_DIR + "/" + filename + O_EXT
        obj_files.append(out_file)
        n.build(out_file, "cc", filename)

    for filename in c_game_targets:
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
        implicit=[LD_SCRIPT, UNDEF_SYMS, UNDEF_FUNCS],
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

    # Wipe asm/ and split from scratch
    n.build("resplit", "resplit_custom", SPLAT_CONFIG)
    n.newline()

    # Clean helper
    n.build("clean", "clean_custom")
    n.newline()

    n.build("format", "format")
    n.newline()

    n.build("format-check", "format_check")
    n.newline()

    n.build("tidy", "tidy")
    n.newline()

    # Check hash
    n.build("check", "checksha", EXE_HASH, implicit=[EXE])
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

        subprocess.check_call(
            [
                "git",
                "clone",
                "--recursive",
                "https://github.com/mkst/maspsx",
                maspsx_dir,
            ]
        )


def check_dependencies():
    """Check for any missing dependencies"""
    import shutil

    if not os.path.isfile(SPLAT_CONFIG):
        print(
            f'[!] Splat config file not found: {SPLAT_CONFIG}, run "configure.py setup"'
        )

    if not os.path.isfile(MASPSX):
        print(f'[!] MASPSX is not found: {MASPSX}, run "configure.py setup"')

    if not os.path.isfile(CC):
        print(f'[!] CC is not found: {CC}, run "configure.py setup"')

    if not shutil.which(CPP):
        print(f'[!] CPP is not found: {CPP}, run "configure.py setup"')

    if not shutil.which(OBJCOPY):
        print(f"[!] OBJCOPY is not found: {OBJCOPY}")


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "setup":
        setup()
    else:
        check_dependencies()
