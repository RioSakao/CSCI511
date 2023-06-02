#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Book {
        string call_number;
        string title;
        string subjects;
        string author;
        string description;
        string publisher;
        string city;
        string year;
        string series;
        string notes;
public:
        void set_callnumber(string s);
        void set_title(string s);
        void set_subjects(string s);
        void set_author(string s);
        void set_description(string s);
        void set_publisher(string s);
        void set_city(string s);
        void set_year(string s);
        void set_series(string s);
        void set_notes(string s);

        string get_callnumber() const;
        string get_title() const;
        string get_subjects() const;
        string get_author() const;
        string get_description() const;
        string get_publisher() const;
        string get_city() const;
        string get_year() const;
        string get_series() const;
        string get_notes() const;
        
        void disp();
};
#endif
