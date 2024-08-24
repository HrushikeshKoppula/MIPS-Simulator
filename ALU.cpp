#include "ALU.h"

void ALU::ADD(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,false,2,Result);
    // Overflow Check
    if((A[0]==B[0])&&(A[0]!=Result[0])){
        Overflow=true;
        for(int i=0;i<32;i++)   Result[i]=0; // so register not changed if overflow
    }
    // zero check
    zero=false;
    for(int i=0;i<32;i++){
        zero=LogicGates::OR(zero,Result[i]);
    }
    zero=LogicGates::NOT(zero);
}
void ALU::ADDU(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,false,2,Result);
    // zero check
    zero=false;
    for(int i=0;i<32;i++){
        zero=LogicGates::OR(zero,Result[i]);
    }
    zero=LogicGates::NOT(zero);
}
void ALU::SUB(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,true,true,2,Result);
    // Overflow Check
    if((A[0]!=B[0])&&(A[0]==Result[0])){
        Overflow=true;
        for(int i=0;i<32;i++)   Result[i]=0; // so register not changed if overflow
    }
    // zero check
    zero=false;
    for(int i=0;i<32;i++){
        zero=LogicGates::OR(zero,Result[i]);
    }
    zero=LogicGates::NOT(zero);
}
void ALU::SUBU(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,true,true,2,Result);
    // zero check
    zero=false;
    for(int i=0;i<32;i++){
        zero=LogicGates::OR(zero,Result[i]);
    }
    zero=LogicGates::NOT(zero);
}
void ALU::SLT(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,true,true,2,Result);
    zero=Result[0];
    for(int i=0;i<31;i++)   Result[i]=0;
    Result[31]=zero;
}
void ALU::AND(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,false,0,Result);
    // zero check
    zero=false;
    for(int i=0;i<32;i++){
        zero=LogicGates::OR(zero,Result[i]);
    }
    zero=LogicGates::NOT(zero);
}
void ALU::OR(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,false,1,Result);
    // zero check
    zero=false;
    for(int i=0;i<32;i++){
        zero=LogicGates::OR(zero,Result[i]);
    }
    zero=LogicGates::NOT(zero);
}
void ALU::XOR(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,false,3,Result);
    // zero check
    zero=false;
    for(int i=0;i<32;i++){
        zero=LogicGates::OR(zero,Result[i]);
    }
    zero=LogicGates::NOT(zero);
}
void ALU::NOT(bool B[32],bool &zero,bool Result[32],bool &Overflow){
    bool A[32];
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,true,1,Result);
    // zero check
    zero=false;
    for(int i=0;i<32;i++){
        zero=LogicGates::OR(zero,Result[i]);
    }
    zero=LogicGates::NOT(zero);
}
void ALU::NAND(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,true,0,Result);
    // zero check
    zero=false;
    for(int i=0;i<32;i++){
        zero=LogicGates::OR(zero,Result[i]);
    }
    zero=LogicGates::NOT(zero);
}
void ALU::NOR(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,true,1,Result);
    // zero check
    zero=false;
    for(int i=0;i<32;i++){
        zero=LogicGates::OR(zero,Result[i]);
    }
    zero=LogicGates::NOT(zero);
}
void ALU::ZERO(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
    THIRTYTWOBITALU ThirtyTwoBitALU(A,B,true,true,2,Result);
    // zero check
    zero=false;
    for(int i=0;i<32;i++){
        zero=LogicGates::OR(zero,Result[i]);
    }
    zero=LogicGates::NOT(zero);
}
void ALU::SLL(bool A[32],int shamt,bool &zero,bool Result[32],bool &Overflow){
    for(int i=shamt;i<32;i++)   A[i-shamt]=A[i];
    for(int i=32-shamt;i<32;i++)    A[i]=0;
    // zero check
    zero=false;
    for(int i=0;i<32;i++){
        zero=LogicGates::OR(zero,Result[i]);
    }
    zero=LogicGates::NOT(zero);
}
void ALU::SRL(bool A[32],int shamt,bool &zero,bool Result[32],bool &Overflow){
    for(int i=31;i>=shamt;i--)   A[i]=A[i-shamt];
    for(int i=shamt;i>=0;i--)    A[i]=0;
    // zero check
    zero=false;
    for(int i=0;i<32;i++){
        zero=LogicGates::OR(zero,Result[i]);
    }
    zero=LogicGates::NOT(zero);
}
void ALU::SRA(bool A[32],int shamt,bool &zero,bool Result[32],bool &Overflow){
    for(int i=31;i>=shamt;i--)   A[i]=A[i-shamt];
    for(int i=shamt;i>0;i--)    A[i]=A[0]; // sign should be preserved so...
    // zero check
    zero=false;
    for(int i=0;i<32;i++){
        zero=LogicGates::OR(zero,Result[i]);
    }
    zero=LogicGates::NOT(zero);
}