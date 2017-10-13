#include "functions.h"
Transportation* find_path(string _origin,string destination,Time time,vector<int>passengers,vector<string>& seen_cities,vector<Transportation*>& path,vector<Transportation*> tr_list)
{
	bool flag = false;
	Transportation* a;
	// cout << _origin << "->" << destination << endl;
	//vector<Transportation*> path;
	for (int i=0 ; i< tr_list.size(); i++)
	{

		// cout << "in first loop"<<endl;

		if (tr_list[i]->isAvailable(_origin,time.convert(),passengers) && tr_list[i]->get_dest() == destination)
		{
			// cout << "success in first loop"<<endl;
			// cout << tr_list[i]->get_ref()<< endl;
			path.push_back(tr_list[i]);
			return tr_list[i];
		}	
	}
	for (int j=0 ; j<tr_list.size(); j++)
	{
		// cout << "scond loop  "<< tr_list[j]->get_ref()<<endl;
		if(tr_list[j]->isAvailable(_origin,time.convert(),passengers))
		{

			for(int k=0 ; k < seen_cities.size() ;k++)
			{
				if (tr_list[j]->get_dest() == seen_cities[k])
				{
					flag = true;
					break;
				}
			}
			if (flag == true)
			{
				// cout << "same"<<endl;
				flag = false;
				continue;
			}
			// cout << tr_list[j]->get_ref()<< endl;
			path.push_back(tr_list[j]);
			seen_cities.push_back(tr_list[j]->get_origin());
			if(tr_list[j]->get_ref()[0] == 'F')
				a = find_path(tr_list[j]->get_dest(),destination,tr_list[j]->get_en_time(),passengers,seen_cities,path,tr_list);
			else
				a = find_path(tr_list[j]->get_dest(),destination,time + tr_list[j]->getDuration(),passengers,seen_cities,path,tr_list);				
			if (a == NULL)
			{
				seen_cities.pop_back();
				path.pop_back();
				continue;
			}

			return a;
		}
	}
	return NULL;
}

void print_recip(vector<Transportation*> path,vector<int>passengers,Time start)
{
	Time temp;
	temp = start;
	// cout << temp.convert()<<endl;
	cout << "result for your query is:"<< endl;
	for (int i=0 ; i < path.size(); i++)
	{
		cout << "**************************************************"<<endl;
		if (path[i]->get_ref()[0] == 'F')
			cout << "type: "<< "Flight"<<endl;
		else
			cout << "type: "<< "Road"<<endl;
		cout << "reference: "<<path[i]->get_ref()<<endl;

		if (path[i]->get_ref()[0] == 'F')
		{
			temp = path[i]->get_en_time();
			// cout <<"temp is : "<< temp.convert()<< endl;
			cout << "route: "<< path[i]->get_origin()<<'('<<path[i]->get_st_time().convert()<<") --> ";
			cout << path[i]->get_dest()<<'('<<path[i]->get_en_time().convert()<<')'<< endl;

		}
//TEHRAN#RAMSAR#08:00#3(23,12,31)

		if (path[i]->get_ref()[0] == 'R')
		{
			// path[i]->get_en_time()
			// cout << temp.get_min()<< endl;
			// cout <<"temp is : "<< temp.convert()<< endl;
			cout << "route: "<< path[i]->get_origin()<<'('<< temp.convert()<<") --> ";
			temp = temp + path[i]->getDuration();
			cout << path[i]->get_dest()<<'('<< temp.convert() <<')'<< endl;
		}
		
		cout << "duration: "<< path[i]->getDuration()<<" minutes"<<endl;
		if (path[i]->get_ref()[0] == 'F')
		{
			cout << "price: ";
			path[i]->getFare(passengers);
		}

		if (path[i]->get_ref()[0] == 'R')
		{
			cout << "price: ";
			path[i]->getFare(passengers);
		}
		

		// path[i]->getFare(passengers);
	}
	// cout << "payment: "<< path[j]->getFare(passengers);
}
