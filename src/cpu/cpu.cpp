#include <cpu/cpu.h>

CPU::CPU(GTE* gte) : gte(gte) {
	cop0.prid = 0x00000002;

	register_opcodes();
}

CPU::~CPU() {}