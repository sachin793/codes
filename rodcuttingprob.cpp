#include<bits/stdc++.h>
using namespace std;
int main()
{
	printf("enter total size of rod\n");
	int n;
	cin>>n;

	int prince[n];
	for(int i=1;i<=n;i++)
		cin>>prince[i];

	int dp[n+1][n+1];

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=INT_MIN;
		}
	}

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else
			  {
			  	dp[i][j]=max(dp[i][j],prince[i]+dp[i-1][j-i]);
			  }
		}
	}

	cout<<dp[n][n];
	return 0;
}


