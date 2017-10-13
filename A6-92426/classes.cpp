#include "classes.h"
#include <time.h>
#include <cstdlib>
int home::set_X_Y(vector<string> maze)
{
	bool done=false;
	for (int i=0 ; i< maze.size();i++)
	{
		for (int j=0 ; j< maze[i].size() ; j++)
		{
			if (maze[i][j] == 'H')
			{
				pos_X=i;
				pos_Y=j;
				done=true;
				break;
			}
		}
		if (done)
			break;
	}
	//############debug#############
	// cout << "the position of house is :"<<endl;
	// cout << "X : "<< pos_X << endl;
	// cout << "Y : "<< pos_Y << endl;
}
ghost::ghost(int x,int y)
{
	pos_X=x;
	pos_Y=y;
}

kid::kid(char _name, int _id) 
{
	name = _name ;
	ID = _id ;
	obj.set_ID(_id);
	move_counter=0;
	target_aq = false;
	charge = false;
	re_home = false;
	scared =false;
	flag2=false;
	charge_counter=0;
}
void kid::set_obj(vector<string> maze,home HQ)
{	
	pos_X= HQ.get_X();
	pos_Y= HQ.get_Y();

	obj.set_X_Y(maze);
	_maze = maze;
	find_way(1,HQ.get_Y(),HQ.get_X(),obj.get_X(),obj.get_Y(),maze,path_to_obj);
	//############debug#############
	// cout << "the position of object of "<< name << " is :" << endl;
	// cout << "looking for :" <<obj.get_ID()<<endl;
	// cout << "X : "<< obj.get_X() << endl;
	// cout << "Y : "<< obj.get_Y() << endl;
}

void object::set_ID(int _id)
{
	ID = 48 +_id;
}

void object::set_X_Y(vector<string> maze)
{
	bool done=false;
	for (int i=0 ; i< maze.size();i++)
	{
		for (int j=0 ; j< maze[i].size() ; j++)
		{
			if (maze[i][j] == ID)
			{
				pos_X=i;
				pos_Y=j;
				done=true;
				break;
			}
		}
		if (done)
			break;
	}

}

void kid::set_stamina(int sta)
{
	stamina = sta;
	stamina_max=sta;
}

