#include <iostream>
#include "OneBitALU.h"

class ALU{
    public:
        bool A;
        bool B;

};

int main(){
    OneBitALU ALU0(1,1,0);
    OneBitALU::setSignals(true,2);
    ALU0.RUN();
    std::cout<<ALU0.Result<<" "<<ALU0.CarryOut<<" ";
    return 0;
}