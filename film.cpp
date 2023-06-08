#include "film.h"
#include <iomanip>
#include <iostream>

Film::Film(const string &s1, const string &s2, const string &s3,
                            const string &s4, const string &s5, const string &s6)
        :Media::Media(s1,s2,s3,s5),director(s4),year(s6)
{
}

void Film::display() const {

        cout << "============================" << endl;
        cout << "=========== FILM ===========" << endl;
        cout << "============================" << endl;
        cout << left;
        cout << setw(20) << "call number: " << setw(20) << call_number << endl;
        cout << setw(20) << "title: " << setw(20) << title << endl;
        cout << setw(20) << "subjects: " << setw(20) << subjects << endl;
        cout << setw(20) << "director: " << setw(20) << director << endl;
        cout << setw(20) << "notes: " << setw(20) << notes << endl;
        cout << setw(20) << "year: " << setw(20) << year << endl;



}
bool Film::compare_other(const string& s) const {
        if(s==director || s==year) {
                return true;
        }
        return false;
}
