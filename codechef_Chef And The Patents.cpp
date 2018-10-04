#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,m,x,k;
		cin>>n>>m>>x>>k;
		long long even=0,odd=0;
		for(int i=0;i<k;i++)
		{
			char s;
			cin>>s;
			if(s=='E')
			even++;
			else
			odd++;
		}
		long long count=0;
		int flag=0;
		int month;
		for(int i=1;i<=12;i++)
		{
			if(i%2==0 )
			{
				if(even>x)
				  {
				    count+=x;
				    even-=x;
				}
				  else
				  {
				  count+=even;
				  even-=even;
			      }
			}
			else
			{
				if(odd>x)
				{
				count+=x;
				odd-=x;
			   }
				else
				{
				  count+=odd;
				   odd-=odd;
			   }
			}
			
			if(count>=n)
			{
				flag=1;
				month=i;
				break;
			}
		}
		if(flag==1 && month<=m)
		{
			cout<<"yes"<<endl;
		}
		else
		{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
