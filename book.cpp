#include "book.h"
#include <iomanip>
#include <iostream>

Book::Book(const string &s1, const string &s2, const string &s3,
                            const string &s4, const string &s5, const string &s6,
                            const string &s7, const string &s8, const string &s9,
                            const string &s10)
            :Media::Media(s1,s2,s3,s10), author(s4), description(s5), publisher(s6), city(s7), year(s8), series(s9)
{
}

void Book::display() const{
        cout << "==========================" << endl;
        cout << "========== BOOK ==========" << endl;
        cout << "==========================" << endl;
        cout << left;
        cout << setw(22) << "call_number: " << call_number << endl;
        cout << setw(22) << "title: " <<  title << endl;
        cout << setw(22) << "subjects: " <<  subjects << endl;
        cout << setw(22) << "author: " <<  author << endl;
        cout << setw(22) << "description: " <<  description << endl;
        cout << setw(22) << "publisher: " <<  publisher << endl;
        cout << setw(22) << "city: " <<  city << endl;
        cout << setw(22) << "year: " <<  year << endl;
        cout << setw(22) << "series: " <<  series << endl;
        cout << setw(22) << "notes: " <<  notes << endl;

}


bool Book::compare_other(const string& s) const{
        int found_a = s.find(author);
        int found_des = s.find(description);
        int found_pub = s.find(publisher);
        int found_ci = s.find(city);
        int found_ye = s.find(year);
        int found_se = s.find(series);
        if(found_a!=string::npos || found_des!=string::npos ||found_pub!=string::npos 
                        ||found_ci!=string::npos || found_ye!=string::npos || found_se!=string::npos) {
                return true;
        }
        return false;
}
