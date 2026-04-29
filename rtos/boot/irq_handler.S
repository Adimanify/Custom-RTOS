.section .text
.global irq_handler
.align 4

irq_handler:
    // Reserve 64 bytes and store x0-x7
    sub sp, sp, #64
    stp x0, x1, [sp, #0]
    stp x2, x3, [sp, #16]
    stp x4, x5, [sp, #32]
    stp x6, x7, [sp, #48]

    bl c_irq_handler

    // Restore x0-x7 and release stack
    ldp x0, x1, [sp, #0]
    ldp x2, x3, [sp, #16]
    ldp x4, x5, [sp, #32]
    ldp x6, x7, [sp, #48]
    add sp, sp, #64

    eret
