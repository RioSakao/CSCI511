#ifndef PERIODICAL_H
#define PEIIODICAL_H
#include <string>
#include "media.h"

using namespace std;

class Periodical : public Media {
        private:
                string author;
                string description;
                string publisher;
                string publishing_history;
                string series;
                string related_title;
                string other_forms_of_title;
                string govt_doc_number;
        public:
                void display() const;
                bool compare_other(const string& s) const;
                Periodical(const string &s1, const string &s2, const string &s3,
                            const string &s4, const string &s5, const string &s6,
                            const string &s7, const string &s8, const string &s9,
                            const string &s10, const string &s11, const string &s12);

};
#endif
