#include<bits/stdc++.h>
using namespace std;
int main()
{
	 printf("enter total amount of sum\n");
	 int sum=0;
	 cin>>sum;

	 printf("enter toal numbers of of arrat elemnt\n");
	 int n;
	 cin>>n;

	 int arr[n+1];

	 for(int i=0;i<n;i++)
	 {
	 	cin>>arr[i];
	 }

	 int dp[n+1][sum+1];

	 for(int i=0<=n;i++)
	 {
	 	for(int j=0;j<=sum;j++)
	 	{
	 		if(j==0)
	 			dp[i][j]=1;
	 		else
	 			if(i==0 && j!=0)
	 				dp[i][j]=0;
	 			else
	 				if(j<arr[i])
	 					dp[i][j]=dp[i-1][j];
	 				else
	 					dp[i][j]=(dp[i-1][j] || dp[i-1][j-arr[i]]);

	 	}
	 }

	 if(dp[n][sum])
	 	cout<<found<<endl;
	 else
	 	cout<<not found<<endl;

	 return 0;
}