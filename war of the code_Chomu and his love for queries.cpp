#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007
ll int S;
// int cmp(pair < ll, ll > a , pair < ll, ll > b)
// {
// 	if(a.first/S!=b.first/S)
// 	return a.first/S<b.first/S;
// 	else
// 	return a.second
	
// }


typedef struct NODE
{
	int l,r;
	int idx;
} query;

bool cmp(query a,query b)
{
	if(a.l/S!=b.l/S)
	return a.l/S<b.l/S;
	return a.r<b.r;
}

int main()
{
	ll n;
	cin>>n;
	ll a[n];
	S=ceil(sqrt(n));
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}

	ll q;
	cin>>q;
	int mp[200005]={0};
	ll count=0;

	ll start=-1;
	ll end=-1;
	query s[q];
	
	for(ll i=0;i<q;i++)
	{
		cin >> s[i].l >> s[i].r;
		s[i].idx=i;
	}
	sort(s,s+q,cmp);
	ll int calculate=0;
	long long ans[q]={0};
	for(ll i=0;i<q;i++)
	{
		
		
	          ll l=s[i].l;
	          ll r=s[i].r;
	          ll index=s[i].idx;
	        
		while(end<r)
		{
           
            
            end++;
            ll p=count-(mp[a[end]+100000]);
            calculate+=(p);
            count++;
            mp[a[end]+100000]++;
		}
		// if(i==2)
		// cout<<calculate<<endl;

		while(end>r)
		{
           	    //	cout<<count<<endl;
             end--;
             count--;
             mp[a[end+1]+100000]--;
             ll p=(count-mp[a[end+1]+100000]);
             calculate-=p;
            // cout<<ans<<endl;
            
		}
                  
		while(start<(l-1))
		{
			start++;
			count--;
			mp[a[start]+100000]--;
			ll p=count-(mp[a[start]+100000]);
			calculate-=(p);
			
		}
		// if(q==0)
		// cout<<ans<<endl;
	
		while(start>=(l))
		{
		
		
			ll p=count-mp[a[start]+100000];
			calculate+=p;
			mp[a[start]+100000]++;
			start--;
		            count++;
		
		}
       ans[index]=calculate;
      //if(i==1)
      //cout<<start<<" "<<end<<endl;
      //if(i==1)
      //cout<<ans[index]<<endl;
       
	}

	for(int i=0;i<q;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}