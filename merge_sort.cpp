#include<stdio.h>
#define sc(n) scanf("%d",&n)
#define INT_MAX 1e9+7
void merge(int a[],int low,int mid,int high)
{
	int nl=(mid-low+1);
	int nr=(high-mid);
	int tl[nl+2];
	int tr[nr+2];
	int i;
	int c=1;
	int d=1;
	for(i=low;i<=mid;i++)
	{
		tl[c++]=a[i];
	}
	for(i=mid+1;i<=high;i++)
	{
		tr[d++]=a[i];
	}
	
	tl[nl+1]=INT_MAX;
	tr[nr+1]=INT_MAX;
	c=d=1;
	for(i=low;i<=(high);i++)
	{
		if(tl[c]<tr[d])
		  a[i]=tl[c++];
		  
		  else
		  a[i]=tr[d++];
	}
	
}

void merge_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		
		merge(a,low,mid,high);
		
	}
	
}

int main()
{
	printf("enter value of total elemment\n");
	int n,i;
	sc(n);
	printf("enter element one by one \n");
	int a[n+1];
	for(i=1;i<=n;i++)
	{
	  sc(a[i]);	
	}
	merge_sort(a,1,n);
	printf("sorted array is\n");
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
