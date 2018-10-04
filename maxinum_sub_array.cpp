#include<bits/stdc++.h>
using namespace std;

int fun1(int a[],int low,int mid,int high)
{
	int max=INT_MIN;
	int sum=0;
	for(int i=mid;i>=0;i--)
	{
		sum+=a[i];
		if(sum>max)
			max=sum;
	}

	int max1=INT_MIN;
	int sum1=0;
	for(int i=mid+1;i<=high;i++)
	{
		sum1+=a[i];
		if(sum1>max1)
			max1=sum1;
	}

	return max1+max;
}

int fun(int a[],int low,int high)
{
	if(low==high)
		return a[low];

	else
	{
		int mid=(low+high)/2;
		
        int p=fun(a,low,mid);
        int b=fun(a,mid+1,high);
        int c=fun1(a,low,mid,high);

        return max(p,max(b,c));
	}
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   	cin>>a[i];

   int ans=fun(a,0,n-1);
    cout<<ans<<endl;
}