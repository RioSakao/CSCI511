#include "periodical.h"
#include <iomanip>
#include <iostream>

Periodical::Periodical(const string &s1, const string &s2, const string &s3,
                            const string &s4, const string &s5, const string &s6,
                            const string &s7, const string &s8, const string &s9,
                           const string &s10, const string &s11, const string &s12)
        :Media::Media(s1,s2,s3,s9), author(s4), description(s5), publisher(s6), publishing_history(s7), series(s8),
         related_title(s10), other_forms_of_title(s11), govt_doc_number(s12)
{
}

void Periodical::display() const {

        cout << "==========================" << endl;
        cout << "======= PERIODICAL =======" << endl;
        cout << "==========================" << endl;
        cout << left;
        cout << setw(22) << "call_number: " << call_number << endl;
        cout << setw(22) << "title: " <<  title << endl;
        cout << setw(22) << "subjects: " <<  subjects << endl;
        cout << setw(22) << "author: " <<  author << endl;
        cout << setw(22) << "description: " <<  description << endl;
        cout << setw(22) << "publisher: " << publisher << endl;
        cout << setw(22) << "publishing_history: " <<  publishing_history << endl;
        cout << setw(22) << "series: " <<  series << endl;
        cout << setw(22) << "notes: " <<  notes << endl;
        cout << setw(22) << "related_titles: " <<  related_title << endl;
        cout << setw(22) << "other_forms_of_title: " << other_forms_of_title << endl;
        cout << setw(22) << "govt_doc_number: " <<  govt_doc_number << endl;
}

bool Periodical::compare_other(const string& s) const {
        int found_a = s.find(author);
        int found_des = s.find(description);
        int found_pub = s.find(publisher);
        int found_ph = s.find(publishing_history);
        int found_se = s.find(series);
        int found_rt = s.find(related_title);
        int found_oft = s.find(other_forms_of_title);
        int found_gdn = s.find(govt_doc_number);
        if(found_a!=string::npos ||found_des!=string::npos ||found_pub!=string::npos 
                        || found_ph!=string::npos || found_se!=string::npos 
                        || found_rt!=string::npos || found_oft!=string::npos || found_gdn!=string::npos){
                return true;
        }
        return false;
}
