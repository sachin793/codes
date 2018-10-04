#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007

int is_possible(int x,int y,int n,int m)
{
   if(x>=1 && x<=n && y>=1 && y<=m)
   	return 1;
   else
   	return 0;
}

int main()
{
	int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		cin>>a[i][j];
    	}
    }

    int row,coulm,time;
    cin>>row>>coulm>>time;

    set < pair < int , pair < int , int > > > s;
    
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
    	for (int j = 0; j <= m; ++j)
    	{
    		/* code */
    		dp[i][j]=INT_MAX;
    	}
    }
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    dp[1][1]=a[1][1];
    s.insert({1,{1,dp[1][1]}});

    while(!s.empty())
    {
         int cur_x=s.begin()->first;
         int cur_y=s.begin()->second.first;
         int cur_dis=s.begin()->second.second;
         s.erase(s.find({cur_x,{cur_y,cur_dis}}));

         for(int i=0;i<4;i++)
         {
              int next_x=cur_x+dx[i];
              int next_y=cur_y+dy[i];

              if(is_possible(next_x,next_y,n,m))
              {
                  if(dp[next_x][next_y]>dp[cur_x][cur_y]+a[next_x][next_y])
                  {
                  	if(dp[next_x][next_y]!=INT_MAX)
                  	{
                  		s.erase(s.find({next_x,{next_y,dp[next_x][next_y]}}));
                  	}

                  	dp[next_x][next_y]=dp[cur_x][cur_y]+a[next_x][next_y];
                  	s.insert({next_x,{next_y,dp[next_x][next_y]}});
                  }
              }
         }
    }

    if(dp[row][coulm]>time)
    {
    	cout<<"NO"<<endl;
    }
    else
    {
    	cout<<"YES"<<" "<<time-dp[row][coulm]<<endl;
    }

	return 0;
}
