#include<bits/stdc++.h>
using namespace std;
#define long long long long
#define INF 1000000007
#define MOD 1000000007

vector<vector<long long> >fec(5003,vector<long long>(5003,0)); 
void fun()
{
	for(int i=0;i<5001;i++)
	{
		for(int j=0;j<5001;j++)
		{
			if(i==0 && j==0)
            {
				fec[i][j]=1;
            }
			else if(i==0)
            {
			 fec[i][j]=0;
            }
			else if(j==0)
			{
                 fec[i][j]=1;
            }
			else
            {
				fec[i][j]=((fec[i-1][j]%(INF-1))+(fec[i-1][j-1]%(INF-1)))%(INF-1);
            }
		}
	}
}
 
 
long long pow1(long long a,long long b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a%MOD;
    }
    else
    {
        long long p=pow1(a,b/2);
        p=p%MOD;
        p=(p*p)%MOD;
        if(b%2==1)
        {
            p=(p*(a%MOD))%MOD;
        }
        return (p%MOD);
    }
}
 
int main()
{
 
    long long t;
    cin>>t;
 
    fun();
  //  cout<<fec[3][2]<<endl;
    while(t--)
    {
    	long long n,k;
    	cin>>n>>k;
    	long long arr[n];
 
    	for(long long i=0;i<n;i++)
    	{
    		cin>>arr[i];
    	}
 
        sort(arr,arr+n);
        long long sum=1;
 
        for(int i=1;i<n-1;i++)
       { 	
 
            long long val = (fec[n-1][k-1]-fec[n-i-1][k-1]-fec[i][k-1])%(INF-1);
            sum = ((sum%INF)*(pow1(arr[i],val)%INF))%INF;
 
        }
 
        cout<<sum%INF<<endl;
 
     }
 
    return 0;
}