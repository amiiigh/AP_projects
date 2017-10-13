#include "AccountBook.h"
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<int> phone_num;
	vector<string> email;
	phone_num.push_back(1234);
	phone_num.push_back(4321);
	email.push_back("Ali1");
	email.push_back("ali2");
	Contact person1("Ali",phone_num,email,1000);

	phone_num.clear();
	email.clear();
	phone_num.push_back(6789);
	phone_num.push_back(9876);
	email.push_back("amin");
	Contact person2("amin",phone_num,email,2000);

	cout << person1 << endl;
	cout << person2 << endl;

	phone_num.clear();
	email.clear();
	phone_num.push_back(1234);
	email.push_back("am1n");
	Contact person1_clone("Ali",phone_num,email,3000);

	phone_num.clear();
	email.clear();
	phone_num.push_back(1234);
	email.push_back("ali2");
	Contact person1_sub("Ali",phone_num,email,1000);

	phone_num.clear();
	email.clear();
	phone_num.push_back(231313);
	email.push_back("231312");
	Contact dummy_person("abdol",phone_num,email,23123);

	AccountBook book1;
	book1 += person1;
	book1 += person2;
	book1 += dummy_person;

	AccountBook book2;
	book2 += person1_clone;

	AccountBook book3;
	book3 += person1_sub;

	cout << (book3 < book1) << endl;
	if(!(book3 < book1))
		cout << "[BUG] sub is not working :| " << endl;
	// cout <<"-------------"<<endl;
	// cout << book1 <<endl;
	// cout <<"-------------"<<endl;
	// cout << book2 <<endl;
	// cout <<"-------------"<<endl;
	cout << (book1 + book2) << endl;

	phone_num.clear();
	email.clear();
	phone_num.push_back(23131231);
	email.push_back("sdasdad");
	Contact person1_new("Ali",phone_num,email,1212);

	book1 += person1_new;
	cout << book1 << endl;

	book1 %= 10.3;
	cout << book1 << endl;

	++book1;
	cout << book1 << endl;

	book1 -= "Abooali";
	cout << book1 << endl;
	book1 -= "abdol";
	cout << book1 << endl;

	cout << (book1 & book2) << endl;
	
	cout << (book1 == book2) << endl;
	cout << (book2 < book1) << endl;
	cout << (book2 <= book1) << endl;
	cout << ((book1 & book2) < book2) << endl;
	cout << (book1 <= book2) << endl;
	cout << book1["amin"] << endl;
	cout << book1["aboo"] << endl;

	cout << book1.size() << endl;
	book1.clear();
	cout << book1.size() << endl;
	
}
