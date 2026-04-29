#include "rtos.h"
#include "gpio.h"

static task_func_t first_task = 0;

void task_create(task_func_t func, int priority) {
    // For now we ignore priority and just store one task
    first_task = func;
}

void rtos_start(void) {
    if (first_task) {
        first_task();  // just jump into the task function
    }

    // If no task defined, loop forever
    while (1);
}

