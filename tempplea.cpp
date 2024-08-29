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
    Id id;
    IDEX idex;
    IDEX idex2;
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
        id.op=0;
        id.rs=0;
        id.rt=0;
        id.rd=0;
        id.shamt=0;
        id.funct=0;
        // for(int i=0;i<16;i++)   idex.immediate[i]=0;
        id.target=0;
        // for(int i=0;i<32;i++)   
        // R-Type
        for (int i=0;i<6;i++)   id.op=(id.op<<1)|Instruction[i];
        for (int i=6;i<11;i++)   id.rs=(id.rs<<1)|Instruction[i];
        for (int i=11;i<16;i++)   id.rt=(id.rt<<1)|Instruction[i];
        for (int i=16;i<21;i++)   id.rd=(id.rd<<1)|Instruction[i];
        for (int i=21;i<26;i++)   id.shamt=(id.shamt<<1)|Instruction[i];
        for (int i=26;i<32;i++)   id.funct=(id.funct<<1)|Instruction[i];
        // I-Type
        for (int i=16;i<32;i++)   id.immediate[i-16]=(id.immediate[i-16]<<1)|Instruction[i];
        // J-Type
        for (int i=26;i<32;i++)   id.target=(id.target<<1)|Instruction[i];
        idex.op=id.op;
        idex.rs=id.rs;
        idex.rt=id.rt;
        idex.rd=id.rd;
        idex.shamt=id.shamt;
        idex.funct=id.funct;
        for(int i=0;i<16;i++)   idex.immediate[i]=id.immediate[i];
        idex.target=id.target;
    }
    void EX(){
        if(idex.op==0){ //R-Type
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            for(int i=0;i<32;i++)   idex.B[i]=REGISTERS::Registers[idex.rt][i];
                switch(idex.funct){
                    case 32: ALU::ADD(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);break;
                    case 33: ALU::ADDU(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);break;
                    case 34: ALU::SUB(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);break;
                    case 35: ALU::SUBU(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);break;
                    case 42: ALU::SLT(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);break;
                    case 36: ALU::AND(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);break;
                    case 37: ALU::OR(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);break;
                    case 38: ALU::XOR(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);break;
                    case 39: ALU::NOR(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);break;
                    case 0: ALU::SLL(idex.A,idex.shamt,idex.zero,idex.Result,idex.Overflow);break;
                    case 2: ALU::SRL(idex.A,idex.shamt,idex.zero,idex.Result,idex.Overflow);break;
                    case 3: ALU::SRA(idex.A,idex.shamt,idex.zero,idex.Result,idex.Overflow);break;
                }
        }

        // I-Type

        if(idex.op==0b001000){//ADDI
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            // Sign-extended
            for(int i=0;i<16;i++)   idex.B[i]=idex.immediate[0];
            for(int i=16;i<32;i++)  idex.B[i]=idex.immediate[i-16];
            ALU::ADD(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);
        }

        if(idex.op==0b001001){// ADDIU
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            // Sign-extended
            for(int i=0;i<16;i++)   idex.B[i]=idex.immediate[0];
            for(int i=16;i<32;i++)  idex.B[i]=idex.immediate[i-16];
            ALU::ADDU(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);
        }

        if(idex.op==0b001010){// SLTI
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            // Sign-extended
            for(int i=0;i<16;i++)   idex.B[i]=idex.immediate[0];
            for(int i=16;i<32;i++)  idex.B[i]=idex.immediate[i-16];
            ALU::SLT(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);
        }
        
        if(idex.op==0b001100){// ANDI
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            // Zero-extended
            for(int i=0;i<16;i++)   idex.B[i]=0;
            for(int i=16;i<32;i++)  idex.B[i]=idex.immediate[i-16];
            ALU::AND(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);
        }

        if(idex.op==0b001101){// ORI
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            // Zero-extended
            for(int i=0;i<16;i++)   idex.B[i]=0;
            for(int i=16;i<32;i++)  idex.B[i]=idex.immediate[i-16];
            ALU::OR(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);
        }
        
        if(idex.op==0b001101){// XORI
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            // Zero-extended
            for(int i=0;i<16;i++)   idex.B[i]=0;
            for(int i=16;i<32;i++)  idex.B[i]=idex.immediate[i-16];
            ALU::XOR(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);
        }

        if(idex.op==0b100011){// LW
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            // Sign-extended
            for(int i=0;i<16;i++)   idex.B[i]=idex.immediate[0];
            for(int i=16;i<32;i++)  idex.B[i]=idex.immediate[i-16];
            ALU::ADD(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);
        }
        idex2.op=idex.op;
        idex2.rs=idex.rs;
        idex2.rt=idex.rt;
        idex2.rd=idex.rd;
        idex2.shamt=idex.shamt;
        idex2.funct=idex.funct;
        for(int i=0;i<16;i++)   idex2.immediate[i]=idex.immediate[i];
        idex2.target=idex.target;
        idex2.zero=idex.zero;
        for(int i=0;i<32;i++)   idex2.Result[i]=idex.Result[i];
        idex2.Overflow=idex.Overflow;
    }
    void MEM(){
        if(idex2.op==0b100011){ //LW
            int effective_address = converter(idex2.Result);
            for(int i=0;i<32;i++)   idex2.Result[i]=DataMemory[effective_address+i];
        }
    }
    void WB(){
        if(idex2.op==0){
            for(int i=0;i<32;i++)   REGISTERS::Registers[idex2.rd][i]=idex2.Result[i];
        }
        if(idex2.op==0b001000||idex2.op==0b001001||idex2.op==0b001010||idex2.op==0b001011||idex2.op==0b00110||idex2.op==0b001101||idex2.op==0b001110||idex2.op==0b100011){
            for(int i=0;i<32;i++)   REGISTERS::Registers[idex2.rt][i]=idex2.Result[i];
        }
    }
};


int main(){
    PROCESSOR Pro;
    // Add Example 00000010000100011001000000100000
    // converter(REGISTERS::Registers[16],16);
    // converter(REGISTERS::Registers[17],17);
    // Pro.Instruction[6]=true;
    // Pro.Instruction[11]=true;
    // Pro.Instruction[15]=true;
    // Pro.Instruction[16]=true;
    // Pro.Instruction[19]=true;
    // Pro.Instruction[26]=true;
    // Pro.ID();
    // Pro.ID();
    // Pro.EX();
    // Pro.MEM();
    // Pro.WB();
    // cout<<converter(REGISTERS::Registers[18]);
    // LW Example 10001101001010000000000000001000
    // for(int i=1;i<32;i++)   Pro.DataMemory[216+i]=1;
    // converter(REGISTERS::Registers[9],216);
    // Pro.Instruction[0]=true;
    // Pro.Instruction[4]=true;
    // Pro.Instruction[5]=true;
    // Pro.Instruction[7]=true;
    // Pro.Instruction[10]=true;
    // Pro.Instruction[12]=true;
    // Pro.ID();
    // Pro.EX();
    // Pro.MEM();
    // Pro.WB();
    // cout<<converter(REGISTERS::Registers[8]);
    // ADDI Example 00100001001010000000000000001010
    // REGISTER R;
    // converter(R,556269578);
    // converter(REGISTERS::Registers[9],216);
    // for(int i=0;i<32;i++)   Pro.Instruction[i]=R[i];
    // Pro.ID();
    // Pro.EX();
    // Pro.MEM();
    // Pro.WB();
    // cout<<converter(REGISTERS::Registers[8]);
    return 0;
}