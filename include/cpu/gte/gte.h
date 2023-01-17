#pragma once

#include <cpu/cpu.h>

class GTE {
public:
	GTE(CPU* cpu);
	~GTE() = default;

	std::unordered_map<u32, Function> opcodes;

	CPU* cpu;

	void register_opcodes();

	void op_rtps();
	void op_nclip();
	void op_op();
	void op_dpcs();
	void op_intpl();
	void op_mvmva();
	void op_ncds();
	void op_cdp();
	void op_ncdt();
	void op_nccs();
	void op_cc();
	void op_ncs();
	void op_nct();
	void op_sqr();
	void op_dcpl();
	void op_dpct();
	void op_avsz3();
	void op_avsz4();
	void op_rtpt();
	void op_gpf();
	void op_gpl();
	void op_ncct();
};