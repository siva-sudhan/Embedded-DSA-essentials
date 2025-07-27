/*
 * Problem: Circular Buffer with Windowed Max
 * -----------------------------------------
 * Implement a fixed-size circular buffer for sensor readings.
 * After each insertion, return the maximum value among the last K readings.
 * No dynamic memory is allowed; use only preallocated static arrays.
 *
 * Types and Functions:
 *   #define MAX_N 1024
 *   typedef struct {
 *       int buffer[MAX_N];
 *       int head;      // index for next insert
 *       int size;      // total buffer capacity (<= MAX_N)
 *       int window;    // K - number of last readings to consider (<= size)
 *   } CircularSensorBuffer;
 *
 *   void init_buffer(CircularSensorBuffer *cb, int size, int window);
 *       - Initialize the circular buffer with given size and window.
 *   void insert_reading(CircularSensorBuffer *cb, int value);
 *       - Insert a reading, overwriting the oldest when full.
 *   int get_max_last_k(CircularSensorBuffer *cb);
 *       - Return the maximum value among the most recent 'window' readings.
 *
 * Requirements:
 *   - Circular insertion using (head + 1) % size.
 *   - get_max_last_k must run in O(K) time or better.
 *   - No dynamic memory allocation.
 *
 * Optional Challenge:
 *   Implement get_max_last_k in amortized O(1) using a monotonic deque.
 */
