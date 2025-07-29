#include <stdint.h>

typedef struct {
    uint8_t opcode;
    int frequency;
} OpcodeStat;

/* Return the opcode that occurs most frequently in the array */
OpcodeStat get_most_frequent_opcode(uint16_t instructions[], int n)
{
    uint16_t opcode_freq[256] = {0};

    for (int i = 0; i < n; ++i) {
        uint8_t opcode = (instructions[i] >> 8) & 0xFF;
        opcode_freq[opcode]++;
    }

    uint8_t best_opcode = 0;
    int best_freq = 0;
    for (int i = 0; i < 256; ++i) {
        if (opcode_freq[i] > best_freq) {
            best_freq = opcode_freq[i];
            best_opcode = (uint8_t)i;
        }
    }

    OpcodeStat stat;
    stat.opcode = best_opcode;
    stat.frequency = best_freq;
    return stat;
}
