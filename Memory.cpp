#include "Memory.h"

MEMORY::MEMORY(int size) {
    this->size = size;
    bits = new bool[size];
}

bool& MEMORY::operator[](int i) {
    return bits[i];
}

MEMORY::~MEMORY() {
    delete[] bits;
}
