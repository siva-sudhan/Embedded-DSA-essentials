/*
 * Problem: Compact Instruction Decoder
 * -----------------------------------
 * You're working on a custom embedded processor emulator that executes
 * 16-bit compact instructions. Each instruction contains two 8-bit fields:
 *   Bits 15-8 : Opcode
 *   Bits 7-0  : Operand
 *
 * You are given a stream of uint16_t instructions stored in an array.
 * Implement logic to:
 *   - Parse each instruction into opcode and operand
 *   - Track how many times each opcode was used
 *   - Return the most frequent opcode along with its frequency
 *
 * Types:
 *   typedef struct {
 *       uint8_t opcode;
 *       int frequency;
 *   } OpcodeStat;
 *
 * Function to implement:
 *   OpcodeStat get_most_frequent_opcode(uint16_t instructions[], int n);
 *
 * Constraints:
 *   - Instruction stream size: n <= 1000
 *   - No dynamic memory allocation
 *   - Opcodes are in the range 0-255
 *
 * Example:
 *   uint16_t instructions[] = {
 *       0x1201, // opcode 0x12
 *       0x340F, // opcode 0x34
 *       0x1204, // opcode 0x12
 *   };
 *   OpcodeStat stat = get_most_frequent_opcode(instructions, 3);
 *   // stat.opcode -> 0x12
 *   // stat.frequency -> 2
 */
