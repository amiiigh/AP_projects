#include <iostream>
#include <cmath>
#include <climits>
#include <sstream>
#include <string>
using namespace std;
long double f(long double v,long double a ,long double b ,long double c,long double d ,long double m,long double t) //set ymid and ymin and ymax
{
	return a*pow(v,3)+b*pow(v,2)+c*pow(v,1)+ d- t/m;
}
long double equ(long double a ,long double b ,long double c,long double d ,long double m,long double t,long double min=0,long double max=LLONG_MAX)
{
	long double ymid,ymin,ymax;
	long double mid=(min+max)/2;
	ymid=f(mid,a,b,c,d,m,t);
	ymin=f(min,a,b,c,d,m,t);
	ymax=f(max,a,b,c,d,m,t);
	if (max-mid>10e-13)
	{
		if (ymid*ymin <0)
			mid = equ(a,b,c,d,m,t,min,mid);
		else if (ymid*ymax<0)
			mid = equ(a,b,c,d,m,t,mid,max);
	}
	return mid;
}
int main()
{
	long double ans=0,a,b,c,d,t,m;
	int i;
	string result="";
	stringstream convert;
	while(cin>>a>>b>>c>>d>>m>>t)
	{
		convert.str("");
		ans = equ(a,b,c,d,m,t);
		convert <<fixed<< ans;
		result = convert.str();
		for (i=0;result[i]!='.';i++) //printin 
			cout << result[i];
		cout << result[i]<<result[i+1]<<result[i+2]<<endl;
	}
	return 0;
}

