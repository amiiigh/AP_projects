#include "classes.h"
using namespace std;
vector<Food> set_food_list()
{
	int number;
	bool flag =true;
	int price;
	string n="";
	string temp="";
	int counter=1;
	vector<Food> foodlist;
	foodlist.push_back(Food(0,"free",0));
	while(temp != "**")
	{
		while (cin >> temp)
		{
			number=atoi(temp.c_str());
			if (temp=="**")
			{
				flag = false;
				break;
			}
			if (temp[0] >47 && temp[0]<58)
			{
				price=atoi(temp.c_str());
				break;
			}
			n = n + " " + temp;
		}
		if (flag==false)
		{
			flag=true;
			break;
		}
		foodlist.push_back(Food(counter,n,price));
		n="";
		counter++;
	}
	// for (int i=1;i<foodlist.size();i++)
	// {
	// 	cout <<"food number :"<<foodlist[i].get_food_id()<<'\t';
	// 	cout << "is:"<<foodlist[i].get_food_name()<<'\t'<<"price:"<<foodlist[i].get_food_price()<<endl;
	// }
	return foodlist;
}
void set_order_time()
{
	char n;
	string temp="";
	int year;
	int month;
	int day;
	int hour;
	int min;
	while (true) //set year
	{
		cin >> n;
		if (n =='-')
			break;
		temp = temp + n ;
	}
	year = atoi(temp.c_str());
	temp="";
		while (true) //set month
	{
		cin >> n;
		if (n =='-')
			break;
		temp = temp + n ;	
	}
	month = atoi(temp.c_str());
	temp="";
	cin >> temp;//set day
	day = atoi(temp.c_str());
	temp="";
		while (true) //set hour
	{
		cin >> n;
		if (n ==':')
			break;
		temp = temp + n ;
	}
	hour = atoi(temp.c_str());
	temp="";
	cin>> temp; //set min
	min = atoi(temp.c_str());
	Time ordertime(year,month,day,hour,min);
}
vector<Orderlist> set_food_order()
{
	string temp="";
	int food_id;
	int num_of_food;
	string comment="";
	bool flag_com = false;
	bool flag_id=false;
	bool flag_num=false;
	vector<Orderlist> orderlist;
	while(temp!="$")
	{
		if (flag_com==false)
			comment="";
		cin >> temp;
		while(!(temp[0] > 47 && temp[0] < 58) && temp!= "$")
		{
			flag_com =true;
			comment=comment + temp + ' ';
			cin >> temp ;
			if (temp=="$")
			break;
		}
		if (flag_com == true && flag_id == true && flag_num == true)
		{
			flag_com=false;
			orderlist.push_back(Orderlist(food_id,num_of_food,true));
		}
		else if (flag_id == true && flag_num == true && flag_com == false)
		{
			orderlist.push_back(Orderlist(food_id,num_of_food,false));
			flag_num=false;
			flag_id=false;
		}
		if (temp=="$")
			break;
		food_id = atoi(temp.c_str());
		flag_id=true;
		cin >> temp;
		num_of_food = atoi(temp.c_str());
		flag_num=true;
	}
	// for (int i=0;i<orderlist.size();i++)
	// {
	// 	cout <<"food id:"<<orderlist[i].get_order_id()<<'\t';
	// 	cout << "num_of_food is :"<<orderlist[i].get_num_of_order()<<'\t'<<"comment:"<<orderlist[i].get_if_comment()<<endl;
	// }
	return orderlist;
}
string set_person_id()
{
	string id="";
	cin >> id ;
	return id;
}
int search_by_id(string person_idcall,int food_id)
{
	ifstream input ("past.txt");
	string line;
	stringstream ss;
	ss << food_id;
	int counter=0;
	int temp;
	if (!(input.is_open()))
		return -1;
	else
	{
		while(!input.eof())
		{
			input >> line;
			if (line == person_idcall)
			{
				while (!(line=="**"))
				{
					input >> line;
					if (line == ss.str())
					{	
						input >> line;
						temp = atoi(line.c_str());
						counter= counter + temp;
					}
				}
			}
			line="";			
		}
	}
	input.close();	
	return counter;
}
int search_for_comment(string person_idcall)
{

	ifstream input ("past.txt");
	string buffer;
	int counter=0;
	int temp;
	int number;
	stringstream ss;
	if (!(input.is_open()))
		return -1;
	else
	{
		while(!input.eof())
		{
			input >> buffer;
			if (buffer == person_idcall)
			{
				while (!(buffer=="**"))
				{
					getline(input,buffer);
					for(int i=0;i<buffer.size();i++)
					{
						if (!(buffer[i] > 47 && buffer[i] < 58) && buffer[i]!=' ' && buffer[i]!='-' && buffer[i]!=':' && buffer[i]!='*' && buffer[i]!='$')
						{	
							if (buffer[i-3] > 47 && buffer[i-3] < 58)
								counter=counter + (buffer[i-3] - 48)*10 + buffer[i-2] - 48 ;
							counter = counter + buffer[i-2] - 48 ;
							break;
						}
					}

				}
			}
			buffer="";			
		}
	}
	input.close();	
	return counter;
}
void calculate_order(string person_idcall, vector<Food> foodlist,vector<Orderlist> orderlist)
{

	int num_of_food;
	double off;
	double price=0;
	double all_price=0;
	int offlimit;
	int num_of_comment;
	for (int i=0;i<orderlist.size();i++)
	{
		num_of_comment = search_for_comment(person_idcall) + orderlist[i].get_num_of_order() * orderlist[i].get_if_comment();
		num_of_food = search_by_id(person_idcall,orderlist[i].get_order_id()) + orderlist[i].get_num_of_order();
		cout<<"num_of_comment is :"<< num_of_comment <<endl;
		cout<<"num_of_food is :"<< num_of_food <<endl;
		if (num_of_food >=5 && num_of_food <=10)
			off=0.10;
		else if (num_of_food >10 && num_of_food <=20)
			off=0.15;
		else if (num_of_food > 20)
			off=0.20;
		else 
			off=0;
		if (num_of_comment > num_of_food/2)
		{
			off=off/2;			
		}
		off=1-off;
		//cout<< "off is :"<<off<<endl;
		price = foodlist[2].get_food_price() * num_of_food ;
		//cout << "price :"<<price<<endl<<"price with off"<<endl;
		price=price*off;
		//printf("%.3f\n",price);
		all_price=all_price +price;
	}
	cout<<person_idcall<<'\t';
	printf("%.3f\n",all_price);
}
int main()
{
	vector<Food> foodlist;
	vector<Orderlist> orderlist;
	string person_idcall;
	foodlist = set_food_list();
	person_idcall = set_person_id();
	set_order_time();
	orderlist = set_food_order();
	calculate_order(person_idcall,foodlist,orderlist);
}