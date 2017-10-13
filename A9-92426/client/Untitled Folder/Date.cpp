#include "Date.h"

Date::Date()
{
	year =0 ;
	month =0 ;
	day = 0 ;
}

Date::Date(string date)
{
	year = 0;
	month = 0;
	day = 0;
	char c;
	string temp ="";
	for (int i=0 ; i< date.size(); i++)
	{
		c = date[i];
		if(c != '/')		
			temp += c;
		if(c == '/' || i == date.size()-1)
		{
			if (year == 0)
			{
				year = atoi(temp.c_str());
				temp ="";
			}
			else if (month == 0)
			{
				month = atoi(temp.c_str());
				temp = "";
			}
			else if (day == 0)
			{
				day = atoi(temp.c_str());
				temp ="";
			}
		}
	}	
}

string Date::convert()
{
	string temp ;
	stringstream ss;
	
	ss<< year << '/' << month <<'/' << day ;

	temp = ss.str();
	return temp;

}

Date& Date::operator=(const Date& bd)
{
	year = bd.get_year();
	month = bd.get_month();
	day = bd.get_day();
	return *this;
}

ostream& operator<<(ostream& output,Date dd)
{
	output << dd.year <<'/'<< dd.month <<'/'<<dd.day ;
	return output;
}

void Date::get_now()
{
	time_t t = time(0);
	tm* now = localtime( & t );//a pointer to a struct named tm
	year = now->tm_year + 1900;
	month = now->tm_mon;
	day = now ->tm_mday;
}