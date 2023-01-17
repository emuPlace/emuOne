#pragma once

class COP0 {
public:
	union CAUSE {
		u32 value;

		enum EXCEPTION_CODE : u32 {
			INT = 0x00,
			MOD = 0x01,
			TLBL = 0x02,
			TLBS = 0x03,
			AdEL = 0x04,
			AdES = 0x05,
			IBE = 0x06,
			DBE = 0x07,
			Syscall = 0x08,
			BP = 0x09,
			RI = 0x0A,
			CpU = 0x0B,
			Ov = 0x0C
		};

		struct {
			EXCEPTION_CODE excode : 5;
			u32 ip : 8;
			u32 ce : 2;
			u32 bd : 1;
		};
	};

	union STATUS {
		u32 value;

		struct {
			u32 iec : 1;
			u32 kuc : 1;
			u32 iep : 1;
			u32 kup : 1;
			u32 ieo : 1;
			u32 kuo : 1;
			u32 im : 8;
			u32 isc : 1;
			u32 swc : 1;
			u32 pz : 1;
			u32 cm : 1;
			u32 pe : 1;
			u32 ts : 1;
			u32 bev : 1;
			u32 re : 1;
			u32 cu0 : 1;
			u32 cu1 : 1;
			u32 cu2 : 1;
			u32 cu3 : 1;
		};
	};

	struct {
		u32 bpc;
		u32 bda;
		u32 jumpdest;
		u32 dcic;
		u32 badvaddr;
		u32 bdam;
		u32 bpcm;
		STATUS sr;
		CAUSE cause;
		u32 epc;
		u32 prid;
	};
};