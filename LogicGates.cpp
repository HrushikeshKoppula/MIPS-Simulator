#include<iostream>

class LogicGates{
    public:
        static bool AND(bool A,bool B){return A&B;}
        static bool OR(bool A,bool B){return A|B;}
        static bool NOT(bool A){return !A;}
        static bool XOR(bool A,bool B){return A^B;}
};

int main(){
    bool A=true;
    bool B=true;
    std::cout<<LogicGates::AND(A,B);
    return 0;
}