import collections
import sys
from typing import Optional

import ida_allins
import ida_bytes
import ida_kernwin
import ida_xref
import idaapi
import idautils
import idc
import ida_funcs


def get_instructions(func_addr, max_count: Optional[int] = 3):
    instructions = []

    for instr in idautils.FuncItems(func_addr):
        insn = idautils.DecodeInstruction(instr)

        if not insn:
            continue

        instructions.append(
            (insn.itype, (x.reg for x in insn.ops), list(idautils.DataRefsFrom(instr)))
        )

        if max_count is not None and len(instructions) > max_count:
            break

    return instructions


def calculate_complexity(instructions) -> int:
    if not instructions:
        return 0

    score = 0

    weights = {
        "NOP": 0,
        "DATA_MOVE": 1,
        "ARITH_LOGIC_SIMPLE": 2,
        "ARITH_LOGIC_COMPLEX": 4,
        "MEMORY_LOAD": 5,
        "MEMORY_STORE": 5,
        "CONTROL_FLOW_COND": 7,
        "CONTROL_FLOW_UNCOND": 4,
        "CONTROL_FLOW_CALL": 10,
        "SYSTEM_COPROC": 8,
        "OTHER": 2,
    }
    DATA_REF_BONUS = 2

    nop_itypes = {ida_allins.MIPS_nop}

    data_move_itypes = {
        ida_allins.MIPS_lui,
    }

    arith_logic_simple_itypes = {
        ida_allins.MIPS_add,
        ida_allins.MIPS_addu,
        ida_allins.MIPS_addi,
        ida_allins.MIPS_addiu,
        ida_allins.MIPS_sub,
        ida_allins.MIPS_subu,
        ida_allins.MIPS_and,
        ida_allins.MIPS_andi,
        ida_allins.MIPS_or,
        ida_allins.MIPS_ori,
        ida_allins.MIPS_xor,
        ida_allins.MIPS_xori,
        ida_allins.MIPS_nor,
        ida_allins.MIPS_slt,
        ida_allins.MIPS_sltu,
        ida_allins.MIPS_slti,
        ida_allins.MIPS_sltiu,
        ida_allins.MIPS_sll,
        ida_allins.MIPS_srl,
        ida_allins.MIPS_sra,
        ida_allins.MIPS_sllv,
        ida_allins.MIPS_srlv,
        ida_allins.MIPS_srav,
    }

    arith_logic_complex_itypes = {
        ida_allins.MIPS_mult,
        ida_allins.MIPS_multu,
        ida_allins.MIPS_div,
        ida_allins.MIPS_divu,
        ida_allins.MIPS_mfhi,
        ida_allins.MIPS_mflo,
        ida_allins.MIPS_mthi,
        ida_allins.MIPS_mtlo,
    }

    memory_load_itypes = {
        ida_allins.MIPS_lb,
        ida_allins.MIPS_lbu,
        ida_allins.MIPS_lh,
        ida_allins.MIPS_lhu,
        ida_allins.MIPS_lw,
        ida_allins.MIPS_lwl,
        ida_allins.MIPS_lwr,
        ida_allins.MIPS_lwc1,
        ida_allins.MIPS_lwc2,
    }

    memory_store_itypes = {
        ida_allins.MIPS_sb,
        ida_allins.MIPS_sh,
        ida_allins.MIPS_sw,
        ida_allins.MIPS_swl,
        ida_allins.MIPS_swr,
        ida_allins.MIPS_swc1,
        ida_allins.MIPS_swc2,
    }

    control_flow_cond_itypes = {
        ida_allins.MIPS_beq,
        ida_allins.MIPS_bne,
        ida_allins.MIPS_blez,
        ida_allins.MIPS_bgtz,
        ida_allins.MIPS_bltz,
        ida_allins.MIPS_bgez,
        ida_allins.MIPS_bc0f,
        ida_allins.MIPS_bc0t,
        ida_allins.MIPS_bc1f,
        ida_allins.MIPS_bc1t,
        ida_allins.MIPS_bc2f,
        ida_allins.MIPS_bc2t,
        ida_allins.MIPS_bc3f,
        ida_allins.MIPS_bc3t,
    }

    control_flow_uncond_itypes = {
        ida_allins.MIPS_j,
        ida_allins.MIPS_jr,
    }

    control_flow_call_itypes = {
        ida_allins.MIPS_jal,
        ida_allins.MIPS_jalr,
        ida_allins.MIPS_bltzal,
        ida_allins.MIPS_bgezal,
    }

    system_coproc_itypes = {
        ida_allins.MIPS_syscall,
        ida_allins.MIPS_break,
        ida_allins.MIPS_eret,
        ida_allins.MIPS_deret,
        ida_allins.MIPS_mfc0,
        ida_allins.MIPS_mtc0,
        ida_allins.MIPS_cfc0,
        ida_allins.MIPS_ctc0,
        ida_allins.MIPS_cop0,
        ida_allins.MIPS_mfc1,
        ida_allins.MIPS_mtc1,
        ida_allins.MIPS_cfc1,
        ida_allins.MIPS_ctc1,
        ida_allins.MIPS_cop1,
        ida_allins.MIPS_mfc2,
        ida_allins.MIPS_mtc2,
        ida_allins.MIPS_cfc2,
        ida_allins.MIPS_ctc2,
        ida_allins.MIPS_cop2,
    }

    for itype, _reg_ops_gen, data_refs in instructions:
        instruction_score = 0
        category = "OTHER"

        if itype in nop_itypes:
            category = "NOP"
        elif itype in data_move_itypes:
            category = "DATA_MOVE"
        elif itype in arith_logic_simple_itypes:
            category = "ARITH_LOGIC_SIMPLE"
        elif itype in arith_logic_complex_itypes:
            category = "ARITH_LOGIC_COMPLEX"
        elif itype in memory_load_itypes:
            category = "MEMORY_LOAD"
        elif itype in memory_store_itypes:
            category = "MEMORY_STORE"
        elif itype in control_flow_cond_itypes:
            category = "CONTROL_FLOW_COND"
        elif itype in control_flow_uncond_itypes:
            category = "CONTROL_FLOW_UNCOND"
        elif itype in control_flow_call_itypes:
            category = "CONTROL_FLOW_CALL"
        elif itype in system_coproc_itypes:
            category = "SYSTEM_COPROC"

        instruction_score = weights.get(category, weights["OTHER"])

        if data_refs:
            instruction_score += DATA_REF_BONUS

        score += instruction_score

    return score


