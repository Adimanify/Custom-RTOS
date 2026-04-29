    .section .text.boot
    .globl _start

    .extern exception_vectors
    .extern _stack_top
    .extern __bss_start
    .extern __bss_end

_start:
    ldr x5, =_stack_top
    mov sp, x5

    ldr x5, =__bss_start
    ldr x6, =__bss_end

1:  cmp x5, x6
    b.hs 2f
    str xzr, [x5], #8
    b 1b

2:
    ldr x0, =exception_vectors
    msr VBAR_EL2, x0
    isb

    mrs x0, HCR_EL2
    orr x0, x0, #28      // set bits 4,3,2 (28 decimal)
    msr HCR_EL2, x0
    isb

    msr daifclr, #0xF
    isb

    bl kernel_main

halt:
    wfe
    b halt
