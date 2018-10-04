    #include<bits/stdc++.h>
    using namespace std;
    typedef pair < long long,long long > pii;
    #define MAX 10000
    vector < pii > graph[MAX];
    #define sc(n) scanf("%lld",&n)
    long long dist[MAX];
    void dijkstra(long long start)
    {
    	priority_queue<pii,vector< pii > ,greater< pii > > q;
    	dist[start]=0;
    	q.push(pii(0,start));
    	while(!q.empty())
    	{
    		long long int weight=q.top().first;
    		long long int node=q.top().second;
    		q.pop();
    		for(long long i=0;i<graph[node].size();i++)
    		{
    			int node1=graph[node][i].first;
    			int we=graph[node][i].second;
    			if((dist[node]+we)<dist[node1])
    			  {
    			  	dist[node1]=(dist[node]+we);
    			  	q.push(pii(dist[node1],node1));
    		     }     
    		}
     
    	}
    }
     
    int main()
    {
    	long long node,edge;
    	sc(node);
    	sc(edge);
    	for(long long i=0;i<edge;i++)
    	{
    		long long u,v,w;
    		sc(u);
    		sc(v);
    		sc(w);
    		graph[u].push_back(pii(v,w));
     
     
    	}
     
    	for(long long i=0;i<=node;i++)
    	{
    		dist[i]=INT_MAX;
    	}
     
    	long long start,end;
    	sc(start);
    	sc(end);
    	dijkstra(start);
    	if(dist[end]>INT_MAX)
    	printf("NO\n");
    	else
    	printf("%lld",dist[end]);
    	return 0;
    }
