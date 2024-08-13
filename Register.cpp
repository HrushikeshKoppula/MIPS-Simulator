#include "Register.h"

REGISTER::REGISTER(){
    for(int i=0;i<32;i++)   bits[i]=0;
}

bool& REGISTER::operator[](int i) {
    return bits[i];
}