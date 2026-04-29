// ===============================
// AArch64 Exception Vector Table (EL2)
// Places EL2 entries first so VBAR_EL2 works correctly.
// ===============================

.section .vectors, "ax"
.align 11                       // must be 2KB aligned
.global exception_vectors

exception_vectors:
    // ---------------------------
    // EL2t (SP_EL0 when EL2 using SP_EL0)
    // ---------------------------
    b .                         // Synchronous (unused)
    b irq_handler               // IRQ
    b .                         // FIQ
    b .                         // SError

    // ---------------------------
    // EL2h (SP_EL2) -- we typically use this
    // ---------------------------
    b .                         // Synchronous
    b irq_handler               // IRQ entry point for EL2
    b .                         // FIQ
    b .                         // SError

    // ---------------------------
    // EL1t (SP_EL0)
    // ---------------------------
    b .                         // Synchronous
    b irq_handler               // IRQ
    b .                         // FIQ
    b .                         // SError

    // ---------------------------
    // EL1h (SP_EL1)
    // ---------------------------
    b .                         // Synchronous
    b irq_handler               // IRQ
    b .                         // FIQ
    b .                         // SError

    // ---------------------------
    // EL0_64 (from user EL0, 64-bit)
    // ---------------------------
    b .                         // Synchronous
    b irq_handler               // IRQ
    b .                         // FIQ
    b .                         // SError

    // ---------------------------
    // EL0_32 (from user EL0, 32-bit)
    // ---------------------------
    b .                         // Synchronous
    b irq_handler               // IRQ
    b .                         // FIQ
    b .                         // SError

