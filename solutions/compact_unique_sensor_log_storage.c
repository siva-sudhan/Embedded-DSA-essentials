#include <stdint.h>
#include <stdio.h>

/* Store unique sensor readings in a 64-bit log */
void store_sensor_readings(int readings[], int size, uint64_t *log)
{
    uint64_t result = 0;
    for (int i = 0; i < size; ++i) {
        int r = readings[i];
        if (r >= 0 && r < 64) {
            result |= (1ULL << r);
        }
    }
    *log = result;
}

/* Print stored readings in ascending order */
void print_logged_readings(uint64_t log)
{
    for (int i = 0; i < 64; ++i) {
        if ((log >> i) & 1ULL) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
