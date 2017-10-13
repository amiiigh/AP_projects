#ifndef PATHFINDER_H_
#define PATHFINDER_H_
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class InvalidPositionEx {
public:
	InvalidPositionEx(int x, int y);
	void print_message();
private:
	int _x, _y;
};

class NoPathEx {
public:
	NoPathEx(int x1, int y1, int x2, int y2);
	void print_message();
private:
	int _x1, _y1, _x2, _y2;
};

class InvalidMapEx {
public:
	void print_message();
};

class PathFinder {
public:
	PathFinder(vector<string> maze);
	string find_path_to(int x1, int y1, int x2, int y2);

private:
	bool solve(int x1, int y1, int x2, int y2, char dir);
	int getNum(int x, int y);
	bool isValidPos(int x, int y);

	vector<string> _map;
	int width, length;
	vector<char> dirs;
	map<int, int> closed;
};

#endif /* PATHFINDER_H_ */
