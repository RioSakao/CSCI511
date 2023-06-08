#include "video.h"
#include <iomanip>
#include <iostream>

Video::Video(const string &s1, const string &s2, const string &s3,
                            const string &s4, const string &s5, const string &s6,
                            const string &s7, const string &s8)
        :Media::Media(s1,s2,s3,s6), description(s4), distributor(s5), series(s6), label(s7)
{
}

void Video::display() const{

        cout << "============================" << endl;
        cout << "========== VIDEO ===========" << endl;
        cout << "============================" << endl;
        cout << left;
        cout << setw(20) << "call number: " << setw(20) << call_number << endl;
        cout << setw(20) << "title: " << setw(20) << title << endl;
        cout << setw(20) << "subjects: " << setw(20) << subjects << endl;
        cout << setw(20) << "distributor: " << setw(20) << distributor << endl;
        cout << setw(20) << "description: " << setw(20) << description << endl;
        cout << setw(20) << "notes: " << setw(20) << notes << endl;
        cout << setw(20) << "series: " << setw(20) << series << endl;
        cout << setw(20) << "label: " << setw(20) << label << endl;

}


bool Video::compare_other(const string& s) const{
        if(s==distributor || s==description || s==series || s==label) {
                return true;
        }
        return false;
}

