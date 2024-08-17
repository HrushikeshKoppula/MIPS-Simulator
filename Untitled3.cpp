#include <iostream>
#include "Memory.h"
#include "Register.h"
#include "Registers.h"
#include "Instruction.h"
using namespace std;

int main(){
    // MEMORY DataMemory;
    // const REGISTER Register;
    // REGISTER Register;
    // for(int i=0;i<32;i++)   DataMemory[32+i]=1;
    // for(int i=0;i<32;i++)   Register[i]=DataMemory[32+i];
    // for(int i=0;i<32;i++)   DataMemory[320+i]=Register[i];
    // for(int i=0;i<32;i++)   cout<<DataMemory[320+i];
    // REGISTERS Registers;
    // Registers.dollar_s1.bits[1]=1;
    INSTRUCTION Instruction;
    cout<<Instruction[31];
    return 0;
}