#ifndef REGISTER_H
#define REGISTER_H

class REGISTER {
public:
    bool bits[32];
    REGISTER();
    bool& operator[](int i);
};

#endif 
