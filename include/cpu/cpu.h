#pragma once

#include <functional>
#include <stdint.h>
#include <unordered_map>

#include <cpu/cop0/cop0.h>
#include <cpu/gte/gte.h>
#include <util/util.h>

class CPU {
public:
	CPU(GTE* gte);
	~CPU() = default;

	u32 registers[32];

	u32 pc;
	u32 hi; u32 lo;

	std::unordered_map<u32, FUNCTION> primary, secondary;

	COP0 cop0;
	GTE* gte;

	void register_opcodes();
	void register_primary();
	void register_secondary();

	void op_special();
	void op_bcondz();
	void op_j();
	void op_jal();
	void op_beq();
	void op_bne();
	void op_blez();
	void op_bgtz();
	void op_addi();
	void op_addiu();
	void op_slti();
	void op_sltiu();
	void op_andi();
	void op_ori();
	void op_xori();
	void op_lui();
	void op_cop0();
	void op_cop1();
	void op_cop2();
	void op_cop3();
	void op_lb();
	void op_lh();
	void op_lwl();
	void op_lw();
	void op_lbu();
	void op_lhu();
	void op_lwr();
	void op_sb();
	void op_sh();
	void op_swl();
	void op_sw();
	void op_swr();
	void op_lwc0();
	void op_lwc1();
	void op_lwc2();
	void op_lwc3();
	void op_swc0();
	void op_swc1();
	void op_swc2();
	void op_swc3();

	void op_sll();
	void op_srl();
	void op_sra();
	void op_sllv();
	void op_srlv();
	void op_srav();
	void op_jr();
	void op_jalr();
	void op_syscall();
	void op_break();
	void op_mfhi();
	void op_mthi();
	void op_mflo();
	void op_mtlo();
	void op_mult();
	void op_multu();
	void op_div();
	void op_divu();
	void op_add();
	void op_addu();
	void op_sub();
	void op_subu();
	void op_and();
	void op_or();
	void op_xor();
	void op_nor();
	void op_slt();
	void op_sltu();
};