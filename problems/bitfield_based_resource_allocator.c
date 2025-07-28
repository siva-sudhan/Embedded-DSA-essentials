/*
 * Problem: Bitfield-Based Resource Allocator
 * -----------------------------------------
 * You're designing firmware for a real-time operating system that manages
 * 32 hardware timers. Each timer is represented by a single bit in a
 * 32-bit register:
 *   0 -> free
 *   1 -> allocated
 *
 * Implement logic to:
 *   - Allocate the first available timer
 *   - Free a timer by index
 *   - Check if a timer is in use
 *
 * Required functions:
 *   int allocate_timer(uint32_t *status_reg);
 *       Returns the index of the allocated timer (0-31) or -1 if full.
 *
 *   void free_timer(uint32_t *status_reg, int index);
 *       Clears the bit corresponding to the timer.
 *
 *   bool is_timer_allocated(uint32_t status_reg, int index);
 *       Returns true if the timer bit is set.
 *
 * Constraints:
 *   - Only use bitwise operations
 *   - Allocation must scan from LSB (index 0) to MSB (index 31)
 *   - If all timers are allocated, allocate_timer() returns -1
 *   - free_timer() clears the corresponding bit
 *   - is_timer_allocated() checks if the bit at index is set
 */
