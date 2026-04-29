#ifndef RTOS_H
#define RTOS_H

// Forward declaration of task function
typedef void (*task_func_t)(void);

void task_create(task_func_t func, int priority);
void rtos_start(void);

// Stub for delay (just a busy loop for now)
void task_delay(unsigned int ms);

#endif
