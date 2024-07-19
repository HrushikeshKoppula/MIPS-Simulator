#include "ALU.h"

void ALU::AND(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,false,0,zero,Result,Overflow);
}
void ALU::OR(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,false,1,zero,Result,Overflow);
}
void ALU::ADD(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,false,2,zero,Result,Overflow);
}
void ALU::NOT(bool B[32],bool &zero,bool Result[32],bool &Overflow){
    bool A[32];
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,true,1,zero,Result,Overflow);
}
void ALU::NAND(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,true,0,zero,Result,Overflow);
}
void ALU::NOR(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,true,1,zero,Result,Overflow);
}
void ALU::SUB(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,true,true,2,zero,Result,Overflow);
}
void ALU::ZERO(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,true,true,2,zero,Result,Overflow);
}
void ALU::LESS(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,true,true,2,zero,Result,Overflow);
    zero=(Result[0]==1);
}