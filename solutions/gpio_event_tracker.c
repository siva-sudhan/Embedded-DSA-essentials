#include <stdint.h>
#include <stdbool.h>

/* 8 words x 32 bits = 256 bits -> 32 bytes */
static uint32_t pin_bits[8];

void set_pin_active(int pin_id)
{
    if (pin_id < 0 || pin_id >= 256)
        return;
    pin_bits[pin_id >> 5] |= (1u << (pin_id & 31));
}

void set_pin_inactive(int pin_id)
{
    if (pin_id < 0 || pin_id >= 256)
        return;
    pin_bits[pin_id >> 5] &= ~(1u << (pin_id & 31));
}

bool is_pin_active(int pin_id)
{
    if (pin_id < 0 || pin_id >= 256)
        return false;
    return (pin_bits[pin_id >> 5] >> (pin_id & 31)) & 1u;
}

int count_active_pins(void)
{
    int total = 0;
    for (int i = 0; i < 8; ++i)
        total += __builtin_popcount(pin_bits[i]);
    return total;
}

int get_first_active_pin(void)
{
    for (int i = 0; i < 8; ++i) {
        uint32_t word = pin_bits[i];
        if (word != 0) {
            return (i << 5) + __builtin_ctz(word);
        }
    }
    return -1;
}
