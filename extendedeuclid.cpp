#include<bits/stdc++.h>
using namespace std;

int g,x,y;
void extendeuclid(int a,int b)
{
	if(b==0)
	{
		g=a;

		x=1;
		y=0;
	}
	else
	{
		extendeuclid(b,a%b);

		int temp=x;
		x=y;
		y=temp-(a/b)*y;
	}
}

int main()
{
       extendeuclid(16,10);
       cout<<g<<x<<y;
       return 0;
}
