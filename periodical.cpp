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

        cout << "============================" << endl;
        cout << "========= PERIODIC =========" << endl;
        cout << "============================" << endl;
        cout << left;
        cout << setw(20) << "call number: " << setw(20) << call_number << endl;
        cout << setw(20) << "title: " << setw(20) << title << endl;
        cout << setw(20) << "subjects: " << setw(20) << subjects << endl;
        cout << setw(20) << "author: " << setw(20) << author << endl;
        cout << setw(20) << "description: " << setw(20) << description << endl;
        cout << setw(20) << "publisher: " << setw(20) << publisher << endl;
        cout << setw(20) << "publishing history: " << setw(20) << publishing_history << endl;
        cout << setw(20) << "series: " << setw(20) << series << endl;
        cout << setw(20) << "notes: " << setw(20) << notes << endl;
        cout << setw(20) << "related title: " << setw(20) << related_title << endl;
        cout << setw(20) << "other forms of title: " << setw(20) << other_forms_of_title << endl;
        cout << setw(20) << "govt doc number: " << setw(20) << govt_doc_number << endl;
}

bool Periodical::compare_other(const string& s) const {
        if(s==author || s==description || s==publisher || s==publishing_history || s==series 
                        || s==related_title || s==other_forms_of_title || s==govt_doc_number){
                return true;
        }
        return false;
}
