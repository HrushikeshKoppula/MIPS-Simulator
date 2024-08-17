#ifndef INSTRUCTION_H
#define INSTRUCTION_H

class INSTRUCTION{
public:
    bool bits[32];
    INSTRUCTION();
    bool& operator[](int i);
};

#endif 
