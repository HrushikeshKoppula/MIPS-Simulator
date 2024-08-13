#ifndef MEMORY_H
#define MEMORY_H

class MEMORY {
public:
    int size;
    bool* bits;
    MEMORY(int size = 32768);
    bool& operator[](int i);
    ~MEMORY();
};

#endif
