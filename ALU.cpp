#include <iostream>
#include <bitset>
#include "OneBitALU.h"

class ALU{
    public:
        // bool A[32];
        // bool B[32];
        // bool CarryIn;
        bool Result[32];
        bool CarryOut;
        ONEBITALU OneBitALU[32];
        ALU(){}
        ALU(bool A[32],bool B[32],bool CarryIn,bool Binv,int OP){
            ONEBITALU::setSignals(Binv,OP);
            for(int i=0;i<32;i++){
                // this->A[i]=A[i];
                // this->B[i]=B[i];
                OneBitALU[i]=ONEBITALU(A[i],B[i],CarryIn);
                Result[i]=OneBitALU[i].Result;
                CarryIn=OneBitALU[i].CarryOut;
            }
        }
};

void converter(bool A[32],int n){
    std::bitset<32> bits(n);
    for(int i=0;i<32;i++){
        A[i]=bits[i];
    }
}

int main(){
    // ONEBITALU ALU0(1,1,0);
    // ONEBITALU::setSignals(true,2);
    // ALU0.RUN();
    // std::cout<<ALU0.Result<<" "<<ALU0.CarryOut<<" ";
    ALU Alu;
    bool Result[32];
    bool A[32];
    bool B[32];
    converter(A,32);
    converter(B,32);
    Result=Alu(A,B,0).Result;
    return 0;
}