#include <limits.h>

#define MAX_N 1024

typedef struct {
    int buffer[MAX_N];
    int head;
    int size;
    int window;
} CircularSensorBuffer;

/* Initialize the circular buffer */
void init_buffer(CircularSensorBuffer *cb, int size, int window)
{
    if (size > MAX_N)
        size = MAX_N;
    if (window > size)
        window = size;

    cb->size = size;
    cb->window = window;
    cb->head = 0;

    for (int i = 0; i < size; ++i) {
        cb->buffer[i] = INT_MIN; /* mark as empty */
    }
}

/* Insert a reading and overwrite oldest when full */
void insert_reading(CircularSensorBuffer *cb, int value)
{
    cb->buffer[cb->head] = value;
    cb->head = (cb->head + 1) % cb->size;
}

/* Return maximum among the last 'window' readings */
int get_max_last_k(CircularSensorBuffer *cb)
{
    int max_val = INT_MIN;
    for (int i = 0; i < cb->window; ++i) {
        int idx = (cb->head - 1 - i + cb->size) % cb->size;
        if (cb->buffer[idx] > max_val) {
            max_val = cb->buffer[idx];
        }
    }
    return max_val;
}
