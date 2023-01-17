#include <cpu/cpu.h>

void CPU::register_opcodes() {
	register_primary();
	register_secondary();
}

void CPU::register_primary() {
	primary[0x00] = std::bind(&CPU::op_special, this);
	primary[0x01] = std::bind(&CPU::op_bcondz, this);
	primary[0x02] = std::bind(&CPU::op_j, this);
	primary[0x03] = std::bind(&CPU::op_jal, this);
	primary[0x04] = std::bind(&CPU::op_beq, this);
	primary[0x05] = std::bind(&CPU::op_bne, this);
	primary[0x06] = std::bind(&CPU::op_blez, this);
	primary[0x07] = std::bind(&CPU::op_bgtz, this);
	primary[0x08] = std::bind(&CPU::op_addi, this);
	primary[0x09] = std::bind(&CPU::op_addiu, this);
	primary[0x0A] = std::bind(&CPU::op_slti, this);
	primary[0x0B] = std::bind(&CPU::op_sltiu, this);
	primary[0x0C] = std::bind(&CPU::op_andi, this);
	primary[0x0D] = std::bind(&CPU::op_ori, this);
	primary[0x0E] = std::bind(&CPU::op_xori, this);
	primary[0x0F] = std::bind(&CPU::op_lui, this);
	primary[0x10] = std::bind(&CPU::op_cop0, this);
	primary[0x11] = std::bind(&CPU::op_cop1, this);
	primary[0x12] = std::bind(&CPU::op_cop2, this);
	primary[0x13] = std::bind(&CPU::op_cop3, this);
	primary[0x20] = std::bind(&CPU::op_lb, this);
	primary[0x21] = std::bind(&CPU::op_lh, this);
	primary[0x22] = std::bind(&CPU::op_lwl, this);
	primary[0x23] = std::bind(&CPU::op_lw, this);
	primary[0x24] = std::bind(&CPU::op_lbu, this);
	primary[0x25] = std::bind(&CPU::op_lhu, this);
	primary[0x26] = std::bind(&CPU::op_lwr, this);
	primary[0x28] = std::bind(&CPU::op_sb, this);
	primary[0x29] = std::bind(&CPU::op_sh, this);
	primary[0x2A] = std::bind(&CPU::op_swl, this);
	primary[0x2B] = std::bind(&CPU::op_sw, this);
	primary[0x2E] = std::bind(&CPU::op_swr, this);
	primary[0x30] = std::bind(&CPU::op_lwc0, this);
	primary[0x31] = std::bind(&CPU::op_lwc1, this);
	primary[0x32] = std::bind(&CPU::op_lwc2, this);
	primary[0x33] = std::bind(&CPU::op_lwc3, this);
	primary[0x38] = std::bind(&CPU::op_swc0, this);
	primary[0x39] = std::bind(&CPU::op_swc1, this);
	primary[0x3A] = std::bind(&CPU::op_swc2, this);
	primary[0x3B] = std::bind(&CPU::op_swc3, this);
}

void CPU::register_secondary() {
	secondary[0x00] = std::bind(&CPU::op_sll, this);
	secondary[0x02] = std::bind(&CPU::op_srl, this);
	secondary[0x03] = std::bind(&CPU::op_sra, this);
	secondary[0x04] = std::bind(&CPU::op_sllv, this);
	secondary[0x06] = std::bind(&CPU::op_srlv, this);
	secondary[0x07] = std::bind(&CPU::op_srav, this);
	secondary[0x08] = std::bind(&CPU::op_jr, this);
	secondary[0x09] = std::bind(&CPU::op_jalr, this);
	secondary[0x0C] = std::bind(&CPU::op_syscall, this);
	secondary[0x0D] = std::bind(&CPU::op_break, this);
	secondary[0x10] = std::bind(&CPU::op_mfhi, this);
	secondary[0x11] = std::bind(&CPU::op_mthi, this);
	secondary[0x12] = std::bind(&CPU::op_mflo, this);
	secondary[0x13] = std::bind(&CPU::op_mtlo, this);
	secondary[0x18] = std::bind(&CPU::op_mult, this);
	secondary[0x19] = std::bind(&CPU::op_multu, this);
	secondary[0x1A] = std::bind(&CPU::op_div, this);
	secondary[0x1B] = std::bind(&CPU::op_divu, this);
	secondary[0x20] = std::bind(&CPU::op_add, this);
	secondary[0x21] = std::bind(&CPU::op_addu, this);
	secondary[0x22] = std::bind(&CPU::op_sub, this);
	secondary[0x23] = std::bind(&CPU::op_subu, this);
	secondary[0x24] = std::bind(&CPU::op_and, this);
	secondary[0x25] = std::bind(&CPU::op_or, this);
	secondary[0x26] = std::bind(&CPU::op_xor, this);
	secondary[0x27] = std::bind(&CPU::op_nor, this);
	secondary[0x2A] = std::bind(&CPU::op_slt, this);
	secondary[0x2B] = std::bind(&CPU::op_sltu, this);
}