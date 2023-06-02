

/* @ read-in book.txt
 * @ assign each item into an class object and save them into an vector<class>
 * @ iterate through the vector and nicely print out the result
 * */

#include "book.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


void Book::set_callnumber(string s) {
        if ( s.length() > 64 )
                throw invalid_argument("call number must be less than 64 characters.");
                call_number = s;
}
void Book::set_title(string s) {title = s;}
void Book::set_subjects(string s) {subjects = s;}
void Book::set_author(string s) {author = s;}
void Book::set_description(string s) {description = s;}
void Book::set_publisher(string s) {publisher = s;}
void Book::set_city(string s) {city = s;}
void Book::set_year(string s) {year = s;}
void Book::set_series(string s) {series = s;}
void Book::set_notes(string s) {notes = s;}
string Book::get_callnumber() const {return call_number;}
string Book::get_title() const {return title;}
string Book::get_subjects() const {return subjects;}
string Book::get_author() const {return author;}
string Book::get_description() const {return description;}
string Book::get_publisher() const {return publisher;}
string Book::get_city() const {return city;}
string Book::get_year() const {return year;}
string Book::get_series() const {return series;}
string Book::get_notes() const {return notes;}


void Book::disp(){
        cout << endl;
        cout << left;
        cout << setw(20) << "call number: " << setw(20) << this->get_callnumber() << endl;
        cout << setw(20) << "title: " << setw(20) << this->get_title() << endl;
        cout << setw(20) << "subjects: " << setw(20) << this->get_subjects() << endl;
        cout << setw(20) << "author: " << setw(20) <<this->get_author() << endl;
        cout << setw(20) << "description: " << setw(20) << this->get_description() << endl;
        cout << setw(20) << "publisher: " << setw(20) << this->get_publisher() << endl;
        cout << setw(20) <<"city: " << setw(20) << this->get_city() << endl;
        cout << setw(20) << "year: " << setw(20) << this->get_year() << endl;
        cout << setw(20) << "series: " << setw(20) << this->get_series() << endl;
        cout << setw(20) << "notes: " << setw(20) << this->get_notes() << endl;
}

int main() {

        ifstream target("01/book.txt");
        string line, token;
        vector<Book> myvector; 
        Book book;
        while ( getline(target, line) ) {
                int count = 0;
                istringstream iss(line);
                while(getline(iss, token, '|')) {
                        count++;
                        switch(count) {
                                case 1:
                                        book.set_callnumber(token);
                                        break;
                                case 2:
                                        book.set_title(token);
                                        break;
                                case 3:
                                        book.set_subjects(token);
                                        break;
                                case 4:
                                        book.set_author(token);
                                        break; 
                                case 5:
                                        book.set_description(token);
                                        break;
                                case 6:
                                        book.set_publisher(token);
                                        break;
                                case 7:
                                        book.set_city(token);
                                        break;
                                case 8:
                                        book.set_year(token);
                                        break;
                                case 9:
                                        book.set_series(token);
                                        break;
                                case 10:
                                        book.set_notes(token);
                                        break;
                        }//switch
                }//while
                myvector.push_back(book);
        }//while
        cout << "============================" << endl;
        cout << "=========== BOOK ===========" << endl; 
        cout << "============================";
        for ( unsigned i = 0; i < myvector.size(); i++ ) {
                myvector[i].disp();
        }//for

        return 0;
}

