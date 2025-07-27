#include <stdint.h>

/* Set the configuration of a single GPIO pin */
void set_pin_config(uint64_t *reg, int pin, uint8_t config)
{
    if (pin < 0 || pin > 31)
        return;

    uint64_t mask = 0x3ULL << (pin * 2);
    *reg &= ~mask;
    *reg |= ((uint64_t)config & 0x3ULL) << (pin * 2);
}

/* Retrieve the configuration of a single GPIO pin */
uint8_t get_pin_config(uint64_t reg, int pin)
{
    if (pin < 0 || pin > 31)
        return 0;
    return (reg >> (pin * 2)) & 0x3ULL;
}

