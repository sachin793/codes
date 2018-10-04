#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long a[n];
	long long b[n];
	long long p=0;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<0)
			b[p++]=a[i];
	}
   long long x;
   cin>>x;

   sort(b,b+n);
   long long sum=0;
   long long count=0;
   long long val=p;
   for(long long i=p-1;i>=0;i--)
   {
   	   if(val>x)
   	   {
          sum+=((-b[i]+count)*x);
          val--;
          count+=(-b[i]+count);
   	   }
   	   else
   	   {
           sum+=((-b[i]+count)*1);
           val--;
           count+=(-b[i]+count);
   	   }
   }
   cout<<sum<<endl;
   return 0;

}