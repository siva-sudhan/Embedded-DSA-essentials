#include <stdint.h>

#define EVENT_BITS_2 2
#define EVENT_MASK_2 0x3

void insert_event(uint8_t *buffer, int index, uint8_t event)
{
    if (!buffer || index < 0 || event >= (1u << EVENT_BITS_2))
        return;

    int byte_index = index >> 2;                       /* index / 4 */
    int shift = (3 - (index & 3)) * EVENT_BITS_2;      /* 6 - 2*(index % 4) */
    buffer[byte_index] &= ~(EVENT_MASK_2 << shift);    /* clear existing bits */
    buffer[byte_index] |= (event & EVENT_MASK_2) << shift; /* set new event */
}

uint8_t get_event(uint8_t *buffer, int index)
{
    if (!buffer || index < 0)
        return 0;

    int byte_index = index >> 2;
    int shift = (3 - (index & 3)) * EVENT_BITS_2;
    return (buffer[byte_index] >> shift) & EVENT_MASK_2;
}

#define EVENT_BITS_4 4
#define EVENT_MASK_4 0xF
#define MAX_MODIFICATIONS 10

void insert_event16(uint8_t *buffer, int index, uint8_t event)
{
    if (!buffer || index < 0 || event >= (1u << EVENT_BITS_4))
        return;

    int byte_index = index >> 1;                       /* index / 2 */
    int shift = (1 - (index & 1)) * EVENT_BITS_4;      /* 4 or 0 */
    buffer[byte_index] &= ~(EVENT_MASK_4 << shift);
    buffer[byte_index] |= (event & EVENT_MASK_4) << shift;
}

uint8_t get_event16(uint8_t *buffer, int index)
{
    if (!buffer || index < 0)
        return 0;

    int byte_index = index >> 1;
    int shift = (1 - (index & 1)) * EVENT_BITS_4;
    return (buffer[byte_index] >> shift) & EVENT_MASK_4;
}

void insert_event16_wl(uint8_t *buffer,
                       uint8_t *mod_counts,
                       int index,
                       uint8_t event,
                       void (*wear_callback)(int byte_index))
{
    if (!buffer || !mod_counts || index < 0 || event >= (1u << EVENT_BITS_4))
        return;

    int byte_index = index >> 1;
    int shift = (1 - (index & 1)) * EVENT_BITS_4;
    buffer[byte_index] &= ~(EVENT_MASK_4 << shift);
    buffer[byte_index] |= (event & EVENT_MASK_4) << shift;

    if (++mod_counts[byte_index] > MAX_MODIFICATIONS) {
        if (wear_callback)
            wear_callback(byte_index);
        mod_counts[byte_index] = 0;
    }
}
