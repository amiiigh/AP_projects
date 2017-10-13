#ifndef con_H
#define con_H

#include <vector> 
#include <iostream>
#include <string>

using namespace std;

class Contact
{
	friend ostream& operator<<(ostream& out,const Contact& c);
public:
	Contact (string _name, vector<int> _phone_num, vector<string> _email, double _owed);
	void set_name(string name);
	void set_phone_nums(vector<int> phone_num);
	void set_emails(vector<string> email);
	void set_owed_value(double owed);
	string get_name() const { return name;}
	vector<int> get_phone_nums() const {return phone_num;}
	vector<string> get_emails() const { return email;}
	double get_owed() const {return owed;}
	bool operator==(const  Contact& c) const ;
private:
	string name; 
	vector<int> phone_num;
	vector<string> email;
	double owed;
};
#endif
