#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "classes.h"
using namespace std;

void print_map(vector<string>maze);
vector<string> read_map();
vector<int> set_config(int& sec_remain,int& gift_val);
vector<ghost> set_ghosts(vector<string> maze);
//bool find_way(int move_no, int current_y, int current_x,int target_x,int target_y,vector<string> maze,string& path);
#endif