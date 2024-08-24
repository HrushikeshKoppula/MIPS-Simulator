#include "Registers.h"

const REGISTER REGISTERS::dollar_0;
REGISTER REGISTERS::dollar_at;
REGISTER REGISTERS::dollar_v0;
REGISTER REGISTERS::dollar_v1;
REGISTER REGISTERS::dollar_a0;
REGISTER REGISTERS::dollar_a1;
REGISTER REGISTERS::dollar_a2;
REGISTER REGISTERS::dollar_a3;
REGISTER REGISTERS::dollar_t0;
REGISTER REGISTERS::dollar_t1;
REGISTER REGISTERS::dollar_t2;
REGISTER REGISTERS::dollar_t3;
REGISTER REGISTERS::dollar_t4;
REGISTER REGISTERS::dollar_t5;
REGISTER REGISTERS::dollar_t6;
REGISTER REGISTERS::dollar_t7;
REGISTER REGISTERS::dollar_s0;
REGISTER REGISTERS::dollar_s1;
REGISTER REGISTERS::dollar_s2;
REGISTER REGISTERS::dollar_s3;
REGISTER REGISTERS::dollar_s4;
REGISTER REGISTERS::dollar_s5;
REGISTER REGISTERS::dollar_s6;
REGISTER REGISTERS::dollar_s7;
REGISTER REGISTERS::dollar_t8;
REGISTER REGISTERS::dollar_t9;
REGISTER REGISTERS::dollar_k0;
REGISTER REGISTERS::dollar_k1;
REGISTER REGISTERS::dollar_gp;
REGISTER REGISTERS::dollar_sp;
REGISTER REGISTERS::dollar_fp;
REGISTER REGISTERS::dollar_ra;
std::map<int, REGISTER> REGISTERS::Registers;
static bool initialized = false;

REGISTERS::REGISTERS() {
    if (!initialized) {
        Registers[0] = dollar_0;
        Registers[1] = dollar_at;
        Registers[2] = dollar_v0;
        Registers[3] = dollar_v1;
        Registers[4] = dollar_a0;
        Registers[5] = dollar_a1;
        Registers[6] = dollar_a2;
        Registers[7] = dollar_a3;
        Registers[8] = dollar_t0;
        Registers[9] = dollar_t1;
        Registers[10] = dollar_t2;
        Registers[11] = dollar_t3;
        Registers[12] = dollar_t4;
        Registers[13] = dollar_t5;
        Registers[14] = dollar_t6;
        Registers[15] = dollar_t7;
        Registers[16] = dollar_s0;
        Registers[17] = dollar_s1;
        Registers[18] = dollar_s2;
        Registers[19] = dollar_s3;
        Registers[20] = dollar_s4;
        Registers[21] = dollar_s5;
        Registers[22] = dollar_s6;
        Registers[23] = dollar_s7;
        Registers[24] = dollar_t8;
        Registers[25] = dollar_t9;
        Registers[26] = dollar_k0;
        Registers[27] = dollar_k1;
        Registers[28] = dollar_gp;
        Registers[29] = dollar_sp;
        Registers[30] = dollar_fp;
        Registers[31] = dollar_ra;
        initialized = true;
    }
}
