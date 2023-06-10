#include "video.h"
#include <iomanip>
#include <iostream>

Video::Video(const string &s1, const string &s2, const string &s3,
                            const string &s4, const string &s5, const string &s6,
                            const string &s7, const string &s8)
        :Media::Media(s1,s2,s3,s6), description(s4), distributor(s5), series(s7), label(s8)
{
}

void Video::display() const{

        cout << "==========================" << endl;
        cout << "========== VIDEO =========" << endl;
        cout << "==========================" << endl;
        cout << left;
        cout << setw(22) << "call_number: " << call_number << endl;
        cout << setw(22) << "title: " <<  title << endl;
        cout << setw(22) << "subjects: "  << subjects << endl;
        cout << setw(22) << "description: " << description << endl;
        cout << setw(22) << "distributor: " << distributor << endl;
        cout << setw(22) << "notes: " <<  notes << endl;
        cout << setw(22) << "series: " <<  series << endl;
        cout << setw(22) << "label: " << label << endl;

}


bool Video::compare_other(const string& s) const{
        int found_dis = s.find(distributor);
        int found_des = s.find(description);
        int found_ser = s.find(series);
        int found_lab = s.find(label);
        if(found_dis!=string::npos || found_des!=string::npos || found_ser!=string::npos  || found_lab!=string::npos ) {
                return true;
        }
        return false;
}

