#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "classes.h"
using namespace std;
Transportation* find_path(string _origin,string destination,Time time,vector<int>passengers,vector<string>& seen_cities,vector<Transportation*>& path,vector<Transportation*> tr_list);
void print_recip(vector<Transportation*> path,vector<int>passengers,Time start);
#endif