def function_calls_fn(caller_addr, callee_addr):
    for xref in idautils.XrefsTo(caller_addr, flags=idaapi.XREF_ALL):
        if xref.type == idaapi.fl_CN:
            called_fn_addr = ida_funcs.get_func(xref.frm).start_ea

            if called_fn_addr == callee_addr:
                return True

    return False


def get_vtable_functions(addr):
    functions = []

    current_ea = addr + 4

    while True:
        if next(idautils.XrefsTo(current_ea, ida_xref.XREF_DATA), None):
            break

        flags = ida_bytes.get_flags(current_ea)
        if not ida_bytes.is_dword(flags):
            current_ea += 4
            continue

        fnc_ptr = ida_bytes.get_wide_dword(current_ea)

        if fnc_ptr:
            functions.append(fnc_ptr)

        current_ea += 4

    return functions


def get_fn_xrefs(fn_addr) -> list:
    xrefs = []

    addr = ida_xref.get_first_cref_to(fn_addr)
    while addr != idc.BADADDR:
        xrefs.append(addr)
        addr = ida_xref.get_next_cref_to(fn_addr, addr)

    return xrefs


def get_vtables():
    memory_new_addr = 0x80017B34
    vtables = []

    for function in idautils.Functions():
        instructions = get_instructions(function)

        if [x[0] for x in instructions] == [
            ida_allins.MIPS_li,
            ida_allins.MIPS_jr,
            ida_allins.MIPS_nop,
        ]:
            vtable_addr = instructions[0][2][0]

            for xref in get_fn_xrefs(function):
                vtable_create_fn = ida_funcs.get_func(xref)
                vtable_create_fn_addr = vtable_create_fn.start_ea

                if not function_calls_fn(memory_new_addr, vtable_create_fn_addr):
                    print("Skip", hex(vtable_create_fn_addr))
                    continue

                vtables.append(
                    {
                        "start": vtable_create_fn_addr,
                        "end": function + (4 * 3),
                        "vtable": vtable_addr,
                        "functions": get_vtable_functions(vtable_addr),
                    }
                )

    return vtables


