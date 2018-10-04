#include<bits/stdc++.h>
using namespace std;



int main()
{
	long long t,j;
	cin>>t;
	for(j=1;j<=t;j++)
	{
		
		long long flag=0,i,node1,node2;
		cin>>node1>>node2;
		long long a[node1+1]={0};
		for(i=1;i<=node2;i++)
		{
			long long u,v;
			cin>>u>>v;
			if(a[u]==0 || a[v]==0)
			{
				if(a[u]==0 && a[v]!=0)
				{
					if(a[v]==1)
					{
						a[u]=2;
					}
					else
					 {
					 	a[u]=1;
					 }
				}
				else
				if(a[u]!=0 && a[v]==0)
				{
					if(a[u]==1)
					{
						a[v]=2;
					}
					else
					{
						a[v]=1;
					}
				}
				else
				{
					a[u]=1;
					a[v]=2;
				}
			}
			else
			{
				if(a[u]==a[v])
				  {
				  	
				  	flag=1;
				  
				  }
			}
			
		}
		if(flag==0)
		 cout<<"Scenario #"<<j<<":"<<endl<<"No suspicious bugs found!";
              else
                 {
                           cout<<"Scenario #"<<j<<":"<<endl<<"Suspicious bugs found!";
                }
	}
	return 0;
}
