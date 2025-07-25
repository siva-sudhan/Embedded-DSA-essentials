/*
 * Problem: Compact Unique Sensor Log Storage
 * ------------------------------------------
 * A sensor system outputs integer readings in the range [0, 63].
 * We only have a single 64‑bit memory location to store these readings.
 * The goal is to store each unique reading exactly once in sorted order
 * using bit manipulation.
 *
 * Implement the following functions:
 *   void store_sensor_readings(int readings[], int size, uint64_t *log);
 *       - Deduplicates the input readings and records the presence of each
 *         value in the 64‑bit log.
 *   void print_logged_readings(uint64_t log);
 *       - Prints the stored readings in ascending order.
 *
 * Constraints:
 *   - All readings are between 0 and 63 (inclusive).
 *   - No dynamic memory usage.
 *   - Operate directly on the provided 64‑bit variable.
 */

