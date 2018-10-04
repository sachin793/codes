#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;
	cin>>n;
	long long cap[n+1]={0};
    set<long long >s;
    long long fill[n+1]={0};
	for(long long i=1;i<=n;i++)
	{
		cin>>cap[i];
	    s.insert(i);
	}
	
	cin>>m;
	
	
	
	for(long long i=0;i<m;i++)
	{
		long long type;
		cin>>type;
		if(type==1)
		{
			long long p,x;
			cin>>p>>x;
	        set<long long>::iterator it=(s.upper_bound(p));
	        it--;
	        if(it!=s.end())
	        {
	        	
	        	while(x>=(cap[*it]-fill[*it]) && x!=0)
		     	{
				   s.erase(*it);
				   x=x-(cap[*it]-fill[*it]);
				   it=(s.upper_bound(*it));
			    }
						
			    fill[*it]+=x;
			}
	        
            				
		}
		else
		{
			long long k;
			cin>>k;
			set<long long >::iterator it=s.find(k);
			
			if(it==s.end())
			{
				cout<<cap[k]<<endl;
			}
			else
			{
				cout<<fill[k]<<endl;
			}
			
		}
	}
	return 0;
}
