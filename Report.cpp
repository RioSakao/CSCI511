#include "Report.h"
#include<iostream>
#include<iomanip>

//copy constructor
Report::Report(const Report& arg)
  : rep_date(arg.rep_date), rep_time(arg.rep_time), rep_desc(arg.rep_desc)
{
  cerr << "Report: Copy ctor" << endl;
}

// constructor with 6 arguments to create a report
Report::Report(int day, int month, int year, int hour, int minute, string description)
    :rep_time(hour, minute), rep_date(day, month, year), rep_desc(description)
{
}

// write Report's display function
void Report::display() const
{
        cout << rep_desc << endl;
        rep_time.display();
        rep_date.display();
}
