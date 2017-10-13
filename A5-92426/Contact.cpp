#include "Contact.h"
Contact::Contact(string _name, vector<int> _phone_num, vector<string> _email, double _owed)
{
	set_name(_name);
	set_phone_nums(_phone_num);
	set_emails(_email);
	set_owed_value(_owed);
}

void Contact::set_emails(vector<string> _email)
{
	email = _email;
}

void Contact::set_name(string _name)
{
	name = _name;
}

void Contact::set_owed_value(double _owed)
{
	owed = _owed;
}

void Contact::set_phone_nums(vector<int> _phone_num)
{
	phone_num = _phone_num;
}

bool Contact::operator==(const  Contact& c) const 
{
	if (name == c.get_name())
		return true;
	else 
		return false;
}

ostream& operator<<(ostream& out,const Contact& c)
{
	out << c.name << endl;
	out << "Phone Num(s): ";
	for (int j=0 ; j<c.phone_num.size() ; j++)
	{
		out << c.phone_num[j];
		if (c.phone_num.size()-1-j >0)
			out << " - " ;
	}
	out << endl;		
	out << "Email(s): ";
	for (int k=0 ; k<c.email.size() ; k++)
	{
		out << c.email[k];
		if (c.email.size()-1-k > 0)
			out << " - " ;	
	}
	out << endl;
	out << "Owed money: " << c.owed ;
	return out;
}