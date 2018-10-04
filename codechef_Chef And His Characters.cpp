#include<bits/stdc++.h>
using namespace std;

int fun(int a[])
{
	if(a[2]!=0 && a[4]!=0 && a[7]!=0 && a[5]!=0)
	 return 1;
	 
	 return 0;
}
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		long long count=0;
		int has[26]={0};
		for(int i=0;i<s.length();i++)
		{
			s[i]=tolower(s[i]);
			if(i>=4)
			{
			   has[s[i-4]-'a']--;	
			}
			has[s[i]-'0']++;
			if(fun(has))
			 count++;
			 			
		}
		if(count>0)
		{
			cout<<"lovely "<<count<<endl;
		}
		else
		{
			cout<<"normal"<<endl;
		}
	}
}
