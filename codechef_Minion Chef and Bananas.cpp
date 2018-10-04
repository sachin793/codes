#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,h;
		cin>>n>>h;
		long long a[n];
		long long count=0;
		long max=INT_MIN;
		for(long long i=0;i<n;i++)
		{
			cin>>a[i];
			count+=a[i];
            if(a[i]>max)
            	max=a[i];
		}
     
       
		long long min=count/h;
		for(long long i=min;i<=max;i++)
		{
			long long sum=0;
			for(long long j=0;j<n;j++)
			{
                  if(a[j]%i==0)
                  {
                       sum+=(a[j]/i);
                  }
                  else
                  {
                       sum+=((a[j]/i)+1);
                  }
			}

			if(sum==h)
			{
                cout<<i<<endl;
                break;
                
			}
		} 

        
	}
	return 0;
}
