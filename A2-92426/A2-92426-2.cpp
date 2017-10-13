#include <iostream>
#include <vector>
#include <string>
using namespace std;
string quadtree(vector<string> patt,int n);
int main ()
{
	int n;
	string answer;
	while(cin >>n)
	{
		if (n==0)
			break;
		vector<string> patt(n);
		for (int i=0;i<n;i++)
		{
			cin >> patt[i];
		}
		answer=quadtree (patt ,n);
		cout<<answer<<endl;
	}
}
string quadtree(vector<string> patt ,int n)
{	
	vector<string> s1(n/2);//sector 1
	vector<string> s2(n/2);//sector 2 
	vector<string> s3(n/2);//sector 3 
	vector<string> s4(n/2);//sector 4
	bool flag=true;//false means not same
	int i,j,k;
	char c;
	string ans;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (patt[0][0]!=patt[i][j])
			{
				flag=false;
				break;
			}
		}
		if (flag==false)
			break;
	}
	if (flag==false)
	{
		ans=ans+"R";
		for (j=0;j<n/2;j++)
		{
			for (k=0;k<n/2;k++) //set s1
			{
				c= patt[j][k];
				s1[j]=s1[j]+c;
			}

			for (k=n/2;k<n;k++) //set s2
			{
				c = patt[j][k];
				s2[j]=s2[j]+c;
			}		
		}
		i=0;
		for (j=n/2;j<n;j++)
		{	
			for (k=0;k<n/2;k++) //set s4
			{
				c = patt[j][k];
				s4[i]=s4[i]+c;
			}

			for (k=n/2;k<n;k++) //set s3
			{
				c = patt[j][k];
				s3[i]=s3[i]+c;
			}
			i++;		
		}
		return ans =ans + quadtree (s1,n/2) + quadtree (s2,n/2)+ quadtree (s3,n/2)+ quadtree (s4,n/2);
	}
	else
	{
		if (patt[0][0]=='*')
			return ans=ans + "B";
		else
			return ans=ans + "W";	
	}	

}

