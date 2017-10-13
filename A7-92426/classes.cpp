#include "classes.h"
#include <fstream>
#include <sstream>
#include <cstdlib>


Flight::Flight()
{}
Road::Road()
{}

bool Road::isAvailable(string _origin,string time,const vector<int>& passengers)
{
	if (origin == _origin)
		return true;
	else 
		return false;
}

double Road::getFare(const vector<int>& passengers)
{
	int infants=0;
	int children=0;
	int adults=0;
	double price;
	int num_of_cars;
	for (int i=0 ; i< passengers.size(); i++)
	{
		if (passengers[i] > 12)
		{
			adults++;
		}
		else if (passengers[i] <=12 && passengers[i]>2)
		{
			children++;
		}
		else if (passengers[i] <=2)
		{
			infants++;
		}
	}
	if ( (adults + children)%4 != 0)
	{
		num_of_cars = (adults + children)/4 + 1 ;
	}
	else 
		num_of_cars = (adults + children)/4 ;
	if (distance <= 50 )
	{
		price = num_of_cars * 400000;
	}
	else
		price = num_of_cars * (400000 + (distance - 50) * 6000);
	cout << "infants("<<infants<<") "<<"children("<<children<<") adults("<<adults<<')'<<endl;
	cout <<'\t' <<num_of_cars << " car(s) required"<<endl;
	cout <<'\t' << fixed <<"total: "<< price<< endl;
	return price;
}

int Road::getDuration()
{
	return ((double)distance / speed_limit) * 60;
}

bool Flight::isAvailable(string _origin,string time,const vector<int>& passengers)
{
	Time t(time);
	// cout << time << endl;
	// cout << "input time : "<<t.get_hour()<<':'<< t.get_min() <<endl;
	// cout << "start time : "<< start_time.get_hour() << ':'<<start_time.get_min()<<endl;
	// cout << "dif is : "<< start_time - t<< endl;
	if (origin == _origin && start_time - t >=30 && capacity >= passengers.size())
		return true;
	else 
		return false;
}

double Flight::getFare(const vector<int>& passengers)
{
	int infants=0;
	int children=0;
	int adults=0;
	double price;
	for (int i=0 ; i< passengers.size(); i++)
	{
		if (passengers[i] > 12)
		{
			adults++;
		}
		else if (passengers[i] <=12 && passengers[i]>2)
		{
			children++;
		}
		else if (passengers[i] <=2)
		{
			infants++;
		}
	}
	price = infants * (fee * 0.1) + children * (fee * 0.5) + adults * fee ;
	cout << "infants("<<infants<<") "<<"children("<<children<<") adults("<<adults<<')'<<endl;
	cout <<'\t' <<infants << " * "<< fee*0.1 << endl;
	cout << '\t' <<children << " * "<< fee*0.5<< endl;
	cout << '\t' <<adults << " * "<< fee << endl;
	cout << '\t' <<fixed <<"total: "<< price << endl;
	return price;
}

int Flight::getDuration()
{
	return end_time - start_time;
}
void Flight::set_reference(string _ref)
{
	flight_reference = _ref;
}

void Flight::set_origin(string _orig)
{
	origin = _orig;
}

void Flight::set_dest(string _des)
{
	dest = _des;
}

// void Flight::set_st_time(time)
// {

// }

// void Flight::set_en_time(time)
// {

// }

void Flight::set_fee(int _fee)
{
	fee = _fee;
}

void Flight::set_capacity(int _capacity)
{
	capacity = _capacity;
}

void Road::set_reference(string _ref)
{	
	road_reference = _ref;
}

void Road::set_origin(string _orig)
{
	origin = _orig;
}

void Road::set_dest(string _des)
{
	dest = _des;
}

void Road::set_distance(int _dis)
{
	distance = _dis;
}

void Road::set_speed_limit(int _speed)
{	
	speed_limit = _speed;
}

Time::Time(string _time)
{
	string hr;
	string minute;
	if (_time[0] != '0')
	{
		hr = hr + _time[0] + _time[1];	
	}
	else
		hr = hr + _time[1];
	if (_time[3] != '0')
		minute = minute + _time[3] + _time[4] ;
	else
		minute = minute + _time[4];
	min = atoi(minute.c_str());
	hour = atoi(hr.c_str());
	
}

string Time::convert()
{
	stringstream ss;
	string ti;
	if (hour < 10)
		ss << '0'<<hour;
	else 
		ss << hour;
	if (min < 10)
		ss << ':'<<'0'<<min;
	else
		ss<< ':'<<min;
	ss >> ti ;
	return ti;
}

Time::Time()
{
	hour = 0;
	min = 0;
}

Time Time::operator=(const Time& o_time)
{
	// Time _new;
	// _new.set_min(o_time.get_min());
	// _new.set_hour(o_time.get_hour());
	min = o_time.get_min();
	hour = o_time.get_hour();
	return *this;
}
void Time::set_min(int _min)
{
	min= _min;
}
void Time::set_hour(int _hour)
{
	hour = _hour;
}


Time Time:: operator+(int minute)
{
	min = min + minute%60;
	hour = hour + minute/60;
	int temp;
	if (min > 60)
	{
		min = min -60;
		hour++;
	}
	return *this;
}

