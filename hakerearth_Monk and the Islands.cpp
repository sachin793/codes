#include<bits/stdc++.h>
using namespace std;
vector <int> ad[10004];
int level[10004];
int visit[10004];
int bsf(int source,int node)
{
	visit[source]=1;
	level[source]=0;
	queue < int > q;
	q.push(source);
	while(!q.empty())
	{
		int to=q.front();
		q.pop();
	     int i;
		for(i = 0;i < ad[ to ].size() ; i++)
		{
			if(visit[ad[to][i]]!=1)
			{
				q.push(ad[to][i]);
				level[ad[to][i]]=level[to]+1;
				visit[ad[to][i]]=1;
			}
		}
	}
	return level[node];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		for(long long i=0;i<100005;i++)
		{
			ad[i].clear();
		}
		int node,edge;
		cin>>node>>edge;
		int u,v;
		for(int i=0;i<10004;i++)
		{
			level[i]=0;
			visit[i]=0;
		}
		

		for(int i=1;i<=edge;i++)
		{
			cin>>u>>v;
			ad[u].push_back(v);
			ad[v].push_back(u);
		}
		
		 int ans=bsf(1,node);
		 cout<<ans<<endl;
	}
}
