#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,h;
		cin>>n>>h;
		long long arr[n]={0};
		for(long long i=0;i<n;i++)
		{
			long long a,b;
			cin>>a>>b;
			arr[a]+=1;
			if(b+1<n)
				arr[b+1]-=1;
		}

		for(long long  i=1;i<n;i++)
		{
			arr[i]=arr[i]+arr[i-1];
		}
       
        for(long long  i=1;i<n;i++)
		{
			arr[i]=arr[i]+arr[i-1];
		}
        long long min=arr[h-1];
        for(int i=1;i<(n-h+1);i++)
        {
             if((arr[i+h-1]-arr[i-1])<min)
             	min=(arr[i+h-1]-arr[i-1]);
        }

        cout<<(3*n-min)<<endl;

	}
	return 0;
}