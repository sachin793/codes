#include<bits/stdc++.h>
using namespace std;
int main()
{
	printf("enter total items\n");
	int n;
	cin>>n;

	printf("enter total weight\n");
	int ans;
	cin>>ans;

	printf("enter weight of items\n");
	int weight[n+1];
	int price[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>weight[i];
	}
    
    printf("enter price of those items\n");
	for(int i=1;i<=n;i++)
	{
		cin>>price[i];
	}
  
    int dp[n+1][ans+1];
    int chose[n+1][ans+1];

    for(int i=0;i<=n;i++)
    {
    	for(int j=0;j<=ans;j++)
    	{
            if(i==0 || j==0)
            	dp[i][j]=0;
            else
            	if(weight[i]>j)
            	{
            		dp[i][j]=dp[i-1][j];
            		
            	}
            	else
            	{
                    dp[i][j]=max(price[i]+dp[i-1][j-weight[i]],dp[i-1][j]);
                    
            	}
    	}
    }

    cout<<dp[n][ans];
    return 0;

}