void kid::move(vector<string>& maze,int gift_val,vector<ghost> ghost_list)
{
	char c;
	string path_temp ;
	char temp; 
	bool flag =false;
	while (true)
	{
		if (speed ==-2 || target_aq)
			c = path_to_home[move_counter];
		else
			c = path_to_obj[move_counter];

		if (re_home && target_aq)
			return;
		if (!scared)
		{
			for (int k=0 ; k< ghost_list.size() ; k++)
			{
				if ((pos_X -1==ghost_list[k].get_X() && pos_Y ==ghost_list[k].get_Y())|| 
					(pos_X +1==ghost_list[k].get_X() && pos_Y ==ghost_list[k].get_Y())||
					(pos_X ==ghost_list[k].get_X() && pos_Y +1 ==ghost_list[k].get_Y())||
					(pos_X-1==ghost_list[k].get_X() && pos_Y-1 ==ghost_list[k].get_Y()))
				{	
					cout << '\t'<< name << " got scared !"<< endl;
					speed = -2;
					scared =true;
					break;
				}
			}
		}
		if (speed == -2 && target_aq==false && flag2==false)
		{
			//cout << "target_aq : "<<target_aq << "flag2 : " <<flag2<<endl;
			//cout << " new path created!"<<endl;
			path_temp.clear();
			for(int j=path_to_home.size()-1; j >= 0 ; j--)
			{
				temp = path_to_home[j];
				path_temp = path_temp + temp;
			}
			path_to_home.clear();
			path_to_home = path_temp;
			//cout << "path to home : "<<path_to_home<<endl;
			move_counter=0;
			c = path_to_home[move_counter];
			flag2 = scared;
			continue;
		}
		if (stamina == 0 )
		{
			cout <<'\t'<< name << " is so tired !"<<endl;
			charge=true;
			if (charge_counter==5)
			{

				charge =false;
				stamina =stamina_max;
				charge_counter=0;
				return;
			}
			charge_counter++;
			return;
		}
		stamina = stamina -1;

		if (c== 'U')
		{
		if (maze[pos_X-1][pos_Y] == 'E')//won a prize
		{
			cout <<'\t'<< name << " got a gift !"<<endl;
			stamina = stamina + gift_val;
		}
		if(maze[pos_X-1][pos_Y] == '.' || maze[pos_X-1][pos_Y] =='E' || maze[pos_X-1][pos_Y] ==this->get_ID() || maze[pos_X-1][pos_Y] =='*')
			maze[pos_X-1][pos_Y] = name;
		if(maze[pos_X][pos_Y] == name || maze[pos_X][pos_Y] =='E' || maze[pos_X][pos_Y] ==this->get_ID() || maze[pos_X-1][pos_Y] =='*')
			maze[pos_X][pos_Y]='.';
		if (!scared)
			path_to_home = path_to_home + 'D';
		pos_X=pos_X-1;
		
	}
	else if(c == 'R')
	{
		if (maze[pos_X][pos_Y+1] == 'E')//won a prize
		{
			cout <<'\t'<< name << " got a gift !"<<endl;
			stamina = stamina + gift_val;
		}
		//if (maze[pos_X][pos_Y+1] != 'H')
		if(maze[pos_X][pos_Y+1] == '.' || maze[pos_X][pos_Y+1] =='E' || maze[pos_X][pos_Y+1] ==this->get_ID()|| maze[pos_X-1][pos_Y] =='*' )
			maze[pos_X][pos_Y+1] = name;
		//if(maze[pos_X][pos_Y] !='H')
		if(maze[pos_X][pos_Y] == name || maze[pos_X][pos_Y] =='E' || maze[pos_X][pos_Y] ==this->get_ID()|| maze[pos_X-1][pos_Y] =='*')
			maze[pos_X][pos_Y]='.';
		pos_Y=pos_Y+1;
		if (!scared)
			path_to_home = path_to_home + 'L';
	}
	else if(c == 'D')
	{
		if (maze[pos_X+1][pos_Y] == 'E')//won a prize
		{
			cout <<'\t'<< name << " got a gift !"<<endl;
			stamina = stamina + gift_val;
		}
		//if (maze[pos_X+1][pos_Y] != 'H')
		if(maze[pos_X+1][pos_Y] == '.' || maze[pos_X+1][pos_Y] =='E' || maze[pos_X+1][pos_Y] ==this->get_ID()|| maze[pos_X-1][pos_Y] =='*')
			maze[pos_X+1][pos_Y] = name;
		//if(maze[pos_X][pos_Y] !='H')
		if(maze[pos_X][pos_Y] == name || maze[pos_X][pos_Y] =='E' || maze[pos_X][pos_Y] == this->get_ID()+48 || maze[pos_X-1][pos_Y] =='*')
			maze[pos_X][pos_Y]='.';
		pos_X=pos_X+1;
		if (!scared)
			path_to_home = path_to_home + 'U';
	}
	else if (c== 'L')
	{
		//cout << "maze[pos_X][pos_Y-1] is : "<< maze[pos_X][pos_Y-1] << ","<<name <<endl;
		if (maze[pos_X][pos_Y-1] == 'E')//won a prize
		{
			cout <<'\t'<< name << " got a gift !"<<endl;
			stamina = stamina + gift_val;
		}
		//if (maze[pos_X][pos_Y-1] != 'H')
		if(maze[pos_X][pos_Y-1] == '.' || maze[pos_X][pos_Y-1] =='E' || maze[pos_X][pos_Y-1] ==this->get_ID()|| maze[pos_X-1][pos_Y] =='*' )
			maze[pos_X][pos_Y-1] = name;
		//if(maze[pos_X][pos_Y] !='H')
		if(maze[pos_X][pos_Y] == name || maze[pos_X][pos_Y] =='E' || maze[pos_X][pos_Y] ==this->get_ID()|| maze[pos_X-1][pos_Y] =='*' )
			maze[pos_X][pos_Y]='.';
		pos_Y=pos_Y-1;
		if (!scared)
			path_to_home = path_to_home + 'R';
	}
	move_counter++;
	if (move_counter >= path_to_obj.size() || (scared && move_counter >= path_to_home.size()) || (target_aq && move_counter >= path_to_home.size()))
	{
		if (speed ==-2)
		{
			cout << "scared back to house"<<endl;
			flag2=false;
			scared=false;
			speed=1;
			stamina = stamina_max;
			path_to_home.clear();
			cout << path_to_obj << endl;
			return;
		}
		if (target_aq)
		{	
			re_home=true;
			cout << name <<" has just reached home !"<< endl;
			return;
		}
		else	
			target_aq = true;
		path_temp.clear();
		for(int i=path_to_home.size()-1; i >= 0 ; i--)
		{
			temp = path_to_home[i];
			path_temp = path_temp + temp;
		}
		path_to_home.clear();
		path_to_home = path_temp ;
		name = name - 32;
		maze[pos_X][pos_Y] = name;
		move_counter=0;
	}
	if (speed==-2 && !flag)
	{
		flag =true;
		continue;
	}
	else
		break;

}
// cout << "pos of "<< name << "is:"<< endl;
// cout << "X is : "<< pos_X <<endl;
// cout << "Y is : "<< pos_Y <<endl;
}

