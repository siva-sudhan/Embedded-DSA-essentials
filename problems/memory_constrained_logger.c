/*
 * Problem: Memory-Constrained Logger System
 * -----------------------------------------
 * We need a logging module for a tiny embedded device with about 1 KB of RAM.
 * Each log message is a short ASCII string up to 64 characters. Messages are
 * inserted one at a time and duplicates must be ignored (only the first
 * occurrence is kept). Logs are stored in insertion order but when requested
 * should be returned in alphabetical order.
 *
 * Requirements:
 *   - Ignore duplicate messages.
 *   - Simulate a total RAM usage of roughly 1 KB for storage.
 *   - At most 100 unique log messages will be stored.
 *   - Implement the following functions:
 *       void insert_log(const char *log_msg);
 *       char **get_sorted_logs(int *num_logs);
 *         -> Returns a dynamically allocated array of log strings sorted
 *            alphabetically. The caller is responsible for freeing the
 *            returned strings and the array itself.
 *
 * A simple brute-force approach is acceptable for this problem. For
 * deduplication, a linear search of existing logs can be performed.
 * When get_sorted_logs() is called, use qsort to sort copies of the
 * stored strings.
 */
