#ifndef ONEBITALU_H
#define ONEBITALU_H

#include "LogicGates.h"

class OneBitALU {
public:
    bool a;
    bool b;
    bool CarryIn;
    static bool Binvert;
    static int Operation;
    bool Result;
    bool CarryOut;
    
    OneBitALU(bool a, bool b, bool CarryIn) : a(a), b(b), CarryIn(CarryIn), Result(false), CarryOut(false) {}

    static void setSignals(bool newBinvert, int newOperation);

    void RUN();
};

#endif // ONEBITALU_H
