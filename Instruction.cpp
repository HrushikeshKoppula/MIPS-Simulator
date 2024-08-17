#include "Instruction.h"

INSTRUCTION::INSTRUCTION(){
    for(int i=0;i<32;i++)   bits[i]=0;
}

bool& INSTRUCTION::operator[](int i){
    return bits[i];
}