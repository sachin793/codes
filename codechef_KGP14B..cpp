#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int fun(char x[],char y[],int len1,int len2)
{
	int i,j;
	for(i=0;i<=len1;i++)
	{
		for(j=0;j<=len2;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=0;
			}
			else
			if(x[i-1]==y[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[len1][len2];
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int i,j;
		for(i=0;i<1005;i++)
		{
			for(j=0;j<1005;j++)
			{
				dp[i][j]=0;
			}
		}
		int len1,len2;
		cin>>len1>>len2;
		char s1[1005];
		char s2[1005];
		cin>>s1>>s2;
		int ans=fun(s1,s2,len1,len2);
		cout<<max(len1,len2)+min(len1,len2)-ans << endl;
	}
	return 0;
}
