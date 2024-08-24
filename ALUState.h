#ifndef ALUSTATE_H
#define ALUSTATE_H

class ALUSTATE{
    public:
    bool A[32];
    bool B[32];
    bool CarryIn;
    bool Binv;
    int OP;
    bool zero;
    bool Result[32];
    bool Overflow;
};

#endif