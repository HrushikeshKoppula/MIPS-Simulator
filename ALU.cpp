#include <iostream>
#include "converter.h"
#include "ThirtyTwoBitALU.h"

class ALU{
    public:
    static void AND(bool A[32],bool B[32],bool Result[32]){
        bool temp;
        THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,false,0,Result,temp);
    }
    static void OR(bool A[32],bool B[32],bool Result[32]){
        bool temp;
        THIRTYTWOBITALU ThirtyTwoBitALU(A,B,false,false,1,Result,temp);
    }
    static void ADD(bool A[32],bool B[32],bool Result[32]){
        
    }
};

int main(){
    bool Result[32];
    bool CarryOut=false;
    bool A[32];
    bool B[32];
    bool CarryIn=true;
    converter(A,2);
    converter(B,-2);
    // Debuggin converters
    std::cout<<converter(A)<<"\n";
    std::cout<<converter(B)<<"\n";
    for(int i=0;i<32;i++)   std::cout<<A[i];
    std::cout<<"\n";
    for(int i=0;i<32;i++)   std::cout<<B[i];
    std::cout<<"\n";
    bool Binv=true;
    int OP=2;
    // THIRTYTWOBITALU(A, B, CarryIn, Binv, OP, Result, CarryOut);
    ALU::AND(A,B,Result);
    int result=converter(Result);
    std::cout<<result<<" "<<CarryOut<<"\n";
    return 0;
}