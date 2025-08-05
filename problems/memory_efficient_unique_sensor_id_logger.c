/*
 * Problem: Memory-Efficient Unique Sensor ID Logger
 * -----------------------------------------------
 * In a memory constrained sensor node (4KB RAM), readings contain a
 * 32-bit sensor ID. Duplicate readings from the same sensor are common
 * due to noise or retransmission.
 *
 * Design a deduplicated logging system that:
 *
 *   - Stores only unique sensor IDs, keeping the order they first appear.
 *   - Checks if an ID has been logged in O(1) time.
 *   - Supports inserting new IDs and resetting the log.
 *
 * Requirements:
 *   bool insert_sensor(uint32_t sensor_id);
 *       - Returns true if the ID is new and stores it.
 *       - Returns false if the ID was already logged.
 *
 *   void reset_log();
 *       - Clears the memory for a new session.
 *
 * Constraints:
 *   - No more than 2KB total memory for storage and lookup.
 *   - Maximum of 512 unique IDs per session.
 *   - No dynamic memory allocation (malloc, etc.).
 *   - Target platform: bare-metal ARM Cortex-A.
 *
 * Bonus:
 *   uint32_t get_logged_ids(uint32_t *output_buf);
 *       - Dumps the stored unique IDs in insertion order into the
 *         provided buffer. Returns the number of IDs copied.
 *
 * Consider future extensions such as minimizing writes to flash if the
 * logger is made persistent.
 */
