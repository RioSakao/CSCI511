#ifndef STIPPLE_H
#define STIPPLE_H   

#include <iostream>
using namespace std;

class stipple{
        public:
                stipple(char arg1, int arg2);
                friend ostream& operator<<(ostream &os, const stipple &s);
        private:
                char character;
                int count;

};

#endif
