#ifndef MEDIA_H
#define MEDIA_H
#include <string>
using namespace std;

class Media {
        public:
            virtual void display() const =0;
            virtual bool compare_other(const string &s) const =0;
            bool compare_subjects(const string &s) const;
            bool compare_title(const string &s) const;
            bool compare_cn(const string &s) const;
            Media(const string &cn, const string &t, const string &sub, const string &n);
        protected:
            string call_number;
            string title;
            string subjects;
            string notes;
};

#endif
