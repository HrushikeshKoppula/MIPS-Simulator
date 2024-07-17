#include<iostream>

class INSTRUCTION{};

class SINGLEREGISTER{};
class REGISTERS{
    public:
    SINGLEREGISTER SingleRegister0;
    SINGLEREGISTER SingleRegister1;
    SINGLEREGISTER SingleRegister2;
    SINGLEREGISTER SingleRegister3;
    SINGLEREGISTER SingleRegister4;
    SINGLEREGISTER SingleRegister5;
    SINGLEREGISTER SingleRegister6;
    SINGLEREGISTER SingleRegister7;
    SINGLEREGISTER SingleRegister8;
    SINGLEREGISTER SingleRegister9;
    SINGLEREGISTER SingleRegister10;
    SINGLEREGISTER SingleRegister11;
    SINGLEREGISTER SingleRegister12;
    SINGLEREGISTER SingleRegister13;
    SINGLEREGISTER SingleRegister14;
    SINGLEREGISTER SingleRegister15;
    SINGLEREGISTER SingleRegister16;
    SINGLEREGISTER SingleRegister17;
    SINGLEREGISTER SingleRegister18;
    SINGLEREGISTER SingleRegister19;
    SINGLEREGISTER SingleRegister20;
    SINGLEREGISTER SingleRegister21;
    SINGLEREGISTER SingleRegister22;
    SINGLEREGISTER SingleRegister23;
    SINGLEREGISTER SingleRegister24;
    SINGLEREGISTER SingleRegister25;
    SINGLEREGISTER SingleRegister26;
    SINGLEREGISTER SingleRegister27;
    SINGLEREGISTER SingleRegister28;
    SINGLEREGISTER SingleRegister29;
    SINGLEREGISTER SingleRegister30;
    SINGLEREGISTER SingleRegister31;
    // void load(SINGLEREGISTER SingleRegister)
};

class ALU{};

class MEMORY{};

class CONTROL{};

class MIPS{
    public:
    REGISTERS Registers;
    ALU ALU;
    MEMORY Memory;
    CONTROL Control;
    void execute(INSTRUCTION Instruction){}
};

int main(){
    
    return 0;
}