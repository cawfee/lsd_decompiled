.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel start
    lui        $v0, 0x8009
    addiu      $v0, $v0, -0x53E0
    lui        $v1, 0x8009
    addiu      $v1, $v1, 0xC68
clear_bss:
    sw         $zero, 0x0($v0)
    addiu      $v0, $v0, 0x4
    sltu       $at, $v0, $v1
    bnez       $at, clear_bss
     nop
    addiu      $v0, $zero, 0x4
    nop
    nop
    nop
    nop
    lui        $a0, 0x8001
    addiu      $a0, $a0, 0x1A48
    addu       $a0, $a0, $v0
    lw         $v0, 0x0($a0)
    lui        $t0, 0x8000
    or         $sp, $v0, $t0
    lui        $a0, 0x8009
    addiu      $a0, $a0, 0xC68
    sll        $a0, $a0, 0x3
    srl        $a0, $a0, 0x3
    lui        $v1, 0x8007
    lw         $v1, -0x4A7C($v1)
    nop
    subu       $a1, $v0, $v1
    subu       $a1, $a1, $a0
    or         $a0, $a0, $t0
    lui        $at, 0x8009
    sw         $ra, -0x53DC($at)
    lui        $gp, 0x8009
    addiu      $gp, $gp, -0x57F8
    move       $fp, $sp
    jal        psyq_malloc_InitHeap
     addi      $a0, $a0, 0x4
    lui        $ra, 0x8009
    lw         $ra, -0x53DC($ra)
    nop
    jal        main
     nop
    break      0, 1
.size start, . - start

dlabel dword_80011A48
    .word 0x00200000
dlabel dword_80011A4C
    .word 0x00200000
    .word 0x00200000
    .word 0x00200000
