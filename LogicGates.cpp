#include "LogicGates.h"

bool LogicGates::AND(bool A, bool B) {
    return A & B;
}

bool LogicGates::OR(bool A, bool B) {
    return A | B;
}

bool LogicGates::NOT(bool A) {
    return !A;
}

bool LogicGates::XOR(bool A, bool B) {
    return A ^ B;
}
