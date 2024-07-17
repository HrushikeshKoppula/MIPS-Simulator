#include "OneBitALU.h"

bool OneBitALU::Binvert = false;
int OneBitALU::Operation = 0;

void OneBitALU::setSignals(bool newBinvert, int newOperation) {
    Binvert = newBinvert;
    Operation = newOperation;
}

void OneBitALU::RUN() {
    if(!Binvert){
        switch (Operation) {
            case 0:
                Result = LogicGates::AND(a, b);
                break;
            case 1:
                Result = LogicGates::OR(a, b);
                break;
            case 2:
                Result = LogicGates::XOR(a, b);
                CarryOut = LogicGates::AND(a, b);
                Result = LogicGates::XOR(Result, CarryIn);
                CarryOut = LogicGates::OR(CarryOut, LogicGates::AND(CarryIn, LogicGates::OR(a, b)));
                break;
        }
    }
    else{
        switch (Operation) {
            case 0:
                Result = LogicGates::AND(a, !b);
                break;
            case 1:
                Result = LogicGates::OR(a, !b);
                break;
            case 2:
                Result = LogicGates::XOR(a, !b);
                CarryOut = LogicGates::AND(a, !b);
                Result = LogicGates::XOR(Result, CarryIn);
                CarryOut = LogicGates::OR(CarryOut, LogicGates::AND(CarryIn, LogicGates::OR(a, !b)));
                break;
        }
    }
}