def print_call_tree(caller_callee_map: dict, out_file):
    callee_to_callers = collections.defaultdict(list)
    all_callers = set()
    all_callees = set()

    for caller, callee in caller_callee_map.items():
        callee_to_callers[callee].append(caller)
        all_callers.add(caller)
        all_callees.add(callee)

    for callee in callee_to_callers:
        callee_to_callers[callee].sort()

    root_nodes = sorted(list(all_callees - all_callers))

    if not root_nodes:
        all_nodes = all_callers.union(all_callees)
        nodes_called = set(caller_callee_map.values())
        potential_roots = sorted(list(all_nodes - nodes_called))

        if potential_roots:
            root_nodes = potential_roots
        elif all_nodes:
            root_nodes = sorted(list(all_nodes))[0:1]
        else:
            return

    def print_branch(node, prefix, is_last, visited_path):
        connector = "└── " if is_last else "├── "
        print(prefix + connector + hex(node), file=out_file)

        if node in visited_path:
            print(
                prefix
                + ("    " if is_last else "│   ")
                + "└── [Cycle detected: Called "
                + str(node)
                + " again]",
                file=out_file,
            )
            return

        callers = callee_to_callers.get(node, [])
        new_prefix = prefix + ("    " if is_last else "│   ")
        new_visited_path = visited_path | {node}

        num_callers = len(callers)
        for i, caller in enumerate(callers):
            is_child_last = i == num_callers - 1
            print_branch(caller, new_prefix, is_child_last, new_visited_path)

    num_roots = len(root_nodes)
    for i, root in enumerate(root_nodes):
        print(hex(root), file=out_file)
        visited_path = {root}

        callers = callee_to_callers.get(root, [])
        num_callers = len(callers)
        for j, caller in enumerate(callers):
            is_child_last = j == num_callers - 1
            print_branch(caller, "", is_child_last, visited_path)

        if i < num_roots - 1:
            print("\n---\n", file=out_file)


def analyze_functions(vtables: list, out_file):
    print("\nFunctions:", file=out_file)

    ignored_functions = []

    # Ignore vtables
    for vtable in vtables:
        ignored_functions.append(vtable["start"])
        ignored_functions.extend(vtable["functions"])

    ignored_functions = set(ignored_functions)

    # Preprocess
    all_functions = []

    for function in idautils.Functions():
        if function in ignored_functions:
            continue

        xref_count = len(get_fn_xrefs(function))
        instructions = get_instructions(function, None)
        complexity = calculate_complexity(instructions)
        name = ida_funcs.get_func_name(function)

        all_functions.append(
            {
                "addr": function,
                "name": name,
                "xrefs": xref_count,
                "instructions": len(instructions),
                "complexity": complexity,
            }
        )

    all_functions.sort(key=lambda f: f["complexity"], reverse=True)

    for func in all_functions:
        print(
            f"[{func['name']:<10}][{func['complexity']:04d}] xrefs={func['xrefs']} instructions={func['instructions']}",
            file=out_file,
        )


def main():
    out_path = ida_kernwin.ask_file(1, "*.txt", "Out File")
    print("Analyzing...")

    out_file = open(out_path, "w", encoding="utf-8")

    vtables = get_vtables()
    callers = {}

    for vtable in vtables:
        vtable_create_fn = vtable["start"]
        create_xrefs = get_fn_xrefs(vtable_create_fn)
        # print(create_xrefs, hex(vtable_create_fn))

        if not create_xrefs:
            # print("No xrefs for", hex(vtable_create_fn))
            continue

        print(f"\nvtable ({vtable['vtable']:08x}):", file=out_file)
        print(f"  - create({vtable_create_fn:08x})", file=out_file)
        for fnc in vtable["functions"]:
            print(f"  - {fnc:08x}", file=out_file)
        print(f"  - get_vtable({vtable['end']:08x})", file=out_file)

        for xref in create_xrefs:
            xref_start = ida_funcs.get_func(xref).start_ea
            callers[xref_start] = vtable_create_fn

    print_call_tree(callers, out_file)
    analyze_functions(vtables, out_file)

    out_file.close()
    print("Done")


if __name__ == "__main__":
    main()
