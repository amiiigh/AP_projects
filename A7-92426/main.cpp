#include <iostream>
#include <vector>
#include "classes.h"
#include "functions.h"
using namespace std;

int main()
{

	Transportation_list trlist;
	Input in;
	vector<Transportation*> list = trlist.read_file();
	// cout<<endl;
	// cout << "testing" << endl;
	// for (int i=0 ; i< list.size() ; i++)
	// {
	// 	cout << list[i]->get_ref()<< endl;
	// 	cout << list[i]->get_origin()<< endl;
	// 	cout << list[i]->get_dest()<< endl;
	// 	if (list[i]->get_ref()[0] == 'F')
	// 	{
	// 		cout << list[i]->get_fee()<< endl;
	// 		cout << list[i]->get_capacity()<< endl;	
	// 		list[i]->get_st_time();
	// 		list[i]->get_en_time();
	// 	}
	// 	else
	// 	{
	// 		cout << list[i]->get_speed_limit()<< endl;
	// 		cout << list[i]->get_dis()<< endl;
	// 	}


	// 	cout << endl;
	// }
	//get input

	vector<string>seen_cities;
	vector<Transportation*> path;
	in.read_input();
	// in.show_inputs();
	if (find_path(in.get_origin(),in.get_dest(),in.get_time(),in.get_passengers(),seen_cities,path,list) == NULL)
	{
		cout << "no result found!"<< endl;
		return 0;
	}
	print_recip(path,in.get_passengers(),in.get_time());
	// for (int j=0; j< path.size(); j++)
	// {
	// 	cout << path[j]->get_ref()<<"->";
	// }


}