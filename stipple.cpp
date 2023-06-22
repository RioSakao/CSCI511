#include "stipple.h"
#include <iomanip>

stipple::stipple(char arg1, int arg2)
        :character(arg1), count(arg2)
{
}

ostream& operator<<(ostream &os, const stipple &s)
{
        for(int i=0; i< s.count/2; i++){
            os << s.character << '.';
        }//for
        
        if(s.count%2 != 0) //odd
        {
            os << s.character;
        }//if
        
        return os;
}