int Time:: operator-( Time& second)
{
	return (hour - second.get_hour())*60 + min - second.get_min();
}

void Flight::set_st_time(string st_time)
{
	Time st(st_time);
	start_time = st;
}

void Flight::set_en_time(string en_time)
{
	Time en(en_time);
	end_time = en;
}

void Input::read_input()
{
	string line;
	cin >> line;
	string temp;
	int i,j,k,m;
	char c;
	bool flag = false;

	for(i = 0; line[i] != '#' ; i++)
	{
		c = line[i];
		temp = temp + c;
	}
	origin = temp;
	temp.clear();


	for(j = i+1; line[j] != '#'; j++)
	{
		c = line[j];
		temp = temp	+ c;
	}
	destination = temp;
	temp.clear();


	for(k = j+1; line[k] != '#'; k++)
	{
		c = line[k];
		temp = temp	+ c;
	}
	Time de(temp);
	departure_time = de;
	temp.clear();

	for (m = k+1; m < line.size(); m++)
	{
		c = line[m];
		if (line[m] == '(')
		{
			flag = true;
			continue;
		}
		if (flag == true)
		{
			while (true)
			{
				c = line[m];
				if (line[m]==',' || m>line.size())	
					break;
				temp = temp +c;
				m++;
				//cout << temp << endl;
			}
			passengers.push_back(atoi(temp.c_str()));
			temp.clear();
		}
	}
}

void Input::show_inputs()
{
	cout << "showing input values: "<<endl;
	cout << "origin : " << origin<<endl;
	cout << "destination : " << destination<< endl;
	for (int i=0 ; i< passengers.size(); i++)
	{
		cout << "passengers " << i+1 << " age is : "<< passengers[i] << endl;	
	}
	
}

vector<Transportation*> Transportation_list::read_file()
{
	fstream input;
	string line;
	input.open("transportation.txt");
	char c;
	Flight * fl;
	Road * ro;
	string temp;
	int i,j,k,m,l,n,p; //for loops :D
	stringstream ss;
	vector<Transportation*> list ;

	int fee,cap,dis,speed;

	while ( getline (input,line) )
	{

		ss.str("");
		temp.clear();
		if (line == "<flights>")
		{
			fl = new Flight;
			getline (input,line);

			// get the ref

			for(i = 0; line[i] != '#' ; i++)
			{
				c = line[i];
				temp = temp + c;
			}
			fl->set_reference(temp);


			temp.clear();


			// get origin

			for(j = i+1; line[j] != '#'; j++)
			{
				c = line[j];
				temp = temp	+ c;
			}
			fl->set_origin(temp);


			temp.clear();

			//get des

			for(k = j+1; line[k] != '#'; k++)
			{
				c = line[k];
				temp = temp	+ c;
			}
			fl->set_dest(temp);


			temp.clear();

			//get st_time

			for(m = k+1; line[m] != '#'; m++)
			{
				c = line[m];
				temp = temp	+ c;
			}
			fl->set_st_time(temp);
			//time(temp);
			temp.clear();

			//get en_time

			for(n = m+1; line[n] != '#'; n++)
			{
				c = line[n];
				temp = temp	+ c;
			}
			fl->set_en_time(temp);
			//time(temp);
			temp.clear();


			//get fee and capa

			for(p = n+1; line[p] != '#'; p++)
			{
				c = line[p];
				temp = temp	+ c;
			}
			fee = atoi(temp.c_str());
			fl->set_fee(fee);
			temp.clear();

			for(l = p+1; l<line.size(); l++)
			{
				c = line[l];
				temp = temp	+ c;
			}
			cap = atoi(temp.c_str());
			fl->set_capacity(cap);
			temp.clear();
			list.push_back(fl);
		}
		else if (line == "<roads>")
		{
			getline (input,line);

			ro = new Road;
			// get the ref

			for(i = 0; line[i] != '#' ; i++)
			{
				c = line[i];
				temp = temp + c;
			}
			ro->set_reference(temp);
			
			temp.clear();

			// get origin

			for(j = i+1; line[j] != '#'; j++)
			{
				c = line[j];
				temp = temp	+ c;
			}
			ro->set_origin(temp);
			temp.clear();

			//get des

			for(m = j+1; line[m] != '#'; m++)
			{
				c = line[m];
				temp = temp	+ c;
			}
			ro->set_dest(temp);
			temp.clear();

			//get distance

			for(l = m+1; line[l] != 'K'; l++)
			{
				c = line[l];
				temp = temp	+ c;
			}

			dis = atoi(temp.c_str());
			// ss << temp ; 
			// ss >> dis ;
			// cout << dis << endl;
			// ss.str("");
			ro->set_distance(dis);
			temp.clear();

			//get speed limit

			for(n = l+3; line[n] != 'K'; n++)
			{
				c = line[n];
				temp = temp	+ c;
			}

			//get fee and capa
			speed = atoi(temp.c_str());
			// ss << temp ;
			// ss >> speed;
			// cout << speed <<endl;
			ro->set_speed_limit(speed);
			// temp.clear();
			list.push_back(ro);
		}
		getline (input,line);
	}
	input.close();

	return list;
}