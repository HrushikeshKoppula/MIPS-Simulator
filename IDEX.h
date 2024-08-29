#ifndef IDEX_H
#define IDEX_H

class IDEX{
    public:
    // R-Type
    int op=0;
    int rs=0;
    int rt=0;
    int rd=0;
    int shamt=0;
    int funct=0;
    // I-Type;
    bool immediate[16];
    // J-Type
    int target=0;
    // ALUSTATE
    bool A[32];
    bool B[32];
    bool zero;
    bool Result[32];
    bool Overflow;
};

#endif