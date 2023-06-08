#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "media.h"

using namespace std;

class Book : public Media {
        private:
            string author;
            string description;
            string publisher;
            string city;
            string year;
            string series;
        public:
            void display() const;
            bool compare_other(const string& s) const;
            Book(const string &s1, const string &s2, const string &s3,
                            const string &s4, const string &s5, const string &s6,
                            const string &s7, const string &s8, const string &s9,
                            const string &s10);
};

#endif
