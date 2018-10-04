#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,k;
		cin>>n>>k;
		long long count=0;
		long long days=0;
		long long a[n];
		for(long long i=0;i<n;i++)
		{
            cin>>a[i];
		}
        long long last=0;
		for(long long i=0;i<n;i++)
		{
            count=ceil((double)(a[i]-last)/k);
            days+=count;
            last=(count*k-(a[i]-last))-1;
            if(last<0)
            last=0;

		}

		cout<<days<<endl;
	}
	return 0;
}
