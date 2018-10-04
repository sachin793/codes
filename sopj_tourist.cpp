#include<bits/stdc++.h>
using namespace std;
int dp1[105][105];
int dp2[105][105];
#define sc(n) scanf("%d",&n)
char path[105][105];
int fun1(int row,int column)
{
	int i,j;
	for(i=1;i<=row;i++)
	    {
	    	for(j=1;j<=column;j++)
	    	{
	    		dp1[i][j]=-1;
			}
		}
		
	
		if(path[1][1]=='*')
		 {
		   dp1[1][1]=1;
		   path[1][1]='.';
	}
		 else
		 dp1[1][1]=0;
		
		
		for(j=2;j<=column;j++)
		{
	        if(path[1][j]=='*')
	        {
			  dp1[1][j]=1+dp1[1][j-1];
			  path[1][j]='.';  
	        }
	         else
	          if(path[1][j]=='.')
	          dp1[1][j]=dp1[1][j-1];
	          
	          else
	           break;
		}
		
		for(i=2;i<=row;i++)
		{
	        if(path[i][1]=='*')
	        {
			
	         dp1[i][1]=1+dp1[i-1][1];
	          path[i][1]='.'; 
	     }
	         
	         else
	          if(path[i][1]=='.')
	          dp1[i][1]=dp1[i-1][1];
	          
	          else
	           break;
		}
		
		for(i=2;i<=row;i++)
		{
			for(j=2;j<=column;j++)
			{
				int mx=max(dp1[i][j-1],dp1[i-1][j]);
			
				if(mx!=-1 && path[i][j]!='#')
				{
					if(path[i][j]=='*')
					{
						path[i][j]='.';
						dp1[i][j]=1+mx;
					}
					else
					 dp1[i][j]=mx;
				}
			}
		}

		
		
	
		
		
	return dp1[row][column];
}

int fun2(int row,int column)
{    
   int i,j;
	
            for(i=row;i>=1;i--)
	    {
	      for(j=column;j>=1;j--)
	    	{
	    		dp2[i][j]=-1;
		}
	   }
		

	
		if(path[row][column]=='*')
		 dp2[row][column]=1;
		 else
		 dp2[row][column]=0;
		
		//cout<<dp2[row][column]<<endl;
		
		for(j=column-1;j>=1;j--)
		{
	        if(path[1][j]=='*')
	         dp2[row][j]=1+dp2[row][j+1];
	         
	         else
	          if(path[1][j]=='.')
	          dp2[row][j]=dp2[row][j+1];
	          
	          else
	           break;
		}
		
		for(i=row-1;i>=1;i--)
		{
	        if(path[i][column]=='*')
	         dp2[i][column]=1+dp2[i+1][column];
	         
	         else
	          if(path[i][1]=='.')
	          dp2[i][column]=dp2[i+1][column];
	          
	          else
	           break;
		}
		//	cout<<dp2[row][column]<<endl;
		
		for(i=row-1;i>=1;i--)
		{
			for(j=column-1;j>=1;j--)
			{
				int mx=max(dp2[i][j+1],dp2[i+1][j]);
			
				if(mx!=-1 && path[i][j]!='#')
				{
					if(path[i][j]=='*')
					{
						dp2[i][j]=1+mx;
					}
					else
					 dp2[i][j]=mx;
				}
			}
		}

		
		
	            //	cout<<dp2[row][column]<<endl;
		
		
	return dp2[1][1];
}
int main()
{
	int t,i,j;
	sc(t);
	while(t--)
	{
	    int column,row;
	    sc(column);
	    sc(row);
	    
	    	
	    	
		for(i=1;i<=row;i++)
		{
			for(j=1;j<=column;j++)
			{
				cin>>path[i][j];
			}
		}
		
		int ans=(fun1(row,column)+fun2(row,column));
		cout<<ans<<endl;
	           

		
	}   
	return 0;
}
