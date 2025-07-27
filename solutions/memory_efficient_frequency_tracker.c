#include <stdint.h>
#include <stddef.h>

#define FREQ_TABLE_BYTES 128 /* 256 entries packed two per byte */

/* Track frequencies of 8-bit readings with packed 4-bit counters */
void track_frequencies(uint8_t readings[], int size, uint8_t freq_table[256])
{
    /* initialize only the needed bytes */
    for (int i = 0; i < FREQ_TABLE_BYTES; ++i)
        freq_table[i] = 0;

    for (int i = 0; i < size; ++i) {
        uint8_t val = readings[i];
        int byte_index = val >> 1;      /* val / 2 */
        int shift = (val & 1) << 2;     /* lower or upper nibble */

        uint8_t count = (freq_table[byte_index] >> shift) & 0x0F;
        if (count < 15) {
            count++;
            freq_table[byte_index] &= ~(0x0F << shift);
            freq_table[byte_index] |= (count & 0x0F) << shift;
        }
    }
}

/* Retrieve frequency for a particular value */
uint8_t get_frequency(uint8_t freq_table[], uint8_t value)
{
    int byte_index = value >> 1;
    int shift = (value & 1) << 2;
    return (freq_table[byte_index] >> shift) & 0x0F;
}
