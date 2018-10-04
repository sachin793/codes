#include<bits/stdc++.h>
using namespace std;
long long int MOD= 1e9+7;
void fun(long long a[2][2],long long n)
{
	long long m[2][2]={{2,2},{1,0}};

	if(n==0 || n==1)
		return;
    fun(a,n/2);

      mul(a,a);
    if(n%2==1)
     mul(a,m);

}

void mul(long long a[2][2],long long p[][])
{
	a[0][0]=(((a[0][0]*p[0][0])%MOD+(a[0][1]*p[1][0])%MOD)%MOD);
	a[0][1]=((a[0][0]*p[0][1])%MOD+(a[0][1]*p[1][1])%MOD)%MOD;
	a[1][0]=((a[1][0]*p[0][0])%MOD+(a[1][1]*p[1][0])%MOD)%MOD;
	a[1][1]=((a[1][0]*p[0][1])%MOD+(a[1][1]*p[1][1])%MOD)%MOD;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		if(n==1)
			cout<<1<<endl;
		else
			if(n==2)
				cout<<3<<endl;
			else
			{
				long long t[2][2]={{2,2},{1,0}};
				fun(t,n-2);
			}

			long long ans=((t[0][0]*3)%MOD + (t[0][1]*1)%MOD)%MOD;
			cout<<ans<<endl;
	}
	return 0;
}