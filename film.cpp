#include "film.h"
#include <iomanip>
#include <iostream>

Film::Film(const string &s1, const string &s2, const string &s3,
                            const string &s4, const string &s5, const string &s6)
        :Media::Media(s1,s2,s3,s5),director(s4),year(s6)
{
}

void Film::display() const {

        cout << "==========================" << endl;
        cout << "========== FILM ==========" << endl;
        cout << "==========================" << endl;
        cout << left;
        cout << setw(22) << "call_number: "  << call_number << endl;
        cout << setw(22) << "title: " <<  title << endl;
        cout << setw(22) << "subjects: "  << subjects << endl;
        cout << setw(22) << "director: "  << director << endl;
        cout << setw(22) << "notes: " <<  notes << endl;
        cout << setw(22) << "year: " <<  year << endl;



}
bool Film::compare_other(const string& s) const {
        int found_dir = s.find(director);
        int found_ye = s.find(year);
        if(found_dir!=string::npos || found_ye!=string::npos ) {
                return true;
        }
        return false;
}
