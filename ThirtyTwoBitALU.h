#ifndef THIRTYTWOBITALU_H
#define THIRTYTWOBITALU_H

#include <stdexcept>
#include "OneBitALU.h"

class THIRTYTWOBITALU{
    public:
        THIRTYTWOBITALU(bool A[32],bool B[32],bool CarryIn,bool Binv,int OP,bool Result[32],bool &CarryOut){
            ONEBITALU::setSignals(Binv,OP);
            for(int i=31;i>0;i--){
                ONEBITALU OneBitALU(A[i],B[i],CarryIn);
                OneBitALU.RUN();
                Result[i]=OneBitALU.Result;
                CarryIn=OneBitALU.CarryOut;
            }
            ONEBITALU OneBitALU(A[0], B[0], CarryIn);
            OneBitALU.RUN();
            Result[0] = OneBitALU.Result;
            if((A[0]==B[0])&&(A[0]!=Result[0])){
                throw std::overflow_error("Overflow occurred");
            }
        }
};

#endif
