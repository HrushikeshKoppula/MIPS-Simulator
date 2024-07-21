#include <iostream>
#include "converter.h"
#include "ALU.h"

int main(){
    bool Result[32];
    bool A[32];
    bool B[32];
    converter(A,2147483646);
    converter(B,2147483647);
    // Debuggin converters
    std::cout<<converter(A)<<"\n";
    std::cout<<converter(B)<<"\n";
    for(int i=0;i<32;i++)   std::cout<<A[i];
    std::cout<<"\n";
    for(int i=0;i<32;i++)   std::cout<<B[i];
    std::cout<<"\n";
    bool zero=false;
    bool Overflow=false;
    ALU::SUB(A,B,zero,Result,Overflow);
    int result=converter(Result);
    std::cout<<zero<<" "<<result<<" "<<Overflow<<"\n";
    return 0;
}