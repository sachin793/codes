#include<bits/stdc++.h>
using namespace std;

int parition(int a[],int low,int high)
{
	int lp=low-1;
	for(int i=low;i<high;i++)
	{
		if(a[i]<a[high])
		{
			lp++;
			swap(a[lp],a[i]);
		}
	}

	
	swap(a[high],a[lp+1]);
	return lp+1;
}

void fun(int a[],int low,int high)
{
   if(low<high)
   {
   	  int mid=(low+high)/2;
   	  int val=parition(a,low,high);
   	  fun(a,low,val-1);
   	  fun(a,val+1,high);
   }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }

   fun(a,0,n-1);
   for(int i=0;i<n;i++)
   	cout<<a[i]<<" ";

   return 0;
 }