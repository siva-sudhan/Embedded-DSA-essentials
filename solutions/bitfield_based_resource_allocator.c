#include <stdint.h>
#include <stdbool.h>

/* Allocate the first available timer */
int allocate_timer(uint32_t *status_reg)
{
    for (int i = 0; i < 32; ++i) {
        if (((*status_reg >> i) & 1U) == 0) {
            *status_reg |= (1U << i);
            return i;
        }
    }
    return -1; /* all timers allocated */
}

/* Free a timer by index */
void free_timer(uint32_t *status_reg, int index)
{
    if (index >= 0 && index < 32) {
        *status_reg &= ~(1U << index);
    }
}

/* Check if a timer is allocated */
bool is_timer_allocated(uint32_t status_reg, int index)
{
    if (index < 0 || index >= 32)
        return false;
    return ((status_reg >> index) & 1U) != 0;
}
