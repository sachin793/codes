#include<bits/stdc++.h>
using namespace std;
long long  dp[55][55];
long long  has[1000005];
int main()
{
	int n,i,j;
	cin>>n;
	long long int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		dp[i][i]=a[i];
		has[dp[i][i]]++;
	}
	
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			dp[i][j]=min(dp[i][j-1],a[j]);
			has[dp[i][j]]++;
		}
	}
	
	int q;
	cin>>q;
	while(q--)
	{
         long long p;
         cin>>p;
         cout<<has[p]<<endl;
	}
	return 0;
}
