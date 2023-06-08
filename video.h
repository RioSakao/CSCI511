#ifndef video_H
#define video_H
#include <string>
#include "media.h"
using namespace std;


class Video : public Media {
        private:
                string description;
                string distributor;
                string series;
                string label;
        public:
                void display() const;
                bool compare_subjects(const string &s) const;
                bool compare_title(const string &s) const;
                bool compare_cn(const string &s) const;
                bool compare_other(const string& s) const;
                Video(const string &s1, const string &s2, const string &s3,
                            const string &s4, const string &s5, const string &s6,
                            const string &s7, const string &s8);
};

#endif
