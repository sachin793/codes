#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];

int fun(char x[],char y[],int len1,int len2)
{
	int i,j;
	for(i=0;i<=len1;i++)
	{
		for(j=0;j<=len2;j++)
		{
			if(i==0)
			 dp[i][j]=j;
			 
			 else
			  if(j==0)
			 dp[i][j]=i;
			 
			 else
			 if(x[i-1]==y[j-1])
			   dp[i][j]=dp[i-1][j-1];
			   
			   else
			    {
			    	dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
				}
			  
			 
		}
	}
	
	return dp[len1][len2];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i,j;
		for(i=0;i<2005;i++)
		{
			for(j=0;j<2005;j++)
			{
				dp[i][j]=0;
			}
		}
		
		char s1[2005];
		char s2[2005];
		cin>>s1>>s2;
		int ans=fun(s1,s2,strlen(s1),strlen(s2));
		cout<<ans<<endl;
	}
	
	return 0;
}
