#include <iostream>
#include <bitset>
#include "OneBitALU.h"

class ALU{
    public:
        // bool A[32];
        // bool B[32];
        // bool CarryIn;
        // bool Result[32];
        // bool CarryOut;
        // ONEBITALU OneBitALU[32];
        // ALU(){}
        ALU(bool A[32],bool B[32],bool CarryIn,bool Binv,int OP,bool Result[32],bool &CarryOut){
            ONEBITALU::setSignals(Binv,OP);
            for(int i=31;i>=0;i--){
                // this->A[i]=A[i];
                // this->B[i]=B[i];
                // OneBitALU[i]=;
                ONEBITALU OneBitALU(A[i],B[i],CarryIn);
                OneBitALU.RUN();
                Result[i]=OneBitALU.Result;
                CarryIn=OneBitALU.CarryOut;
                // Debugging output
                // std::cout << "Step " << i << ": Result = " << Result[i] << ", CarryOut = " << CarryOut << std::endl;
            }
        }
};

void converter(bool A[32],int n){
    std::bitset<32> bits(n);
    for(int i=0;i<32;i++){
        A[i]=bits[31-i];
    }
}

int converter(bool A[32]){
    int n=-A[0];
    for(int i=1;i<32;i++){
        n=2*n+A[i];
    }
    return n;
}

int main(){
    bool Result[32];
    bool CarryOut=false;
    bool A[32];
    bool B[32];
    bool CarryIn=false;
    converter(A,2147483647);
    converter(B,-2147483648);
    // Debuggin converters
    std::cout<<converter(A)<<"\n";
    std::cout<<converter(B)<<"\n";
    for(int i=0;i<32;i++)   std::cout<<A[i];
    std::cout<<"\n";
    for(int i=0;i<32;i++)   std::cout<<B[i];
    std::cout<<"\n";
    bool Binv=false;
    int OP=2;
    ALU(A,B,CarryIn,Binv,OP,Result,CarryOut);
    int result=converter(Result);
    std::cout<<result<<" "<<CarryOut<<"\n";
    return 0;
}