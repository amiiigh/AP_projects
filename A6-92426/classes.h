#ifndef CLASSES_H_
#define CLASSES_H_
#include <iostream>
#include <vector>
using namespace std;

class home 
{
public:
	int set_X_Y(vector<string> maze);
	int get_X(){return pos_X;}
	int get_Y(){return pos_Y;}
private:
	int pos_X;
	int pos_Y;
};

class object
{
public:
	void set_ID(int _id);
	void set_X_Y(vector<string> maze);
	char get_ID(){return ID;}
	int get_X(){return pos_X;}
	int get_Y(){return pos_Y;}
private:
	char ID;
	int pos_X;
	int pos_Y;
};

class ghost
{
public:
	ghost(int x,int y);
	int get_X(){return pos_X;}
	int get_Y(){return pos_Y;}
	void move(vector<string>& maze);
private:
	int pos_X;
	int pos_Y;
};

class kid
{
public:
	kid (char _name,int _id);
	char get_name(){return name;}
	int get_ID(){return ID;}
	int get_stamina(){return stamina;}
	int get_Y() const {return pos_Y;}
	int get_X() const {return pos_X;}
	void set_obj(vector<string> maze,home HQ);
	bool find_way(int move_no, int current_y, int current_x,int target_x,int target_y,vector<string> maze,string& path); 
	string get_path(){return path_to_obj;}
	void set_stamina(int sta);
	void move(vector<string>& maze,int gift_val,vector<ghost> ghost_list);
	bool operator==(const kid& sec_kid) const ;
private:
	string path_to_obj;
	string path_to_home;
	int speed;
	int stamina;
	int stamina_max;
	int ID; ///CHECK THAT
	char name;
	int pos_X;
	int pos_Y;
	object obj;
	vector<string> _maze;
	int move_counter;
	bool target_aq;
	bool re_home;
	bool charge;
	bool scared;
	bool flag2;
	int charge_counter;
};





class gift
{

public:

private:
	int value;
};

#endif