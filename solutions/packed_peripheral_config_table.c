#include <stdint.h>

/* Set the mode for a given peripheral */
void set_peripheral_mode(uint8_t config[6], int index, uint8_t mode)
{
    if (index < 0 || index >= 16)
        return;

    uint64_t reg = 0;
    for (int i = 0; i < 6; ++i)
        reg |= ((uint64_t)config[i]) << (8 * i);

    uint64_t shift = (uint64_t)(index * 3);
    uint64_t mask = 0x7ULL << shift;

    reg &= ~mask;
    reg |= ((uint64_t)mode & 0x7ULL) << shift;

    for (int i = 0; i < 6; ++i)
        config[i] = (reg >> (8 * i)) & 0xFF;
}

/* Retrieve the mode for a given peripheral */
uint8_t get_peripheral_mode(uint8_t config[6], int index)
{
    if (index < 0 || index >= 16)
        return 0;

    uint64_t reg = 0;
    for (int i = 0; i < 6; ++i)
        reg |= ((uint64_t)config[i]) << (8 * i);

    return (reg >> (index * 3)) & 0x7ULL;
}
