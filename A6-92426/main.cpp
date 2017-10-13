#include "functions.h"
#include "classes.h"
#include <vector>
using namespace std;

int main()
{
	vector<int>sta_list;
	vector<string> maze;
	vector<ghost>ghost_list;
	int gift_val;
	int sec_remain;
	home HQ;

	sta_list = set_config(sec_remain,gift_val);
	string path;

	maze = read_map();
	HQ.set_X_Y(maze);
	print_map(maze);
	ghost_list = set_ghosts(maze);

	kid A('a',1);
	A.set_obj(maze,HQ);
	A.set_stamina(sta_list[0]);
	kid B('b',2);
	B.set_obj(maze,HQ);
	B.set_stamina(sta_list[1]);
	kid C('c',3);
	C.set_obj(maze,HQ);
	C.set_stamina(sta_list[2]);
	kid D('d',4);
	D.set_obj(maze,HQ);
	D.set_stamina(sta_list[3]);
	kid F('f',5);
	F.set_obj(maze,HQ);
	F.set_stamina(sta_list[4]);
	kid J('j',6);
	J.set_obj(maze,HQ);
	J.set_stamina(sta_list[5]);
	kid K('k',7);
	K.set_obj(maze,HQ);
	K.set_stamina(sta_list[6]);
	while(sec_remain >0)
	{	
		cout << sec_remain << endl;
		cin.get();
		for(int i=0 ; i<ghost_list.size();i++)
		{

			ghost_list[i].move(maze);	
			// cout << "ghost number : "<<i+1<<" postions :"<<endl;
			// cout << "X is : "<<ghost_list[i].get_X()<<endl;
			// cout << "Y is : "<<ghost_list[i].get_Y()<<endl;
		}
		A.move(maze,gift_val,ghost_list);
		B.move(maze,gift_val,ghost_list);
		C.move(maze,gift_val,ghost_list);
		D.move(maze,gift_val,ghost_list);
		F.move(maze,gift_val,ghost_list);
		J.move(maze,gift_val,ghost_list);
		K.move(maze,gift_val,ghost_list);
		cout << A.get_stamina()<<'-'<<B.get_stamina()<<'-'<<C.get_stamina()<<'-'<<D.get_stamina()<<'-'<<F.get_stamina()<<'-'<<J.get_stamina()<<'-'<<K.get_stamina()<<endl;
		print_map(maze);

			// if (A==B)
			// 	maze[A.get_X()][A.get_Y()]='*';
			// if (A==C)
			// 	maze[A.get_X()][A.get_Y()]='*';
			// if (A==D)
			// 	maze[A.get_X()][A.get_Y()]='*';
			// if (A==F)
			// 	maze[A.get_X()][A.get_Y()]='*';
			// if (A==J)
			// 	maze[A.get_X()][A.get_Y()]='*';
			// if (A==K)
			// 	maze[A.get_X()][A.get_Y()]='*';
			// if (B==C)
			// 	maze[B.get_X()][B.get_Y()]='*';
			// if (B==D)
			// 	maze[B.get_X()][B.get_Y()]='*';
			// if (B==F)
			// 	maze[B.get_X()][B.get_Y()]='*';
			// if (B==J)
			// 	maze[B.get_X()][B.get_Y()]='*';
			// if (B==K)
			// 	maze[B.get_X()][B.get_Y()]='*';
			// if (C==D)
			// 	maze[C.get_X()][C.get_Y()]='*';
			// if (C==F)
			// 	maze[C.get_X()][C.get_Y()]='*';
			// if (C==K)
			// 	maze[C.get_X()][C.get_Y()]='*';
			// if (C==J)
			// 	maze[C.get_X()][C.get_Y()]='*';
			// if (D==F)
			// 	maze[D.get_X()][D.get_Y()]='*';
			// if (D==K)
			// 	maze[D.get_X()][D.get_Y()]='*';
			// if (D==J)
			// 	maze[D.get_X()][D.get_Y()]='*';
			// if (F==K)
			// 	maze[F.get_X()][F.get_Y()]='*';
			// if (F==J)
			// 	maze[F.get_X()][F.get_Y()]='*';
			// if (J==K)
			// 	maze[J.get_X()][J.get_Y()]='*';
		sec_remain--;
	}
	// cout << "second remaining is : "<< sec_remain<<endl;
	// cout << "gift_val is : "<< gift_val <<endl;
	// //cout << "path of A is : "<<A.get_path() << endl;
	// cout << "stamina of A is : "<<A.get_stamina() << endl;
	// //cout << "path of B is : "<<B.get_path() << endl;
	// cout << "stamina of B is : "<<B.get_stamina() << endl;
	// //cout << "path of C is : "<<C.get_path() << endl;
	// cout << "stamina of C is : "<<C.get_stamina() << endl;
	// //cout << "path of D is : "<<D.get_path() << endl;
	// cout << "stamina of D is : "<<D.get_stamina() << endl;
	// //cout << "path of F is : "<<F.get_path() << endl;
	// cout << "stamina of F is : "<<F.get_stamina() << endl;
	// //cout << "path of J is : "<<J.get_path() << endl;
	// cout << "stamina of J is : "<<J.get_stamina() << endl;
	// //cout << "path of K is : "<<K.get_path() << endl;
	// cout << "stamina of K is : "<<K.get_stamina() << endl;
}