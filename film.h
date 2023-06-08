#ifndef FILM_H
#define FILM_H
using namespace std;
#include <string>
#include "media.h"

class Film : public Media{
        private:
                string director;
                string year;
        public:
                void display() const;
                bool compare_other(const string& s) const;
                Film(const string &s1, const string &s2, const string &s3,
                            const string &s4, const string &s5, const string &s6);

};

#endif
