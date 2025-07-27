/*
 * Problem: Packed GPIO Pin Configuration Table
 * -------------------------------------------
 * A 32-pin GPIO controller stores each pin's mode in two bits:
 *   00 = Input, 01 = Output, 10 = Alternate Function, 11 = Analog.
 * Use a single 64-bit register to hold the configuration for all pins.
 *
 * Implement the following functions:
 *   void set_pin_config(uint64_t *reg, int pin, uint8_t config);
 *       - Set the configuration of 'pin' (0-31) to the value 'config' (0-3).
 *   uint8_t get_pin_config(uint64_t reg, int pin);
 *       - Return the current configuration of 'pin'.
 *
 * Bit Layout:
 *   Pin 0 -> bits 1:0
 *   Pin 1 -> bits 3:2
 *   ...
 *   Pin n -> bits (2*n+1):(2*n)
 *
 * Requirements:
 *   - Only use the provided 64-bit register for storage.
 *   - Clear the target bits before writing a new config.
 *   - To read, shift right by 2*pin and mask with 0x3.
 */

