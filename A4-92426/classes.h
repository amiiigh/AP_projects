#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream> //file 

using namespace std;

//fstream input;


class Food
{
public:
	Food(int id,string name,int price);
	void set_food(int id,string name,int price);
	string get_food_name (){return food_name;}
	int get_food_id () {return food_id;}
	int get_food_price () {return food_price;}
private:
	string food_name;
	int food_id;
	int food_price;
};

class Orderlist
{
public:
	Orderlist(int food_id,int num_of_food,bool comment);
	int get_order_id() { return food_id;}
	int get_num_of_order () {return num_of_food;}
	bool get_if_comment() {return comment;}
private:
	int num_of_food;
	bool comment;
	int food_id;	
};
class Time
{
public:
	Time(int _year,int _month,int _day,int _hour,int _min);
	void set_time(int h,int m);
	void set_date(int year,int month,int day);
	void print_T_D();
private:
	int hour;
	int min;
	int year;
	int day;
	int month;
};
Orderlist::Orderlist(int _food_id,int _num_of_food,bool _comment)
{
	food_id=_food_id;
	num_of_food=_num_of_food;
	comment=_comment;
}
void Time::print_T_D()
{
	cout << year<<'-'<<month<<'-'<< day <<'\t'<< hour <<':'<<min <<endl;
}
void Time::set_time(int h,int m)
{
	hour=h;
	min=m;
}
void Time::set_date(int __year,int __month,int __day)
{
	year=__year;
	month=__month;
	day=__day;
}
Time::Time(int _year,int _month,int _day,int _hour,int _min)
{
	set_time(_hour,_min);
	set_date(_year,_month,_day);
}
Food::Food(int id,string food_name,int food_price)
{
	set_food(id,food_name,food_price);
}
void Food::set_food(int id,string name,int price)
{
	//validate entered information 
	food_id=id;
	food_name=name;
	food_price=price;
}