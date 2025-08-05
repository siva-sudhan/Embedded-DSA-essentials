#include <stdint.h>
#include <stdbool.h>

#define MAX_IDS    512
#define TABLE_SIZE 512
#define EMPTY_SLOT 0xFFFFFFFFu

static uint32_t id_table[TABLE_SIZE];
static uint16_t order_index[MAX_IDS];
static uint16_t id_count = 0;

/* simple multiplicative hash, assumes TABLE_SIZE power of two */
static inline uint32_t hash32(uint32_t x)
{
    return (x * 2654435761u) & (TABLE_SIZE - 1);
}

bool insert_sensor(uint32_t sensor_id)
{
    uint32_t idx = hash32(sensor_id);
    for (uint32_t probe = 0; probe < TABLE_SIZE; ++probe) {
        uint32_t pos = (idx + probe) & (TABLE_SIZE - 1);
        uint32_t entry = id_table[pos];
        if (entry == sensor_id) {
            return false; /* already logged */
        }
        if (entry == EMPTY_SLOT) {
            if (id_count >= MAX_IDS)
                return false; /* table full */
            id_table[pos] = sensor_id;
            order_index[id_count++] = (uint16_t)pos;
            return true;
        }
    }
    return false; /* table full */
}

void reset_log(void)
{
    for (uint32_t i = 0; i < TABLE_SIZE; ++i)
        id_table[i] = EMPTY_SLOT;
    id_count = 0;
}

uint32_t get_logged_ids(uint32_t *output_buf)
{
    if (!output_buf)
        return 0;
    for (uint32_t i = 0; i < id_count; ++i)
        output_buf[i] = id_table[order_index[i]];
    return id_count;
}
