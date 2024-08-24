#ifndef ALU_H
#define ALU_H

#include "ThirtyTwoBitALU.h"

class ALU{
    public:
    static void ADD(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow);
    static void ADDU(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow);
    static void AND(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow);
    static void OR(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow);
    static void NOT(bool B[32],bool &zero,bool Result[32],bool &Overflow);
    static void NAND(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow);
    static void NOR(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow);
    static void SUB(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow);
    static void ZERO(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow);
    static void LESS(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow);
};

#endif
