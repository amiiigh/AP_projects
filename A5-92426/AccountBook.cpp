#include "AccountBook.h"

void sort_contact (AccountBook& A)
{
	vector<Contact> new_list;
	int n=0;
	bool flag;
	for (int j=0 ; j< A.get_contact().size(); j++)
	{
		for (int i=0 ; i < A.get_contact().size()-1; i++ )
		{
			while ((int)A.get_contact()[i].get_name()[n] == (int)A.get_contact()[i+1].get_name()[n])
			{
				n++;
			}
			if 	((int)A.get_contact()[i].get_name()[n]<91 && 
					 (int)A.get_contact()[i].get_name()[n]>64 && 
					 (int)A.get_contact()[i+1].get_name()[n]>96 && 
					 (int)A.get_contact()[i+1].get_name()[n]<123 )
				{
					//cout << "in "<<endl;
					new_list = A.get_contact();
					Contact C = new_list[i];
					new_list[i] = new_list[i+1];
					new_list[i+1] = C;
					A.set_contacts(new_list);
					flag=true;
				}
			else
				flag=false;
			if ((int)A.get_contact()[i].get_name()[n] < (int)A.get_contact()[i+1].get_name()[n] && flag==false)
			{
				new_list = A.get_contact();
				Contact C = new_list[i];
				new_list[i] = new_list[i+1];
				new_list[i+1] = C;
				A.set_contacts(new_list);
			}
			n=0;
		}
	}
}

void sort_email (AccountBook& A)
{
	vector<string> new_list;
	int n=0;
	bool flag;
	for (int j=0 ; j< A.get_contact().size(); j++)
	{
		for (int k=0 ; k< A.get_contact()[j].get_emails().size(); k++)
		{
			for (int i=0 ; i < A.get_contact()[j].get_emails().size() -1; i++)
			{
				while ((int)A.get_contact()[j].get_emails()[i][n] == (int)A.get_contact()[j].get_emails()[i+1][n])
				{
					n++;
				}

				if 	((int)A.get_contact()[j].get_emails()[i][n]<91 && 
					 (int)A.get_contact()[j].get_emails()[i][n]>64 && 
					 (int)A.get_contact()[j].get_emails()[i+1][n]>96 && 
					 (int)A.get_contact()[j].get_emails()[i+1][n]<123 )
				{
					new_list = A.get_contact()[j].get_emails();
					string C = new_list[i];
					new_list[i] = new_list[i+1];
					new_list[i+1] = C;
					A.set_emails_AB(j,new_list);
					flag=true;
				}
				else
					flag=false;
				if ((int)A.get_contact()[j].get_emails()[i][n] < (int)A.get_contact()[j].get_emails()[i+1][n] && flag ==false)
				{
					new_list = A.get_contact()[j].get_emails();
					string C = new_list[i];
					new_list[i] = new_list[i+1];
					new_list[i+1] = C;
					A.set_emails_AB(j,new_list);
				}
				n=0;
			}
		}
	}
}

void sort_phone_num (AccountBook& A)
{
	vector<int> new_list;
	for (int j=0 ; j< A.get_contact().size(); j++)
	{
		for (int k=0 ; k< A.get_contact()[j].get_phone_nums().size(); k++)
		{
			for (int i=0 ; i < A.get_contact()[j].get_phone_nums().size() -1; i++)
			{
				if (A.get_contact()[j].get_phone_nums()[i] > (int)A.get_contact()[j].get_phone_nums()[i+1])
				{
					new_list = A.get_contact()[j].get_phone_nums();
					int C = new_list[i];
					new_list[i] = new_list[i+1];
					new_list[i+1] = C;
					A.set_phonenums_AB(j,new_list);
				}
			}
		}
	}
}

vector<string> combine_emails(const Contact& A,const Contact& B)
{
	vector<string> emails ;
	emails = A.get_emails();
	bool flag=false; 	

	for (int j=0 ; j< B.get_emails().size(); j++)
	{
		for (int i=0; i< emails.size(); i++)
		{
			if (emails[i] == B.get_emails()[j])
			{
				flag= true;
				break;
			}
		}	
		if (flag == false)
		{
			emails.push_back(B.get_emails()[j]);
		}
		flag=false;
	}

	return emails;
}

