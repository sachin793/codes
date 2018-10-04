#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007
vector< pair < ll ,ll > > tree(4*100001);
ll arr[100005];
void build(int node, int start, int end)
{
    if(start == end)
    {
        
        tree[node]={1,arr[start]};
        return ;
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
       if(tree[node<<1].second>=tree[node<<1|1].second)
       {
       		tree[node]={tree[node<<1].first,tree[node<<1].second};
       }
       else
       {
       		tree[node]={tree[node<<1].first+tree[node<<1|1].first,tree[node<<1|1].second};
       }
    }
}


pair<ll,ll>  query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return {0,0};
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    pair<ll,ll> p1 = query(2*node, start, mid, l, r);
    pair<ll,ll> p2 = query(2*node+1, mid+1, end, l, r);
    

    if(p1.second>=p2.second)
    {
    	return p1;
    }
    else
    {
    	return {p1.first+p2.first,p2.second};
    }
}

int main()
{
	ll n,q;
	cin>>n>>q;

	for(ll i=0;i<n;i++)
	{
		cout<<arr[i];
	}

	ll q;
	cin >> q;

	ll ans=0;
	while(q--)
	{
		ll a,b;
		cin >> a >> b;
		a=(a+ans)%n;
		b=(b+ans)%n;
		if(a>b)
			swap(a,b);
		pair<ll,ll> p=query(1,0,n-1,a,b);
		cout << p.first << endl;
	}

	return 0;
}