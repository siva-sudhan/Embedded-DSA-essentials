/*
 * Problem: GPIO Event Tracker (Memory-Efficient Bitset)
 * -----------------------------------------------------
 * You're designing a bitset-based event tracker for a microcontroller that
 * monitors the state of 256 GPIO pins. Each pin can be either ACTIVE (1) or
 * INACTIVE (0).
 *
 * Use only 32 bytes (256 bits) to store all pin statuses and implement the
 * following operations using bit manipulation:
 *
 *   void set_pin_active(int pin_id);    // mark pin as active
 *   void set_pin_inactive(int pin_id);  // mark pin as inactive
 *   bool is_pin_active(int pin_id);     // check if a pin is active
 *   int  count_active_pins();           // return the number of active pins
 *
 * Constraints:
 *   - pin_id is in the range [0, 255]
 *   - No dynamic memory allocation
 *   - All operations must be implemented with bit operations
 *
 * Optional Extension:
 *   int get_first_active_pin();
 *     -> Return the lowest numbered active pin, or -1 if none. This should be
 *        implemented without iterating over all 256 pins one by one.
 */
