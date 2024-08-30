#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <iostream>
#include "converter.h"
#include "Register.h"
#include "Registers.h"
#include "Memory.h"
#include "Instruction.h"
#include "ALU.h"
#include "ID.h"
#include "IDEX.h"
#include "ALUState.h"

class PROCESSOR{
    public:
    REGISTER PC;
    REGISTER HI;
    REGISTER LO;
    int MEMORY_SIZE=32768;
    MEMORY InstructionMemory;
    MEMORY DataMemory;
    INSTRUCTION Instruction;
    Id id;
    IDEX idex;
    IDEX idex2;
    ALUSTATE ALUState;
    void IF();
    void ID();
    void EX();
    void MEM();
    void WB();
    void RUN();
};


#endif