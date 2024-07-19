#include "converter.h"

void converter(bool A[32],int n){
    std::bitset<32> bits(n);
    for(int i=0;i<32;i++){
        A[i]=bits[31-i];
    }
}

int converter(bool A[32]){
    int n=-A[0];
    for(int i=1;i<32;i++){
        n=2*n+A[i];
    }
    return n;
}
