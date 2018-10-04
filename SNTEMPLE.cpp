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

		long long val=2*n+2;

	    map < long long , long long > mp;
         long long num;

        long long a[val];

        for(long long i=0;i<val;i++)
        {
        	cin>>a[i];
        }

	    for(long long i=0;i<val;i++)
	    {
	    	
	    	
	    	mp[a[i]]++;
	    }

	    set < long long > s;

	    for(long long i=0;i<val;i++)
	    {
	    	if(mp[a[i]]%2==1)
	    	{
	    		s.insert(a[i]);
	    	}
	    }

	    set < long long > :: iterator it;
	    it=s.begin();
	    cout<<*it<<" ";
	    it++;
	    cout<<*it<<endl;
	}

	return 0;
}