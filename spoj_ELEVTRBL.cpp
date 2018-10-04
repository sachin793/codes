    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    ll int f,s,g,u,d;
    bool visited[1000005];
    ll int spath[1000005]={0};
    void bfs(ll int start)
    {
    	queue<ll int > q;
    	q.push(start);
    	visited[start]=true;
    	while(!q.empty())
    	{
    		ll int curr=q.front();
    		q.pop();
    		if(((curr+u)<=f)&&(visited[curr+u]==false))
    		{
    			visited[curr+u]=true;
    			spath[curr+u]=spath[curr]+1;
    			
    			if((curr+u)==g)
    			return;
    			
    			q.push(curr+u);
    		}
    		if(((curr-d)>=1)&&(visited[curr-d]==false))
    		{
    			visited[curr-d]=true;
    			spath[curr-d]=spath[curr]+1;
    			
    			if((curr-d)==g)
    			return;
    			q.push(curr-d);
    		}
    	}
    }
    int main()
    {
    	scanf("%lld %lld %lld %lld %lld",&f,&s,&g,&u,&d);
     
    	if(s==g)
    	printf("0\n");
    	else
    	{
    			bfs(s);
    			if(visited[g]==true)
    			printf("%lld\n",spath[g]);
    			else
    			printf("use the stairs\n");
    	}
    } 
