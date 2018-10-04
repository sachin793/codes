#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,k;
	cin>>t;
	for(k=1;k<=t;k++)
	{
		long long n;
		cin>>n;
		long long i;
		long long dp[n+1],a[n+1];
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		
		for(i=1;i<=n;i++)
		{
			dp[i]=0;
		}
		
		dp[1]=a[1];
		dp[2]=max(a[1],a[2]);
		
		for(i=3;i<=n;i++)
		{
			dp[i]=max((a[i]+dp[i-2]),dp[i-1]);
			
		}
		
		cout<<"Case "<<k<<": "<<dp[n]<<endl;
	}
}
