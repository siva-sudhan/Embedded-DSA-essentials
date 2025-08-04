/*
 * Problem: Compact Sensor Event Tracker
 * ------------------------------------
 * You're developing firmware for a battery-powered IoT device that collects
 * and logs sensor events. There are 8 types of events, each represented by an
 * integer between 0 and 7.
 *
 * To save memory and reduce write operations to flash, the system stores
 * multiple events in a compact format, using a single byte (8 bits) to store
 * up to 4 events (2 bits per event).
 *
 * Design a compact event queue that:
 *   - Can hold up to N sensor events, where N is divisible by 4.
 *   - Uses the minimum number of bytes, storing 4 events per byte.
 *   - Supports the following operations:
 *       void insert_event(uint8_t *buffer, int index, uint8_t event);
 *       uint8_t get_event(uint8_t *buffer, int index);
 *
 * Constraints:
 *   - No dynamic memory allocation.
 *   - Bitwise operations only (no memcpy, bitfields, etc.).
 *   - Ensure byte writes do not affect neighboring events.
 *
 * Example:
 *   uint8_t buffer[2]; // 8 events = 2 bytes
 *   insert_event(buffer, 0, 1);
 *   insert_event(buffer, 1, 2);
 *   insert_event(buffer, 2, 3);
 *   insert_event(buffer, 3, 0);
 *   insert_event(buffer, 4, 2);
 *   insert_event(buffer, 5, 1);
 *   printf("%d", get_event(buffer, 2)); // Should return 3
 *
 * Follow-Up:
 *   - Extend to support up to 16 event types using 4 bits (bitmask-aware logic).
 *   - Add wear-leveling support: when a byte is modified more than 10 times,
 *     trigger a callback to write it to a different memory location (simulate
 *     this with a counter).
 *
 * Hint:
 *   - Each event is 2 bits. For index i, it lies in byte i/4, and within that
 *     byte its 2 bits are at shift: 6 - 2*(i%4).
 */
