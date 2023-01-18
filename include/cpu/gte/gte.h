#pragma once

#include <cpu/cpu.h>

#include <glm/mat3x3.hpp>

class GTE {
public:
	union RGBC {
		struct {
			u8 r, g, b, c;
		};
	};

	union VECTOR2S16 {
		struct {
			s16 x, y;
		};

		glm::i16vec2 vector;
	};

	union VECTOR3S16 {
		struct {
			s16 x, y, z;
		};

		glm::i16vec3 vector;
	};

	GTE(CPU* cpu);
	~GTE() = default;


	// MARK: Properties
	std::unordered_map<u32, FUNCTION> opcodes;

	CPU* cpu;


	// MARK: GTE Data Registers
	VECTOR3S16 vxy0, vz0;
	VECTOR3S16 vxy1, vz1;
	VECTOR3S16 vxy2, vz2;
	RGBC rgbc;
	u16 otz;
	s16 ir0, ir1, ir2, ir3;
	VECTOR2S16 sxy0, sxy1, sxy2;
	u16 sz0, sz1, sz2, sz3;
	RGBC rgb0, rgb1, rgb2;
	// res1 - prohibited (u8 res);



	// MARK: Functions
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