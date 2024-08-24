#include <iostream>
#include "converter.h"
#include "Register.h"
#include "Registers.h"
#include "Memory.h"
#include "Instruction.h"
#include "ALU.h"
#include "DecodedInstruction.h"
#include "ALUState.h"
using namespace std;

class PROCESSOR{
    public:
    REGISTER PC;
    REGISTER HI;
    REGISTER LO;
    // REGISTERS Registers;
    MEMORY InstructionMemory;
    MEMORY DataMemory;
    INSTRUCTION Instruction;
    DECODEDINSTRUCTION DecodedInstruction;
    ALUSTATE ALUState;
    void IF(){
        int pc=converter(PC);
        for(int i=0;i<32;i++){
            Instruction[i]=InstructionMemory[pc+i];
        }
        converter(PC,pc+32);
    }
    void ID(){
        // reset
        DecodedInstruction.op=0;
        DecodedInstruction.rs=0;
        DecodedInstruction.rt=0;
        DecodedInstruction.rd=0;
        DecodedInstruction.shamt=0;
        DecodedInstruction.funct=0;
        DecodedInstruction.immediate=0;
        DecodedInstruction.target=0;
        // R-Type
        for (int i=0;i<6;i++)   DecodedInstruction.op=(DecodedInstruction.op<<1)|Instruction[i];
        for (int i=6;i<11;i++)   DecodedInstruction.rs=(DecodedInstruction.rs<<1)|Instruction[i];
        for (int i=11;i<16;i++)   DecodedInstruction.rt=(DecodedInstruction.rt<<1)|Instruction[i];
        for (int i=16;i<21;i++)   DecodedInstruction.rd=(DecodedInstruction.rd<<1)|Instruction[i];
        for (int i=21;i<26;i++)   DecodedInstruction.shamt=(DecodedInstruction.shamt<<1)|Instruction[i];
        for (int i=26;i<32;i++)   DecodedInstruction.funct=(DecodedInstruction.funct<<1)|Instruction[i];
        // I-Type
        for (int i=16;i<32;i++)   DecodedInstruction.immediate=(DecodedInstruction.immediate<<1)|Instruction[i];
        // J-Type
        for (int i=26;i<32;i++)   DecodedInstruction.target=(DecodedInstruction.target<<1)|Instruction[i];
        for(int i=0;i<32;i++)   ALUState.A[i]=REGISTERS::Registers[DecodedInstruction.rs][i];
        for(int i=0;i<32;i++)   ALUState.B[i]=REGISTERS::Registers[DecodedInstruction.rt][i];
    }
    void EX(){
        if(DecodedInstruction.op==0){
            switch(DecodedInstruction.funct){
                case 32: ALU::ADD(ALUState.A,ALUState.B,ALUState.zero,ALUState.Result,ALUState.Overflow);break;
                case 33: ALU::ADDU(ALUState.A,ALUState.B,ALUState.zero,ALUState.Result,ALUState.Overflow);break;
                case 34: ALU::SUB(ALUState.A,ALUState.B,ALUState.zero,ALUState.Result,ALUState.Overflow);break;
                case 35: ALU::SUBU(ALUState.A,ALUState.B,ALUState.zero,ALUState.Result,ALUState.Overflow);break;
                case 42: ALU::SLT(ALUState.A,ALUState.B,ALUState.zero,ALUState.Result,ALUState.Overflow);break;
                case 36: ALU::AND(ALUState.A,ALUState.B,ALUState.zero,ALUState.Result,ALUState.Overflow);break;
                case 37: ALU::OR(ALUState.A,ALUState.B,ALUState.zero,ALUState.Result,ALUState.Overflow);break;
                case 38: ALU::XOR(ALUState.A,ALUState.B,ALUState.zero,ALUState.Result,ALUState.Overflow);break;
                case 39: ALU::NOR(ALUState.A,ALUState.B,ALUState.zero,ALUState.Result,ALUState.Overflow);break;
                case 0: ALU::SLL(ALUState.A,DecodedInstruction.shamt,ALUState.zero,ALUState.Result,ALUState.Overflow);break;
                case 2: ALU::SRL(ALUState.A,DecodedInstruction.shamt,ALUState.zero,ALUState.Result,ALUState.Overflow);break;
                case 3: ALU::SRA(ALUState.A,DecodedInstruction.shamt,ALUState.zero,ALUState.Result,ALUState.Overflow);break;
            }
        }
    }
};


int main(){
    PROCESSOR Pro;
    converter(REGISTERS::Registers[16],16);
    converter(REGISTERS::Registers[17],17);
    Pro.Instruction[6]=true;
    Pro.Instruction[11]=true;
    Pro.Instruction[15]=true;
    Pro.Instruction[16]=true;
    Pro.Instruction[19]=true;
    Pro.Instruction[26]=true;
    // Pro.ID();
    Pro.ID();
    Pro.EX();
    cout<<converter(Pro.ALUState.Result);
    return 0;
}