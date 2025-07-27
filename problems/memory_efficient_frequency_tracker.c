/*
 * Problem: Memory-Efficient Frequency Tracker for 8-bit Values
 * -----------------------------------------------------------
 * We need to count how many times each 8-bit reading (0-255) occurs
 * using no more than 512 bytes for the frequency table. Each count can
 * be at most 15, so we pack two 4-bit counters into one byte.
 *
 * Implement:
 *   void track_frequencies(uint8_t readings[], int size,
 *                          uint8_t freq_table[256]);
 *     - `freq_table` stores counts for all 256 possible values, with
 *       two entries packed per byte. Only the first 128 bytes of the
 *       array are required.
 *     - Clamp each counter at 15 when incrementing.
 *
 * Optional Helper:
 *   uint8_t get_frequency(uint8_t freq_table[], uint8_t value);
 *     - Returns the stored frequency for the given value.
 */
