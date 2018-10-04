
// sachin agarwal(20164006)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INFINITE 1000
int ta[100],ns=0;
int linearSearch(int a[],int n,int k)
{
	int i;
	for(i=0;i<n;i++)           
	{
		if(a[i]==k)
			return i;     // comparing value of smallest value of array with element of array and return that index
	}	
}
int getSecondSmall(int a[],int n)
{
	if(n==1)
		return a[n-1];
	int i,s=0,na[100],small;
	for(i=0;i<n;i+=2)    // compare element of array with its neighbour element
	{
		if(i==n-1)
		{
			na[s]=a[i];
			s++;
		}
		else if(i%2==0)
		{
			if(a[i]>a[i+1])
				na[s]=a[i+1];
			else
				na[s]=a[i];
			s++;
		}	
	}
	small=getSecondSmall(na,s);    // again function calling in new array finally give smallest element
	i=linearSearch(na,s,small);    // function calling for find out index of smallest element
	if(i%2==0)                     
		ta[ns]=na[i+1];       
	else
		ta[ns]=na[i-1];
		ns++;
	ta[0]=INFINITE;
	return small;
}
int main()
{
	int a[100],ca[100],i,n,small,secondSmall;
	printf("Enter The size of Array \n"); 
	scanf("%d",&n);
	printf("Enter The Elements \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);		
	}
	small=getSecondSmall(a,n);  // function calling which will return smallest number in array
	i=linearSearch(a,n,small);
        if(i%2==0)
                ta[ns]=a[i+1];    
        else
                ta[ns]=a[i-1];
                ns++;
	for(i=0;i<ns;i++)          // creating a new array in which those are element will be stored which is compared by smallest element
               ca[i]=ta[i]; 
	secondSmall=getSecondSmall(ca,ns);	
	printf("\nSmall : %d\nSecondSmall : %d\n",small,secondSmall);
}

