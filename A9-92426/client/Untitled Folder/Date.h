#ifndef DATE_H_
#define	DATE_H_

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

class Date
{
public:
	friend ostream& operator<<(ostream& out,Date dd);
	Date();
	Date(string date);
	string convert();
	Date& operator=(const Date& bd);
	
	int get_year() const{return year;}
	int get_month() const{return month;}
	int get_day() const{return day;}
	void get_now();
	// ~Date();
private:
	int year;
	int month;
	int day;
	
};

#endif