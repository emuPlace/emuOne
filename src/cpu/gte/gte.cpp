#include <cpu/gte/gte.h>

GTE::GTE(CPU* cpu) : cpu(cpu) {
	register_opcodes();
}

GTE::~GTE() {}