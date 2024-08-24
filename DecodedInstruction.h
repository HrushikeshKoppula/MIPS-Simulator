#ifndef DECODEDINSTRUCTION_H
#define DECODEDINSTRUCTION_H

class DECODEDINSTRUCTION{
    public:
    // R-Type
    int op=0;
    int rs=0;
    int rt=0;
    int rd=0;
    int shamt=0;
    int funct=0;
    // I-Type;
    int immediate=0;
    // J-Type
    int target=0;
};

#endif