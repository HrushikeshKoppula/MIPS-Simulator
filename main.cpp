#include <bits/stdc++.h>
#include "Processor.h"
using namespace std;


int main() {
    PROCESSOR processor;
    

    // a=00000000000000000000000000101010
    // b=00000000000000000000000001010101
    // c=a+b
    // converter(REGISTERS::Registers[10].bits,42);
    // converter(REGISTERS::Registers[11].bits,85);
    // string inst="00000001010010110100100000100000";
    // for(int i=0;i<32;i++)   processor.InstructionMemory[i]=(inst[i]=='1');
    // processor.RUN();
    // cout<<converter(REGISTERS::Registers[9]);


    // c=a+10
    // converter(REGISTERS::Registers[10].bits,9990);
    // string inst="00100001010010010000000000001010";
    // for(int i=0;i<32;i++)   processor.InstructionMemory[i]=(inst[i]=='1');
    // processor.RUN();
    // cout<<converter(REGISTERS::Registers[9]);


    // load a into t2, b into t3, c into t5, d into t6
    // store a + b in t1, c + d in t4
    // store (a+b)-(c+d) in t0
    // store in memory
    int a=12434,b=46475,c=784356,d=98457;
    bool temp[32];
    converter(temp,12434);
    for(int i=0;i<32;i++)   processor.DataMemory[i]=temp[i];
    converter(temp,46475);
    for(int i=0;i<32;i++)   processor.DataMemory[32+i]=temp[i];
    converter(temp,784356);
    for(int i=0;i<32;i++)   processor.DataMemory[64+i]=temp[i];
    converter(temp,98457);
    for(int i=0;i<32;i++)   processor.DataMemory[96+i]=temp[i];
    string inst1="10001100000010100000000000000000";
    string inst2="10001100000010110000000000100000";
    string inst3="10001100000011010000000001000000";
    string inst4="10001100000011100000000001100000";
    string inst5="00000001010010110100100000100000";
    string inst6="00000001101011100110000000100000";
    string inst7="00000001001011000100000000100010";
    string inst8="10101100000010000000000010000000";
    string inst=inst1+inst2+inst3+inst4+inst5+inst6+inst7+inst8;
    for(int i=0;i<inst.size();i++)   processor.InstructionMemory[i]=(inst[i]=='1');
    cout<<"\n";
    processor.RUN();
    cout<<converter(REGISTERS::Registers[10])<<"\n";
    cout<<a<<"\n";
    cout<<converter(REGISTERS::Registers[11])<<"\n";
    cout<<b<<"\n";
    cout << converter(REGISTERS::Registers[13]) << "\n";
    cout<<c<<"\n";
    cout<<converter(REGISTERS::Registers[14])<<"\n";
    cout<<d<<"\n";
    cout<<converter(REGISTERS::Registers[9])<<"\n";
    cout<<a+b<<"\n";
    cout<<converter(REGISTERS::Registers[12])<<"\n";
    cout<<c+d<<"\n";
    cout<<converter(REGISTERS::Registers[8])<<"\n";
    cout<<a+b-c-d<<"\n";
    for(int i=0;i<32;i++)   temp[i]=processor.DataMemory[128+i];
    cout<<converter(temp)<<"\n";
    return 0;
}