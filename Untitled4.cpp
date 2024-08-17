#include <bits/stdc++.h>
#include "Register.h"
#include "converter.h"
#include "ALU.h"
using namespace std;

int main(){
    REGISTER s0;
    REGISTER s1;
    REGISTER s2;
    converter(s1.bits,INT_MAX);
    converter(s2.bits,INT_MAX);
    bool zero,overflow;
    ALU::ADD(s1.bits,s2.bits,zero,s0.bits,overflow);
    // for(int i=0;i<32;i++)   cout<<s0[i];
    cout<<converter(s0.bits);
    cout<<" "<<overflow;
}