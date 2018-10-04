#include<bits/stdc++.h>
using namespace std;
int dp[105];
int main()
{
	int n;
	cin>>n;
	int i;
	int a[n+1];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	if(a[0]!=0)
	dp[0]=1;
	else
	dp[0];
	

	if(a[1]==0)
	dp[1]=dp[0];
	else
	if(a[1]==1 && a[i-1]!=1)
	dp[1]=dp[0]+1;
	else
	if(a[1]==2 && a[i-1]!=2)
	dp[1]=dp[0]+1;
	else
	dp[1]=dp[0]+1;

	for(i=2;i<n;i++)
	{
	     
		if(a[i]==0)
		{
			dp[i]=dp[i-1];
		
		}
		else
		if(a[i]==1 && (a[i-1]==2 || a[i-1]==0) )
		{
			dp[i]=dp[i-1]+1;
		
		}
		else
		if(a[i]==1 && a[i-1]==3 && a[i-2]==2)
		 {
		 	dp[i]=dp[i-1];
		 	
		 }
		 else
		 if(a[i]==1 && a[i-1]==3 && a[i-2]==2)
		  {
		  	dp[i]=dp[i-1]+1;
		  	
		  }
		else
		if(a[i]==1 && a[i-1]==1 )
		{
			dp[i]=dp[i-1];
			
		}
		else
		if(a[i]==2 && (a[i-1]==1 || a[i-1]==0) )
		 {
		 	dp[i]=1+dp[i-1];
		 	
		 }
		 else
		 if(a[i]==2 && a[i-1]==2)
		  {
		  	dp[i]=dp[i-1];
		  	
		  }
		  else
		   if(a[i]==2 && a[i-1]==3 && a[i-2]==1)
		   {
		   	 dp[i]=dp[i-1];
		   
		   	 
		   }
		   else
		   if(a[i]==2 && a[i-1]==3 && a[i-2]!=1)
		   {
		   	dp[i]=1+dp[i-1];
		   	
		   }
		   else
		  if(a[i]==3 )
		  {
		  	dp[i]=1+dp[i-1];
		  	
		  }		
		
	}
   
   
	cout<<dp[n-1]<<endl;
	return 0;
}
