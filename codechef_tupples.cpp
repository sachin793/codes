#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,a,b,c;
		cin>>n>>a>>b>>c;
	            long long count=0;
		if(c>a && c>b)
		{
              
              for(int i=1;i<=a;i++)
              {
              	for(int j=1;j<=b;j++)
              	{
              		if(i*j>=(n/c) && i*j<=n)
              		{
              			if(n%(i*j)==0 && n/(i*j)<=c)
              			{
              				count++;
              			}
              		}

              		if(i*j>n)
              			break;

              	}
              	if(i*1>n)
              	break;
              }
		}
		else
			if(b>a && b>c)
			{
               for(int i=1;i<=a;i++)
              {
              	for(int j=1;j<=c;j++)
              	{
              		if(i*j>=(n/b) && i*j<=n)
              		{
              			if(n%(i*j)==0 && n/(i*j)<=b)
              			{
              				count++;
              			}
              		}
              		if(i*j>n)
              			break;
              	}
              	 if(i*1>n)
              	break;
              }

             
			}
			else
			{
			
                  for(int i=1;i<=b;i++)
              {
              	for(int j=1;j<=n/i;j++)
              	{
              		if(i*j>=(n/a) && i*j<=n)
              		{
              			if(n%(i*j)==0 && n/(i*j)<=a)
              			{
              				count++;
              			}
              		}
              		if(i*j>n)
              			break;

              	}
              	if(i*1>n)
              	break;
              }
              
			}

			cout<<count<<endl;
	}
	return 0;
}
