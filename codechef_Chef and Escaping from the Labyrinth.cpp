#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int r,c;
		cin>>r>>c;
		int level[30005][30005]={0};
		vector < pair < int,int> >v;
		int a[r+1][c+1];
		char b[r+1][c+1];
		for(int i=0;i<=r;i++)
		{
			for(int j=0;j<=c;j++)
			{
				b[i][j]='N';
				
			}
		}
		
		for(int i=0;i<=r;i++)
		{
			for(int j=0;j<=c;j++)
			{
				cin>>a[i][j];
				if(a[i][j]!=0 && a[i][j]!=-1)
				{
					v.push_back({i,j});
					level[i][j]=0;
					
				}
				if(a[i][j]==-1)
				{
					b[i][j]='N';
				}
				
			}
		}
		
		queue< pair < int,int > > q;
		while(v.size()!=0)
		{
		  q.push({v[0].first,v[0].second});
		  
		  int visit[30005][30005]={0};
		  visit[v[0].first][v[0].second]=1;
		  v.erase(v.begin());
		  while(!q.empty())
		  {
		  	   int x=q.front().first;
		  	   int y=q.front().second;
		  	   
		  	   q.pop();
		  	    if((x-1)>=1 && a[x-1][y]!=-1 && (level[x][y]+1)<=5)
		  	           {
		  	        	level[x-1][y]=(level[x][y]+1);
		  	        	visit[x-1][y]=1;
		  	        	b[x-1][y]='Y';
		  	        	q.push({x-1,y});
		  	        	
				}
				
				if((x+1)<=r && a[x+1][y]!=-1 && (level[x][y]+1)<=5)
		  	           {
		  	        	level[x+1][y]=(level[x][y]+1);
		  	        	visit[x+1][y]=1;
		  	        	b[x+1][y]='Y';
		  	        	q.push({x+1,y});
				}
				if((y-1)>=1 && a[x][y-1]!=-1 && (level[x][y]+1)<=5)
		  	            {
		  	        	level[x][y-1]=(level[x][y]+1);
		  	        	visit[x][y-1]=1;
		  	        	b[x][y-1]='Y';
		  	        	q.push({x,y-1});
				}
				if((y+1)<=c && a[x][y+1]!=-1 && (level[x][y]+1)<=5)
		  	           {
		  	        	level[x][y+1]=(level[x][y+1]+1);
		  	        	visit[x][y+1]=1;
		  	        	b[x][y+1]='Y';
		  	        	q.push({x,y+1});
				}
							
				
		  }
		  
		  for(int i=1;i<=r;i++)
		  {
		  	for(int j=1;j<=c;j++)
		  	{
		  		cout<<b[i][j];
			  }
			  cout<<endl;
		  }
	}
	return 0;
}
