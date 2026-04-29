#include "./include/interrupts.h"

void irq_enable(unsigned int irq_mask){
    IRQ_ENABLE1 = irq_mask;
}

void irq_disable(unsigned int irq_mask){
    IRQ_DISABLE1 = irq_mask;
}

int irq_is_pending(unsigned int irq_mask) {
    return (IRQ_PENDING1 & irq_mask) != 0;
}

