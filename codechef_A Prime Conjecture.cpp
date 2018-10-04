#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long a[n];
		int flag=0;
		for(long long i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		if(n>2)
	    {
	    		
		for(long long i=1;i<n-1;i++)
		{
			if(llabs(a[i]-a[i-1])>1 || llabs(a[i]-a[i+1])>1)
               {
                  flag=1;
                  break;
               }
		}
		}
		else
		{
			if(llabs(a[0]-a[1])>1)
			{
				flag=1;
	
			}
		}
		if(flag==1)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
}
