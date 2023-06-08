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
        cout << "============================" << endl;
        cout << "=========== BOOK ===========" << endl;
        cout << "============================" << endl;
        cout << left;
        cout << setw(20) << "call number: " << setw(20) << call_number << endl;
        cout << setw(20) << "title: " << setw(20) << title << endl;
        cout << setw(20) << "subjects: " << setw(20) << subjects << endl;
        cout << setw(20) << "author: " << setw(20) << author << endl;
        cout << setw(20) << "description: " << setw(20) << description << endl;
        cout << setw(20) << "publisher: " << setw(20) << publisher << endl;
        cout << setw(20) <<"city: " << setw(20) << city << endl;
        cout << setw(20) << "year: " << setw(20) << year << endl;
        cout << setw(20) << "series: " << setw(20) << series << endl;
        cout << setw(20) << "notes: " << setw(20) << notes << endl;

}


bool Book::compare_other(const string& s) const{
            if(s==author || s==description || s==publisher || s==city || s==year || s==series) {
                    return true;
            }
            return false;
}
