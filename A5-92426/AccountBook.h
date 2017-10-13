#ifndef Acc_H
#define Acc_H

#include <vector> 
#include <iostream>
#include <string>
#include "Contact.h"

using namespace std;

class AccountBook
{
	friend ostream& operator<<(ostream& out,const AccountBook& Abook);
public:
	AccountBook  operator+(const AccountBook& Abook) const;
	AccountBook& operator+=(const Contact& c);
	AccountBook& operator%=(double percent);
	AccountBook  operator&(const AccountBook& Abook) const;
	AccountBook& operator-=(string key);	
	AccountBook& operator++();	
	Contact&     operator[](string);
	bool         operator==(const AccountBook& Abook) const ;				
	bool         operator<(const AccountBook& Abook) const;
	bool         operator<=(const AccountBook& Abook) const ; //check for meaning 
	void set_contacts(vector<Contact> contact_list);
	void set_owed_AB(int i,double owed);
	void set_emails_AB(int j,vector<string> emails);
	void set_phonenums_AB(int k,vector<int> phone_nums);
	int size();
	void clear();
	vector<Contact> get_contact() const { return contacts;}
private:
	vector<Contact> contacts;
};
#endif
