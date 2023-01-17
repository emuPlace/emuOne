#include <cpu/gte/gte.h>

void GTE::register_opcodes() {
	opcodes[0x01] = std::bind(&GTE::op_rtps, this);
	opcodes[0x06] = std::bind(&GTE::op_nclip, this);
	opcodes[0x0C] = std::bind(&GTE::op_op, this);
	opcodes[0x10] = std::bind(&GTE::op_dpcs, this);
	opcodes[0x11] = std::bind(&GTE::op_intpl, this);
	opcodes[0x12] = std::bind(&GTE::op_mvmva, this);
	opcodes[0x13] = std::bind(&GTE::op_ncds, this);
	opcodes[0x14] = std::bind(&GTE::op_cdp, this);
	opcodes[0x16] = std::bind(&GTE::op_ncdt, this);
	opcodes[0x1B] = std::bind(&GTE::op_nccs, this);
	opcodes[0x1C] = std::bind(&GTE::op_cc, this);
	opcodes[0x1E] = std::bind(&GTE::op_ncs, this);
	opcodes[0x20] = std::bind(&GTE::op_nct, this);
	opcodes[0x28] = std::bind(&GTE::op_sqr, this);
	opcodes[0x29] = std::bind(&GTE::op_dcpl, this);
	opcodes[0x2A] = std::bind(&GTE::op_dpct, this);
	opcodes[0x2D] = std::bind(&GTE::op_avsz3, this);
	opcodes[0x2E] = std::bind(&GTE::op_avsz4, this);
	opcodes[0x30] = std::bind(&GTE::op_rtpt, this);
	opcodes[0x3D] = std::bind(&GTE::op_gpf, this);
	opcodes[0x3E] = std::bind(&GTE::op_gpl, this);
	opcodes[0x3F] = std::bind(&GTE::op_ncct, this);
}