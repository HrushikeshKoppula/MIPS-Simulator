#include <bits/stdc++.h>
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
    int MEMORY_SIZE=32768;
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
        // Load-Store
        if(idex.op==0b100011){// LW
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            // Sign-extended
            for(int i=0;i<16;i++)   idex.B[i]=idex.immediate[0];
            for(int i=16;i<32;i++)  idex.B[i]=idex.immediate[i-16];
            ALU::ADD(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);
            if(idex.Result[30]&&idex.Result[31])  cout<<"Address used is not Word Alligned\n";
            idex.Result[30]=false;
            idex.Result[31]=false;
        }
        if(idex.op==0b100000){// LB
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            // Sign-extended
            for(int i=0;i<16;i++)   idex.B[i]=idex.immediate[0];
            for(int i=16;i<32;i++)  idex.B[i]=idex.immediate[i-16];
            ALU::ADD(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);
        }
        if(idex.op==0b101011){// SW
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            // Sign-extended
            for(int i=0;i<16;i++)   idex.B[i]=idex.immediate[0];
            for(int i=16;i<32;i++)  idex.B[i]=idex.immediate[i-16];
            ALU::ADD(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);
            if(idex.Result[30]&&idex.Result[31])  cout<<"Address used is not Word Alligned\n";
            idex.Result[30]=false;
            idex.Result[31]=false;
        }
        if(idex.op==0b101000){// SB
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            // Sign-extended
            for(int i=0;i<16;i++)   idex.B[i]=idex.immediate[0];
            for(int i=16;i<32;i++)  idex.B[i]=idex.immediate[i-16];
            ALU::ADD(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);
        }
        // Branch
        if(idex.op==0b000100){ // BEQ
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            for(int i=0;i<32;i++)   idex.B[i]=REGISTERS::Registers[idex.rt][i];
            ALU::ZERO(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);
        }
        if(idex.op==0b000101){ // BNE
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            for(int i=0;i<32;i++)   idex.B[i]=REGISTERS::Registers[idex.rt][i];
            ALU::ZERO(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);
        }
        if(idex.op==0b000001){//BLTZ
            for(int i=0;i<32;i++)   idex.A[i]=REGISTERS::Registers[idex.rs][i];
            ALU::SLT(idex.A,idex.B,idex.zero,idex.Result,idex.Overflow);
        }
        // J - Type
        // if(idex.op==0b000010){// J

        // }
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
        if(idex2.Overflow)  cout<<"Overflow occured\n";
    }
    void MEM(){
        if(idex2.op==0b100011){ //LW
            int effective_address = converter(idex2.Result);
            for(int i=0;i<32;i++)   idex2.Result[i]=DataMemory[effective_address+i];
        }
        if(idex2.op==0b100000){ //LB
            int effective_address = converter(idex2.Result);
            for(int i=0;i<24;i++)   idex2.Result[i]=DataMemory[effective_address];
            for(int i=0;i<8;i++)   DataMemory[effective_address+i]=idex2.Result[24+i];
        }
        if(idex2.op==0b101011){ //SW
            int effective_address = converter(idex2.Result);
            for(int i=0;i<32;i++)   DataMemory[effective_address+i]=idex2.Result[i];
        }
        if(idex2.op==0b101011){ //SB
            int effective_address = converter(idex2.Result);
            for(int i=0;i<24;i++)   idex2.Result[i]=DataMemory[effective_address];
            for(int i=0;i<8;i++)   DataMemory[effective_address+i]=idex2.Result[24+i];
        }
        if(idex2.op==0b000100&&!idex2.zero){// BEQ
            bool temp[32];
            bool zero;
            bool Overflow;
            for(int i=0;i<14;i++)   temp[i]=idex2.immediate[0];
            for(int i=0;i<16;i++)   temp[i+14]=idex2.immediate[i];
            temp[30]=false;
            temp[31]=false;
            ALU::ADD(PC.bits,temp,zero,PC.bits,Overflow);
            idex2.op=0;
            idex2.rs=0;
            idex2.rt=0;
            idex2.rd=0;
            idex2.shamt=0;
            idex2.funct=0;
            for(int i=0;i<16;i++)   idex2.immediate[i]=false;
            idex2.target=0;
            idex2.zero=false;
            for(int i=0;i<32;i++)   idex2.A[i]=false;
            for(int i=0;i<32;i++)   idex2.B[i]=false;
            for(int i=0;i<32;i++)   idex2.Result[i]=false;
            idex2.Overflow=false;
        }
        if(idex2.op==0b000101&&idex2.zero){// BNE
            bool temp[32];
            bool zero;
            bool Overflow;
            for(int i=0;i<14;i++)   temp[i]=idex2.immediate[0];
            for(int i=0;i<16;i++)   temp[i+14]=idex2.immediate[i];
            temp[30]=false;
            temp[31]=false;
            ALU::ADD(PC.bits,temp,zero,PC.bits,Overflow);
            idex2.op=0;
            idex2.rs=0;
            idex2.rt=0;
            idex2.rd=0;
            idex2.shamt=0;
            idex2.funct=0;
            for(int i=0;i<16;i++)   idex2.immediate[i]=false;
            idex2.target=0;
            idex2.zero=false;
            for(int i=0;i<32;i++)   idex2.A[i]=false;
            for(int i=0;i<32;i++)   idex2.B[i]=false;
            for(int i=0;i<32;i++)   idex2.Result[i]=false;
            idex2.Overflow=false;
        }
        if(idex2.op==0b000001&&idex2.zero){// BLTZ
            bool temp[32];
            bool zero;
            bool Overflow;
            for(int i=0;i<14;i++)   temp[i]=idex2.immediate[0];
            for(int i=0;i<16;i++)   temp[i+14]=idex2.immediate[i];
            temp[30]=false;
            temp[31]=false;
            ALU::ADD(PC.bits,temp,zero,PC.bits,Overflow);
            idex2.op=0;
            idex2.rs=0;
            idex2.rt=0;
            idex2.rd=0;
            idex2.shamt=0;
            idex2.funct=0;
            for(int i=0;i<16;i++)   idex2.immediate[i]=false;
            idex2.target=0;
            idex2.zero=false;
            for(int i=0;i<32;i++)   idex2.A[i]=false;
            for(int i=0;i<32;i++)   idex2.B[i]=false;
            for(int i=0;i<32;i++)   idex2.Result[i]=false;
            idex2.Overflow=false;
        }
    }
    void WB(){
        if(idex2.op==0){ // all R-Type instructions write to rd
            for(int i=0;i<32;i++)   REGISTERS::Registers[idex2.rd][i]=idex2.Result[i];
        }
        if(idex2.op==0b001000||idex2.op==0b001001||idex2.op==0b001010||idex2.op==0b001100||idex2.op==0b001101||idex2.op==0b001110||idex2.op==0b100011||idex2.op==0b100000){
            // all I-Type instructions write to rt, except SW,SB
            for(int i=0;i<32;i++)   REGISTERS::Registers[idex2.rt][i]=idex2.Result[i];
        }
    }
    void RUN(){
        while(converter(PC)<MEMORY_SIZE){
            IF();
            ID();
            EX();
            MEM();
            WB();
        }
    }
};



int main() {
    PROCESSOR processor;
    // a=00000000000000000000000000101010
    // b=00000000000000000000000001010101
    // c=a+b
    converter(REGISTERS::Registers[10].bits,42);
    converter(REGISTERS::Registers[11].bits,85);
    string inst="00000001010010110100100000100000";
    for(int i=0;i<32;i++)   processor.InstructionMemory[i]=(inst[i]=='1');
    processor.RUN();
    cout<<converter(REGISTERS::Registers[9]);
    return 0;
}