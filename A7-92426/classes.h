#ifndef CLASSES_H_
#define CLASSES_H_
#include <iostream>
#include <vector>
using namespace std;

class Time
{
public:
	Time(string _time);
	Time();
	void set_min(int _min);
	void set_hour(int _hour);
	Time operator=(const Time& o_time);
	int operator-(Time& second);
	Time operator +(int minute);
	int get_min()const{return min;}
	int get_hour()const{return hour;}
	string convert();
private:
	int hour;
	int min;
};

class Transportation 
{
public:
	virtual bool isAvailable(string _origin,string time,const vector<int>& passengers) = 0;
	virtual double getFare(const vector<int>& passengers) = 0;
	virtual int getDuration() = 0;

	virtual string get_ref() = 0;
	virtual string get_origin() = 0;
	virtual string get_dest() = 0;
	virtual int get_fee(){}
	virtual int get_capacity(){}
	virtual int get_dis(){}
	virtual int get_speed_limit(){}
	virtual Time get_st_time(){}
	virtual Time get_en_time(){}	
};

class Flight
:public Transportation
{
public:
	Flight();
	void set_reference(string _ref);
	void set_origin(string _orig);
	void set_dest(string _des);
	void set_st_time(string st_time);
	void set_en_time(string en_time);
	void set_fee(int _fee);
	void set_capacity(int _capacity);
	string get_ref(){return flight_reference;}
	string get_origin(){return origin;}
	string get_dest(){return dest;}
	int get_fee(){return fee;}
	int get_capacity(){return capacity;}
	Time get_st_time(){/*cout << start_time.get_hour() <<':'<< start_time.get_min() << endl;*/
	return start_time;}
	Time get_en_time(){/*cout << end_time.get_hour() << ':'<< end_time.get_min() << endl;*/
	return end_time;}	
	virtual bool isAvailable(string _origin,string time,const vector<int>& passengers);
	virtual double getFare(const vector<int>& passengers);
	virtual int getDuration();
private:
	string flight_reference;
	string origin;
	string dest;
	Time start_time;
	Time end_time;
	int fee;
	int capacity;

};

class Road
:public Transportation
{
public:
	Road();
	void set_reference(string _ref);
	void set_origin(string _orig);
	void set_dest(string _des);
	void set_distance(int _dis);
	void set_speed_limit(int _speed);
	string get_ref(){return road_reference;}
	string get_origin(){return origin;}
	string get_dest(){return dest;}
	int get_dis(){return distance;}
	int get_speed_limit(){return speed_limit;}

	virtual bool isAvailable(string _origin,string time,const vector<int>& passengers);
	virtual double getFare(const vector<int>& passengers);
	virtual int getDuration();
private:
	string road_reference;
	string origin;
	string dest;
	int distance;
	int speed_limit;

};

class Transportation_list
{
public:
	// Transportation_list(string F_name);
	vector<Transportation*> read_file();	
private:
	//string file_name;
	vector<Transportation*>trans_list;
};

class Input
{
public:
	void read_input();
	void show_inputs();
	string get_origin(){return origin;}
	string get_dest(){return destination;}
	vector<int> get_passengers(){return passengers;}
	Time get_time(){return departure_time;}
private:
	string origin;
	string destination;
	Time departure_time;
	vector<int>passengers;
	int num_of_passengers;
};



#endif
