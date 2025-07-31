#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define POOL_SIZE 1024
#define MAX_LOGS 100
#define MAX_LOG_LENGTH 64

/* static memory pool for all log messages */
static char memory_pool[POOL_SIZE];
static uint16_t offsets[MAX_LOGS];
static uint8_t log_count = 0;
static uint16_t pool_used = 0;

/* duplicate of strdup for portability */
static char *dup_string(const char *s)
{
    size_t len = strlen(s);
    char *res = (char *)malloc(len + 1);
    if (res)
        memcpy(res, s, len + 1);
    return res;
}

/* Insert a new log message if it is unique and space allows */
void insert_log(const char *log_msg)
{
    if (!log_msg)
        return;

    /* Check for duplicates */
    for (uint8_t i = 0; i < log_count; ++i) {
        const char *stored = memory_pool + offsets[i];
        if (strncmp(stored, log_msg, MAX_LOG_LENGTH) == 0) {
            return; /* duplicate */
        }
    }

    if (log_count >= MAX_LOGS)
        return; /* capacity reached */

    size_t len = 0;
    while (len < MAX_LOG_LENGTH && log_msg[len] != '\0')
        ++len;
    if (pool_used + len + 1 > POOL_SIZE)
        return; /* not enough simulated RAM */

    memcpy(memory_pool + pool_used, log_msg, len);
    memory_pool[pool_used + len] = '\0';
    offsets[log_count++] = pool_used;
    pool_used += len + 1;
}

static int cmp_strings(const void *a, const void *b)
{
    const char *sa = *(const char * const *)a;
    const char *sb = *(const char * const *)b;
    return strcmp(sa, sb);
}

/* Retrieve logs sorted alphabetically. Caller frees the result. */
char **get_sorted_logs(int *num_logs)
{
    if (num_logs)
        *num_logs = log_count;
    if (log_count == 0)
        return NULL;

    char **arr = (char **)malloc(log_count * sizeof(char *));
    if (!arr)
        return NULL;

    for (uint8_t i = 0; i < log_count; ++i) {
        const char *msg = memory_pool + offsets[i];
        arr[i] = dup_string(msg);
        if (!arr[i]) {
            /* cleanup on allocation failure */
            for (uint8_t j = 0; j < i; ++j)
                free(arr[j]);
            free(arr);
            return NULL;
        }
    }

    qsort(arr, log_count, sizeof(char *), cmp_strings);
    return arr;
}
