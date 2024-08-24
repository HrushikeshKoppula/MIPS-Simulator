#ifndef REGISTERS_H
#define REGISTERS_H

#include "Register.h"
#include <map>

class REGISTERS{
public:
    static const REGISTER dollar_0;
    static REGISTER dollar_at;
    static REGISTER dollar_v0;
    static REGISTER dollar_v1;
    static REGISTER dollar_a0;
    static REGISTER dollar_a1;
    static REGISTER dollar_a2;
    static REGISTER dollar_a3;
    static REGISTER dollar_t0;
    static REGISTER dollar_t1;
    static REGISTER dollar_t2;
    static REGISTER dollar_t3;
    static REGISTER dollar_t4;
    static REGISTER dollar_t5;
    static REGISTER dollar_t6;
    static REGISTER dollar_t7;
    static REGISTER dollar_s0;
    static REGISTER dollar_s1;
    static REGISTER dollar_s2;
    static REGISTER dollar_s3;
    static REGISTER dollar_s4;
    static REGISTER dollar_s5;
    static REGISTER dollar_s6;
    static REGISTER dollar_s7;
    static REGISTER dollar_t8;
    static REGISTER dollar_t9;
    static REGISTER dollar_k0;
    static REGISTER dollar_k1;
    static REGISTER dollar_gp;
    static REGISTER dollar_sp;
    static REGISTER dollar_fp;
    static REGISTER dollar_ra;
    static std::map<int, REGISTER> Registers;
    REGISTERS();
};

#endif 
