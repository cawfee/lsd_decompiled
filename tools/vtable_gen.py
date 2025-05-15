DEFAULT_NAMES = {
    0: "Destroy",
    1: "Construct",
    2: "Cleanup"
}


def main(name: str, vtable_start: int, member_count: int, functions_count: int):
    print(f"typedef struct {name}_vtable {{\n    /* 0x000 {vtable_start:08x} */ u32 value;")
    for i in range(functions_count):
        print(f"    /* 0x{(i + 1) * 4:03X} {vtable_start + ((i + 1) * 4):08x} */ void (*{DEFAULT_NAMES.get(i, f'Unk{i}')})(void *);")
    print(f"}} {name}_vtable_t;\n")

    print(f"typedef struct {name} {{\n    /* 0x00 */ {name}_vtable_t *vtable;")
    for i in range(member_count):
        print(f"    /* 0x{(i + 1) * 4:02X} */ s32 m_Unk{i};")
    print(f"}} {name}_t;")


if __name__ == "__main__":
    base_address = 0x80087034
    end_address = 0x80087108
    members = 0x88
    main("class_43370", base_address, int(members / 4), int((end_address - base_address) / 4))
