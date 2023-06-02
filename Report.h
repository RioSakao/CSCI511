#ifndef REPORT_H
#define REPORT_H
#include "Time.h"
#include "Date.h"
#include <string>
using namespace std;

class Report {
  private:
    Date rep_date;
    Time rep_time;
    string rep_desc;
  public:
    Report(const Report& arg);

    //TO DO: constructor that takes 6 arguments
    Report(int day, int month, int year, int hour, int minute, string description );

    void display() const; //you write the definition in Report.cpp?
};
#endif
