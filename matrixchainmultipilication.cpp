#include<bits/stdc++.h>
using namespace std;
int main()
{
	printf("enter toal number of matrix\n");
	int n;
	cin>>n;

	int a[n+1];
	for(int i=0;i<n+1;i++)
	{
        cin>>a[i];
	}

   int dp[n+1][n+1];
   for(int i=0;i<=n;i++)
   {
   	 for(int j=0;j<=n;j++)
   	 {
   	 	dp[i][j]=INT_MAX;
   	 }
   }

   int pos[n+1][n+1];

   for(int length=0;length<n;length++)
   {
   	  for(int i=1;i<=n;i++)
   	  {
   	  	  int j=i+length;
   	  	  if(j==i)
   	  	  {
   	  	  	dp[i][j]=0;
   	  	  }
   	  	  else
   	  	  {
   	  	  	 
   	  	  	 for(int k=i;k<j;k++)
   	  	  	 {
                 dp[i][j]=min(dp[i][j],(dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]));
                 
   	  	  	 }
   	  	  }
   	  }
   }

   cout<<dp[1][n]<<endl;
   return 0;
}
