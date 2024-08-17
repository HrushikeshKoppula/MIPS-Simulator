#ifndef THIRTYTWOBITALU_H
#define THIRTYTWOBITALU_H

#include <stdexcept>
#include "OneBitALU.h"

class THIRTYTWOBITALU{
    public:
        THIRTYTWOBITALU(bool A[32],bool B[32],bool CarryIn,bool Binv,int OP,bool &zero,bool Result[32],bool &Overflow){
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
            // Overflow Check
            if((OP==2)&&(((!Binv)&&(A[0]==B[0])&&(A[0]!=Result[0]))||((Binv)&&(A[0]!=B[0])&&(A[0]==Result[0])))){
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
};

#endif
