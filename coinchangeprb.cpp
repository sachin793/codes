#include<bits/stdc++.h>
using namespace std;
int main()
{
	printf("enter total numbers of coin\n");
	int n;
	cin>>n;
    int coin[n+1];
	printf("enter coins\n");
	for(int i=1;i<=n;i++)
	{
       cin>>coin[i];
	}

    printf("enter total amount\n");
    int amount;
    cin>>amount;
	int dp[n+1][amount+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=amount;j++)
		{
			dp[i][j]=INT_MAX;
		}
	}
    for(int i=0;i<=n;i++)
    {
    	for(int j=0;j<=amount;j++)
    	{
    		if(i==0 || j==0)
    			dp[i][j]=0;

    		else
    			if(coin[i]>j)
    			{
    				dp[i][j]=dp[i-1][j];
    			}
    			else
    			{
    				dp[i][j]=min(dp[i][j],1+dp[i-1][j-coin[i]]);
    			}
    	}
    }

    cout<<dp[n][amount]<<endl;
    return 0;

}

