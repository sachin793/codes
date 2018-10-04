#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	long long n;
	cin>>n;
	
	if(n>37)
	cout<<"-1"<<endl;
	else
	if(n<37)
	{
		ll count=n/2;
		for(ll i=0;i<count;i++)
		{
             cout<<"8";
		}
		if(n%2==1)
		{
			cout<<"0";
		}
		
	}
	else
	{
		ll count=n/2;
		if(n%2==1)
		{
			cout<<"0";
		}
		for(ll i=0;i<count;i++)
		{
             cout<<"8";
		}
		
		
	}
		
		
	
}
