/*
 * Problem: Packed Peripheral Config Table
 * --------------------------------------
 * Your embedded system has 16 hardware peripherals (SPI, I2C, CAN, UART, ...).
 * Each peripheral stores its mode in a 3-bit field with the following meaning:
 *   000 -> Disabled
 *   001 -> Enabled
 *   010 -> Sleep
 *   011 -> Interrupt-Only
 *   100-111 -> Reserved for future use
 *
 * All peripheral modes are packed into a single 6-byte array:
 *   uint8_t config[6];
 *   // 16 peripherals * 3 bits = 48 bits = 6 bytes
 *
 * Implement the following functions:
 *   void set_peripheral_mode(uint8_t config[6], int index, uint8_t mode);
 *       - Store 'mode' for peripheral 'index' (0-15). Only the lower
 *         three bits of 'mode' are used.
 *
 *   uint8_t get_peripheral_mode(uint8_t config[6], int index);
 *       - Retrieve the mode for peripheral 'index'.
 *
 * Constraints:
 *   - No dynamic memory or structs; operate only on the 6-byte array.
 *   - Bit packing must be tight (3 bits per peripheral) and may span bytes.
 *   - Use bitwise operations to handle cross-byte reads and writes.
 */
