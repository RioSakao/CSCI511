#ifndef STAMPSTREAM_H
#define STAMPSTREAM_H
#include <iostream>
using namespace std;

class stampstream :  public std::ostream
{
        public:
                stampstream(int c, int r);
                ~stampstream();
                 
};

ostream& endrow(ostream& os);
class row;
ostream& operator<<(ostream& os, const row&);
#endif
