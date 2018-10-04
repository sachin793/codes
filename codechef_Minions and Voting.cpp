#include<bits/stdc++.h>
using namespace std;
long long MA=100005;
long long tree[100005]={0};
long long sum[100005]={0};
void updateRange1(long long l,long long r,long long end)
{
     //cout<<end<<endl;
     tree[l]=tree[l]+1;
     if(r+1<=end)
     tree[r+1]=tree[r+1]-1;
}
void updateRange2(long long l,long long r,long long end)
{
     //cout<<end<<endl;
     sum[l]=sum[l]+1;
     if(r+1<=end)
     sum[r+1]=sum[r+1]-1;
}

void update1(long long n)
{
    for(long long i=1;i<n;i++)
    {
    	tree[i]=tree[i-1]+tree[i];
    }
}

void update2(long long n)
{
    for(long long i=1;i<n;i++)
    {
    	sum[i]=sum[i-1]+sum[i];
    }
}

void fun1(long long a[],long long dis[],long long low,long long high)
{
	long long mid;
	long long start=low;
	long long end=high;
	long long ans=0;
    while(low<=high)
    {
          mid=(low+high)/2;
          if((dis[mid]-dis[start+1])<=a[start])
          {
               ans=mid;
               low=mid+1;
          }
          else
          {
          	 high=mid-1;
          	 
          }
    }
 
    updateRange1(start+1,ans,end);
}

void fun2(long long b[],long long ma[],long long low,long long high)
{
	long long mid;
	long long start=low;
	long long end=high;
	long long ans=0;
    while(low<=high)
    {
          mid=(low+high)/2;
          if((ma[mid]-ma[start+1])<=b[start])
          {
               ans=mid;
               low=mid+1;
          }
          else
          {
          	 high=mid-1;
          	 
          }
    }
 
    updateRange1(start+1,ans,end);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{

		long long n;
		cin>>n;
		
		for(long long i=0;i<n;i++)
		{
			tree[i]=0;
			sum[i]=0;
		}
	
		long long a[n];
		for(long long i=0;i<n;i++)
		{
			cin>>a[i];
		}
		long long b[n];
		for(long long i=0;i<n;i++)
		{
			b[i]=a[n-i-1];
		}
		
		// for(long long i=0;i<n;i++)
		// {
	 //               cout<<a[i]<<" ";
		// }
  //        cout<<endl;           
	    long long dis[n];
	    long long ma[n];
	         dis[0]=0;
	         dis[1]=0;
	         ma[n-1]=0;
	         ma[n-2]=0;
		for(long long i=2;i<n;i++)
		{
                           dis[i]=dis[i-1]+a[i-1];
                           
		}
		
		for(long long i=2;i<n;i++)
		{
                           ma[i]=ma[i-1]+b[i-1];
                           
		}
		
		
     
  //                       for(long long i=0;i<n;i++)
		// {
		// cout<<ma[i]<<" ";
		// }
  //            cout<<endl;           
		for(long long i=0;i<n-1;i++)
		{
			fun1(a,dis,i,n-1);
		}
		update1(n);
		for(long long i=0;i<n-1;i++)
		{
			fun2(b,ma,i,n-1);
		}
		update2(n);
		for(long long i=0;i<n;i++)
		{
			cout<<tree[i]+sum[n-i-1]<<" ";
		}
		cout<<endl;


	}
	return 0;
}
