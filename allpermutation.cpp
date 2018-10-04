#include<bits/stdc++.h>
using namespace std;

void fun(string s, int lb, int up)
{
	if(lb==(up-1))
		{
			cout<<s<<endl;
			return ;
		}
	else
	{
		for(int i=lb;i<up;i++)
		{
			swap(s[i],s[lb]);
            fun(s,lb+1,up);
            swap(s[i],s[lb]);
           
		}
	}
}

int main()
{
	string s;
	cin>>s;
	int p=s.length();
	fun(s,0,p);
	return 0;
}