bool kid::operator==(const kid& sec_kid) const 
{
	if (sec_kid.get_X() == pos_X && sec_kid.get_Y() == pos_Y)
		return true;
}
void ghost::move(vector<string>& maze)
{
	srand (time(NULL));
	int dir ;
	while (true)
	{
		dir = rand() % 100 + 25;
		// cout <<dir<<endl;
		dir =dir/25;
		if (maze[pos_X-1][pos_Y]=='#' && maze[pos_X+1][pos_Y]=='#' && maze[pos_X][pos_Y-1]=='#')
			dir==2;
		if (maze[pos_X-1][pos_Y]=='#' && maze[pos_X][pos_Y+1]=='#' && maze[pos_X][pos_Y-1]=='#')
			dir==3;
		if (maze[pos_X-1][pos_Y]=='#' && maze[pos_X+1][pos_Y]=='#' && maze[pos_X][pos_Y+1]=='#')
			dir==4;
		if (maze[pos_X][pos_Y+1]=='#' && maze[pos_X+1][pos_Y]=='#' && maze[pos_X][pos_Y-1]=='#')
			dir==1;
		if (dir == 1)
		{
			if (maze[pos_X -1][pos_Y] =='#')
			{
				continue;
			}
			if(maze[pos_X][pos_Y] != 'H' && maze[pos_X][pos_Y] != 'E' && maze[pos_X][pos_Y] != '1' &&
				maze[pos_X][pos_Y] != '2' && maze[pos_X][pos_Y] != '3' && maze[pos_X][pos_Y] != '4' &&
				maze[pos_X][pos_Y] != '5' && maze[pos_X][pos_Y] != '6' && maze[pos_X][pos_Y] != '7' )
				maze[pos_X][pos_Y]='.';
			if (maze[pos_X -1][pos_Y] =='.')
				maze[pos_X -1][pos_Y]='G';
			pos_X=pos_X-1;
			break;
		}	
		else if (dir == 2)
		{
			if (maze[pos_X][pos_Y+1] =='#')
				continue;
			if(maze[pos_X][pos_Y] != 'H' && maze[pos_X][pos_Y] != 'E' && maze[pos_X][pos_Y] != '1' &&
				maze[pos_X][pos_Y] != '2' && maze[pos_X][pos_Y] != '3' && maze[pos_X][pos_Y] != '4' &&
				maze[pos_X][pos_Y] != '5' && maze[pos_X][pos_Y] != '6' && maze[pos_X][pos_Y] != '7' )
				maze[pos_X][pos_Y]='.';
			if (maze[pos_X ][pos_Y+1] =='.')
				maze[pos_X ][pos_Y+1]='G';
			pos_Y=pos_Y +1;
			break;
		}	
		else if (dir == 3)
		{
			if (maze[pos_X +1][pos_Y] =='#')
				continue;
			if(maze[pos_X][pos_Y] != 'H' && maze[pos_X][pos_Y] != 'E' && maze[pos_X][pos_Y] != '1' &&
				maze[pos_X][pos_Y] != '2' && maze[pos_X][pos_Y] != '3' && maze[pos_X][pos_Y] != '4' &&
				maze[pos_X][pos_Y] != '5' && maze[pos_X][pos_Y] != '6' && maze[pos_X][pos_Y] != '7' )
				maze[pos_X][pos_Y]='.';
			if (maze[pos_X +1][pos_Y] =='.')
				maze[pos_X +1][pos_Y]='G';
			pos_X=pos_X+1;
			break;
		}	
		else if (dir == 4)
		{
			if (maze[pos_X ][pos_Y -1] =='#')
				continue;
			if(maze[pos_X][pos_Y] != 'H' && maze[pos_X][pos_Y] != 'E' && maze[pos_X][pos_Y] != '1' &&
				maze[pos_X][pos_Y] != '2' && maze[pos_X][pos_Y] != '3' && maze[pos_X][pos_Y] != '4' &&
				maze[pos_X][pos_Y] != '5' && maze[pos_X][pos_Y] != '6' && maze[pos_X][pos_Y] != '7' )
				maze[pos_X][pos_Y]='.';
			if (maze[pos_X ][pos_Y-1] =='.')
				maze[pos_X ][pos_Y-1]='G';
			pos_Y = pos_Y -1;
			break;
		}	
	}
	

}
bool kid::find_way(int move_no, int current_y, int current_x,int target_x,int target_y,vector<string> maze,string& path) 
{
	int x_delta[4] ;
	int y_delta[4] ;
	bool area1=false,area2=false,area3=false,area4=false;
    // uncomment the following two lines for debugging:
	//cout << move_no << endl;
	//cout << path << endl;
	//print_map(maze);
	//cin.get();
	int y_COUNT=maze[0].size();
	int x_COUNT=maze.size();
	//cout << y_COUNT <<'-'<<x_COUNT<<endl;
	if (target_y <= y_COUNT/2 && target_x<=x_COUNT/2)//area 1
	{	
		area1=true;
	//	cout << "area 1"<<endl;
		x_delta[0]=0;
		y_delta[0]=-1;
		
		x_delta[1]=-1;
		y_delta[1]=0;

		x_delta[2]=1;
		y_delta[2]=0;

		x_delta[3]=0;
		y_delta[3]=1;
	}
	else if (target_y > y_COUNT/2 && target_x<=x_COUNT/2)//area 2
	{
		area2=true;
	//	cout << "area 2"<<endl;
		x_delta[0]=0;
		y_delta[0]=1;

		x_delta[1]=-1;
		y_delta[1]=0;

		x_delta[2]=1;
		y_delta[2]=0;

		x_delta[3]=0;
		y_delta[3]=-1;
	}
	else if (target_y >= y_COUNT/2 && target_x > x_COUNT/2)//area 3
	{
		area3=true;
	//	cout << "area 3"<<endl;
		x_delta[0]=0;
		y_delta[0]=1;

		x_delta[1]=1;
		y_delta[1]=0;

		x_delta[2]=-1;
		y_delta[2]=0;

		x_delta[3]=0;
		y_delta[3]=-1;
	}
		else if (target_y < y_COUNT/2 && target_x > x_COUNT/2)//area 4
		{
			area4=true;
	//		cout << "area 4"<<endl;
			x_delta[0]=0;
			y_delta[0]=-1;

			x_delta[1]=1;
			y_delta[1]=0;

			x_delta[2]=-1;
			y_delta[2]=0;

			x_delta[3]=0;
			y_delta[3]=1;
		}
		if (move_no == y_COUNT * x_COUNT)
		{
		//cout << "move_no == y_COUNT * x_COUNT" << endl;
			return true;
		}
		for (int move = 0; move < 4; move++) 
		{
			int new_y = current_y + y_delta[move];
			int new_x = current_x + x_delta[move];

			//cout << new_y << '/'<< new_x <<endl ;
			if (new_y < 0 || new_y >= y_COUNT || new_x < 0 || new_x >= x_COUNT)
			{
			//cout << "new_y < 0 || new_y >= y_COUNT || new_x < 0 || new_x >= x_COUNT"<<endl;
				continue;
			}

			if (maze[new_x][new_y] != '.' && maze[new_x][new_y] != 'G' &&
				maze[new_x][new_y] != 'E' && maze[new_x][new_y] !='H' &&
				maze[new_x][new_y] !='1' && maze[new_x][new_y] != '2' &&
				maze[new_x][new_y] != '3' && maze[new_x][new_y] != '4' &&
				maze[new_x][new_y] != '5' && maze[new_x][new_y] != '6' &&
				maze[new_x][new_y] != '7')
			{
			//cout <<"maze[new_y][new_x] != '.'"<<endl; 
				continue;
			}
			maze[new_x][new_y] = '$';
			if (area1)
			{
				if (move ==0)
					path = path + 'L';
				else if (move ==1)
					path = path + 'U';
				else if (move ==2)
					path = path + 'D';
				else if (move == 3)
					path = path +'R';
			}
			else if (area2)
			{
				if (move ==0)
					path = path + 'R';
				else if (move ==1)
					path = path + 'U';
				else if (move ==2)
					path = path + 'D';
				else if (move == 3)
					path = path +'L';
			}
			else if (area3)
			{
				if (move ==0)
					path = path + 'R';
				else if (move ==1)
					path = path + 'D';
				else if (move ==2)
					path = path + 'U';
				else if (move == 3)
					path = path +'L';
			}
			else if (area4)
			{
				if (move ==0)
					path = path + 'L';
				else if (move ==1)
					path = path + 'D';
				else if (move ==2)
					path = path + 'U';
				else if (move == 3)
					path = path +'R';
			}

			if (new_x==target_x && new_y == target_y)
				return true;
			if (find_way(move_no + 1, new_y, new_x,target_x,target_y ,maze,path))
				return true;
			maze[new_x][new_y] = '.';
			path.erase(path.end()-1);
		}
		return false;

	}










