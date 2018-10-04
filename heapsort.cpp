#include<stdio.h>
#define sc(n) scanf("%d",&n)

void maxheapfy(int a[],int i,int n)
{

	int biggest=i;
	int lc=2*i;
	int rc=2*i+1;
	
	if(a[lc]>a[biggest] && lc<=n)
      biggest=lc;
	  
	if(a[rc]>a[biggest] && rc<=n)
	  biggest=rc;
	  
	  if(i!=biggest)
	  	 {
	  	    int p=a[i];
	  	    a[i]=a[biggest];
	  	    a[biggest]=p;
	  	    
	  	    maxheapfy(a,biggest,n);
		 }
}

void build_maxheap(int a[],int n)
{
	int parant=n/2;
	while(parant>0)
	{
		maxheapfy(a,parant,n);
		parant--;
		
	}

}

void heapsort(int a[],int n)
{
	build_maxheap(a,n);
	int b[n+1],k=1;
	while(n>0)
	{
	  	b[k++]=a[1];
	  	int p=a[n];
	  	a[n]=a[1];
	  	a[1]=p;
	  	n--;
	  	maxheapfy(a,1,n);
	  	
	} 
	int i;
	for(i=1;i<=n;i++)
	{
		a[i]=b[i];
	}
}

int main()
{
	int n;
	printf("enter value of n\n");
	sc(n);
	printf("enter value of element \n");
	int a[n+1],i;
	for(i=1;i<=n;i++)
	{
		sc(a[i]);
	}
	 heapsort(a,n);
	printf("sorted array is\n");
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	
	return 0;
	
}
