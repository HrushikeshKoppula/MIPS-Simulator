#ifndef DECODEDINSTRUCTION_H
#define DECODEDINSTRUCTION_H

class DECODEDINSTRUCTION{
    public:
    // R-Type
    int op;
    int rs;
    int rt;
    int rd;
    int shamt;
    int funct;
    // I-Type;
    int immediate;
    // J-Type
    int target;
};

#endif