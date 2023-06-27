#ifndef STAMPBUF_H
#define STAMPBUF_H
#include "stampstream.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <array>
using namespace std;

class row
{
        public:
                row(int r);
                int new_row;
                friend ostream& operator<<(ostream& os, const row&);
};

class stampbuf : public streambuf
{
        public:
                stampbuf(int c, int r);
                ~stampbuf();
                int overflow(int c);
                int sync();
                int get_col() const;
                int get_row() const;
                //friend ostream& operator<<(ostream& os, const Row&);
                void set_newline();
                friend ostream& endrow(ostream& os);
        private:
                char buf[1024];
                int col;
                int row;
};


#endif
