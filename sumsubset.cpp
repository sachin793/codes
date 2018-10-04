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

	 for(int i=1;i<=n;i++)
	 {
	 	cin>>arr[i];
	 }

	 int dp[n+1][sum+1];
	 int ans[n+1][sum+1];


  
	 for(int i=0;i<=n;i++)
	 {

	 	for(int j=0;j<=sum;j++)
	 	
	 	{
	 		ans[i][j]=0;
	 		if(j==0)
	 			dp[i][j]=1;

	 		else
	 			if(i==0 && j!=0)
	 				dp[i][j]=0;
	 			else
	 				if(j<arr[i])
	 					dp[i][j]=dp[i-1][j];
	 				else
	 					{
	 						dp[i][j]=(dp[i-1][j] || dp[i-1][j-arr[i]]);
	 						if(dp[i-1][j-arr[i]])
	 			             {
								 if(i==6 && j==2)
								 cout<<arr[i]<<endl;	
								 ans[i][j]=arr[i];
							}
	 							else
	 							{
							if(i==6 && j==2)
								 {
								 	cout<<"hello1"<<endl;
										 }	 
	 							ans[i][j]=ans[i-1][j];
	 						}
	 					}

	 	}
	 }
	 
	  for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=sum;j++)
	 	{
	 		cout<<dp[i][j]<<" ";
		 }
		 cout<<endl;
	 }
	 cout<<endl;
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=sum;j++)
	 	{
	 		cout<<ans[i][j]<<" ";
		 }
		 cout<<endl;
	 }

	 if(dp[n][sum])
	 	{
	 		cout<<"found"<<endl;
            int i=n;
            int j=sum;
	 		while(i!=0 && j!=0)
	 		{
                if(ans[i][j])
                {
                    cout<<ans[i][j];
                    j=j-arr[i];
                    i--;
                }
                else
                {
                    i--;
                }
	 		}
	 	}
	 else
	 	cout<<"not found"<<endl;

	 return 0;
}

