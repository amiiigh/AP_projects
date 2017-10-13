// #include <iostream>
// #include <vector>
// #include <string>
// #include <fstream>
// using namespace std;
#include "functions.h"
#include "classes.h"
using namespace std;

vector<string> read_map()
{
	ifstream input;
	string line;
	vector<string>maze;

	input.open("map.txt");
	while(getline (input,line))
	{
		maze.push_back(line);
	}
	input.close();

	return maze ;
	// ############debug#############
	// cout << "map was read succseccfully"<<endl;
	// for (int i=0 ; i<maze.size() ; i++)
	// {
	// 	cout << maze[i] << endl;
	// }
}

vector<int> set_config(int& sec_remain,int& gift_val)
{
	ifstream input;
	int kids_sta[7];
	vector<int> kids_sta_list;
	input.open("config.txt");

	input >> sec_remain;
	for (int i=0 ; i< 7 ; i++)
	{
		input >> kids_sta[i];
		kids_sta_list.push_back(kids_sta[i]);
	}
	input >> gift_val;

	return kids_sta_list;
	// ############debug#############
	// cout << "sec_remain is :"<< sec_remain<<endl;
	// cout << "gift_val is :"<< gift_val<<endl;
	// for (int j=0 ; j< 7 ; j++)
	// {
	// 	cout << "kids_sta "<< j+1 <<  "is :" << kids_sta[j]<<endl;
	// }
}

void print_map(vector<string>maze)
{
	for (int i=0 ; i<maze.size() ; i++)
	{
		cout << maze[i] << endl;
	}
}

vector<ghost> set_ghosts(vector<string> maze)
{
	bool done=false;
	vector<ghost>ghosts_list;
	for (int i=0 ; i< maze.size();i++)
	{
		for (int j=0 ; j< maze[i].size() ; j++)
		{
			if (maze[i][j] == 'G')
			{	
				ghosts_list.push_back(ghost(i,j));
				// pos_X=i;
				// pos_Y=j;
				//done=true;
				//break;
			}
		}
		// if (done)
			// break;
	}
	return ghosts_list;
}