vector<int> combine_phone_nums(const Contact& A,const Contact& B)
{
	vector<int> phone_nums ;
	phone_nums = A.get_phone_nums();
	bool flag=false;

	for (int j=0 ; j< B.get_phone_nums().size(); j++)
	{
		for (int i=0; i< phone_nums.size(); i++)
		{
			if (phone_nums[i] == B.get_phone_nums()[j])
			{
				flag= true;
				break;
			}
		}	
		if (flag == false)
		{
			phone_nums.push_back(B.get_phone_nums()[j]);
		}
		flag=false;
	}

	return phone_nums;
}

bool check_emails(Contact A,Contact B)
{
	bool flag=false;
	if (A.get_emails().size() == 0 || B.get_emails().size() == 0)
		return false;
	for (int i=0 ; i< A.get_emails().size() ; i++ )	
	{
		for (int j=0 ; j< B.get_emails().size() ; j++)
		{
			if (A.get_emails()[i] == B.get_emails()[j])
			{
				flag=true;
				break;
			}
		}
		if (flag == false)
		{
			return false;
		}
		else
			flag==false;
	}
	return true;
}

bool check_phone_nums(Contact A,Contact B)
{
	bool flag=false;
	if (A.get_phone_nums().size() == 0 ||  B.get_phone_nums().size() == 0)
		return false;
	for (int i=0 ; i< A.get_phone_nums().size() ; i++ )	
	{
		for (int j=0 ; j< B.get_phone_nums().size() ; j++)
		{
			if (A.get_phone_nums()[i] == B.get_phone_nums()[j])
			{
				flag=true;
				break;
			}
		}
		if (flag == false)
		{
			return false;
		}
		else
			flag==false;
	}
	return true;
}

void AccountBook::clear()
{
	contacts.clear();
}

int AccountBook::size()
{
	return	contacts.size();
}

void AccountBook::set_contacts(vector<Contact> contact_list)
{
	contacts=contact_list;
}

void AccountBook::set_owed_AB(int i,double owed)
{
	contacts[i].set_owed_value(owed);
}

void AccountBook::set_emails_AB(int j,vector<string> emails)
{
	contacts[j].set_emails(emails);
}


void AccountBook::set_phonenums_AB(int k,vector<int> phone_nums)
{
	contacts[k].set_phone_nums(phone_nums);
}

bool AccountBook::operator<(const AccountBook& Abook) const
{
	if (!(*this == Abook) && *this <= Abook)
	{
		return true;
	}
	else 
		return false;
}

Contact& AccountBook::operator[](string key)
{
	bool flag =false;
	for (int i=0 ; i< contacts.size(); i++)
	{
		if (contacts[i].get_name() == key )
		{
			flag =true;
			return contacts[i];
		}
	}
	if (flag == false)
	{	
		vector<string> email;
		vector<int>	phone_nums;
		Contact new_contact(key,phone_nums,email,0);
		contacts.push_back(new_contact);
		return	contacts[contacts.size()-1]; // check after sorting
	}
}

AccountBook AccountBook::operator&(const AccountBook& Abook) const
{
	AccountBook new_Abook;
	double owed;
	for (int i=0;i< Abook.get_contact().size() ; i++)
	{
		for ( int k=0; k < contacts.size() ; k++)
		{
			if (Abook.get_contact()[i] == contacts[k])
			{
				new_Abook += contacts[k];
				owed=contacts[k].get_owed() + Abook.get_contact()[i].get_owed() ;
				new_Abook.set_owed_AB(new_Abook.get_contact().size()-1,owed);
				new_Abook.set_emails_AB(new_Abook.get_contact().size()-1,combine_emails(Abook.get_contact()[i],contacts[k]));
				new_Abook.set_phonenums_AB(new_Abook.get_contact().size()-1,combine_phone_nums(Abook.get_contact()[i],contacts[k]));
				break;
			}
		}
	}
	sort_contact (new_Abook);
	sort_email (new_Abook);
	sort_phone_num (new_Abook);
	return new_Abook;
}

