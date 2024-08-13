#ifndef REGISTERS_H
#define REGISTERS_H

#include "Register.h"

class REGISTERS {
public:
    const REGISTER dollar_0;
    REGISTER dollar_at;
    REGISTER dollar_v0;
    REGISTER dollar_v1;
    REGISTER dollar_a0;
    REGISTER dollar_a1;
    REGISTER dollar_a2;
    REGISTER dollar_a3;
    REGISTER dollar_t0;
    REGISTER dollar_t1;
    REGISTER dollar_t2;
    REGISTER dollar_t3;
    REGISTER dollar_t4;
    REGISTER dollar_t5;
    REGISTER dollar_t6;
    REGISTER dollar_t7;
    REGISTER dollar_s0;
    REGISTER dollar_s1;
    REGISTER dollar_s2;
    REGISTER dollar_s3;
    REGISTER dollar_s4;
    REGISTER dollar_s5;
    REGISTER dollar_s6;
    REGISTER dollar_s7;
    REGISTER dollar_t8;
    REGISTER dollar_t9;
    REGISTER dollar_k0;
    REGISTER dollar_k1;
    REGISTER dollar_gp;
    REGISTER dollar_sp;
    REGISTER dollar_fp;
    REGISTER dollar_ra;

    // Constructor to initialize all the registers
    REGISTERS();
};

#endif // REGISTERS_H
