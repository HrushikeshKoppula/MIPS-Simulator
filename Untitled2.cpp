#include <iostream>
#include "converter.h"
#include "ALU.h"

// class ALU{
//     // THIRTYTWOBITALU(A, B, CarryIn, Binv, OP, zero, Result, Overflow);
//     public:
//     static void AND(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
//         THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,false,0,zero,Result,Overflow);
//     }
//     static void OR(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
//         THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,false,1,zero,Result,Overflow);
//     }
//     static void ADD(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
//         THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,false,2,zero,Result,Overflow);
//     }
//     static void NOT(bool B[32],bool &zero,bool Result[32],bool &Overflow){
//         bool A[32];
//         THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,true,1,zero,Result,Overflow);
//     }
//     static void NAND(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
//         THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,true,0,zero,Result,Overflow);
//     }
//     static void NOR(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
//         THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,true,1,zero,Result,Overflow);
//     }
//     static void SUB(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
//         THIRTYTWOBITALU ThirtyTwoBitALU(A,B,true,true,2,zero,Result,Overflow);
//     }
//     static void ZERO(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
//         THIRTYTWOBITALU ThirtyTwoBitALU(A,B,true,true,2,zero,Result,Overflow);
//     }
//     static void LESS(bool A[32],bool B[32],bool &zero,bool Result[32],bool &Overflow){
//         THIRTYTWOBITALU ThirtyTwoBitALU(A,B,true,true,2,zero,Result,Overflow);
//         zero=(Result[0]==1);
//     }
// };

int main(){
    bool Result[32];
    bool A[32];
    bool B[32];
    converter(A,2147483646);
    converter(B,2147483647);
    // Debuggin converters
    std::cout<<converter(A)<<"\n";
    std::cout<<converter(B)<<"\n";
    for(int i=0;i<32;i++)   std::cout<<A[i];
    std::cout<<"\n";
    for(int i=0;i<32;i++)   std::cout<<B[i];
    std::cout<<"\n";
    bool zero=false;
    bool Overflow=false;
    ALU::LESS(A,B,zero,Result,Overflow);
    int result=converter(Result);
    std::cout<<zero<<" "<<result<<" "<<Overflow<<"\n";
    return 0;
}