AccountBook AccountBook::operator+(const AccountBook& Abook) const
{
	double owed;
	AccountBook new_Abook;
	new_Abook.set_contacts(contacts);
	for (int i=0;i< Abook.get_contact().size() ; i++)
	{
		for ( int k=0; k < contacts.size() ; k++)
		{
			if (Abook.get_contact()[i] == contacts[k])
			{
				owed = contacts[k].get_owed() + Abook.get_contact()[i].get_owed() ;
				new_Abook.set_owed_AB(k,owed);
				new_Abook.set_emails_AB(k,combine_emails(Abook.get_contact()[i],contacts[k]));
				new_Abook.set_phonenums_AB(k,combine_phone_nums(Abook.get_contact()[i],contacts[k]));
				break;
			}
			else 
			{
				new_Abook += Abook.get_contact()[i];
			}
		}
	}
	sort_contact (new_Abook);
	sort_email (new_Abook);
	sort_phone_num (new_Abook);
	return new_Abook;
}

AccountBook& AccountBook::operator+=(const Contact& c)
{
	string key;
	key = c.get_name();
	if (contacts.size() == 0)
	{
		contacts.push_back(c);
		return *this;
	}
	for (int i=0 ; i<contacts.size() ; i++)
	{
		if (contacts[i].get_name() == key)
		{
			contacts[i].set_phone_nums(c.get_phone_nums());
			contacts[i].set_emails(c.get_emails());
			contacts[i].set_owed_value(c.get_owed());
			return *this;
		}
	}
	contacts.push_back(c);
	sort_contact (*this);
	sort_email (*this);
	sort_phone_num (*this);
	return *this;
}

AccountBook& AccountBook::operator-=(const string key)
{
	for (int i=0 ; i<contacts.size() ; i++)
	{
		if (contacts[i].get_name() == key)
		{
			contacts.erase (contacts.begin() + i);
			return *this;
		}
	}
	sort_contact (*this);
	sort_email (*this);
	sort_phone_num (*this);
	return *this;
}	

bool AccountBook::operator==(const AccountBook& Abook) const //edit this
{
	bool flag = false;
	if (contacts.size() != Abook.get_contact().size())
		return false;
	for (int m=0; m < contacts.size(); m++)
	{
		for (int n=0 ; n < Abook.get_contact().size(); n++)
		{
			if(contacts[m].get_name() == Abook.get_contact()[n].get_name() && 
				check_emails(contacts[m],Abook.get_contact()[n]) && 
				check_phone_nums(contacts[m],Abook.get_contact()[n]))
			{
				//cout << "Contact" << m << "and "<< "Contact" << n<< endl;
				flag=true;
				break;
			}
		}
		//cout << "Contact" << m << "and "<< "Contact" << n<< endl;
		//cout << "flag : " <<flag <<endl;
		if (flag==false)
		{
			return false;
		}
		else
			flag=false;
	}
	return true;

}

bool AccountBook::operator<=(const AccountBook& Abook) const 
{
	bool flag= false;
	if (contacts.size() > Abook.get_contact().size())
		return false;
	for (int i=0 ; i < contacts.size(); i++)
	{
		for (int j=0 ; j< Abook.get_contact().size() ; j++ )
		{
			if (contacts[i] == Abook.get_contact()[j])
			{
				if (contacts[i].get_owed() <= Abook.get_contact()[j].get_owed() &&
					contacts[i].get_emails().size() <= Abook.get_contact()[j].get_emails().size() &&
					contacts[i].get_phone_nums().size() <= Abook.get_contact()[j].get_phone_nums().size() &&
					check_emails(contacts[i],Abook.get_contact()[j]) && check_phone_nums(contacts[i],Abook.get_contact()[j]))
				{
					flag=true;
					break;
				}

			}
		}
		if (flag == false)
			return false;
		flag=false;
	}
	return true;
}

AccountBook& AccountBook::operator++()
{
	double owed;
	for (int i=0 ; i < contacts.size(); i++)
	{
		owed = contacts[i].get_owed();
		contacts[i].set_owed_value(owed + 1000);
	}
	return *this;
}

AccountBook& AccountBook::operator%=(double percent)
{
	double owed;
	for (int i=0 ; i < contacts.size(); i++)
	{
		owed = (percent * contacts[i].get_owed())/100 + contacts[i].get_owed() ;
		contacts[i].set_owed_value(owed);
	}
	return *this;
}

ostream& operator<<(ostream& out,const AccountBook& Abook)
{
	vector<Contact> c = Abook.get_contact();
	for (int i=0 ; i < c.size() ; i++)
	{
		out << c[i];
		if (i != c.size()-1)
		out << endl;
	}
	return out;
}