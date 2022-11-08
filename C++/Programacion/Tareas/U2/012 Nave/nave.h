#include <iostream>

using namespace std;

class Nave{
    int id;
    public:
        static int total;
        Nave() {total++;}
        ~Nave() {total--;}
        inline static int cuenta() {return total;}
};

int Nave::total = 0;