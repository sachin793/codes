#include<stdio.h>
int n,m;
int validate(int k,char c,int t[100][100],char a[])
{
	int i;
	for(i=1;i<=m;i++)
	{
		if(a[i]==c)
			return t[k][i];
	}
	return -1;
	
}
int main()
{
	printf("Enter the no. of states - ");
	scanf("%d",&n);
	printf("Enter the no. of input symbols - ");
	scanf("%d",&m);
	printf("Enter the n input symbols - \n");
	
	char a[m+2],cc;
	int i;
	for(i=1;i<=m;i++)
	{
		scanf(" %c",&cc);
		if(cc=='\n')
			break;
		a[i]=cc; 
	}
	
	int t[100][100],fn;
	printf("Enter the no. of final states - ");
	scanf("%d",&fn);
	printf("Enter the final states - ");
	int f[fn+1],j;
	for(i=1;i<=fn;i++)
		scanf("%d",&f[i]);
	printf("Enter the transitions :\n");
	for(i=0;i<n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("(q%d,%c) = q",i,a[j]);
			scanf("%d",&t[i][j]);
		}
	}
	while(1)
	{
		int flag=0;
		printf("\nEnter the string to be checked : ");
		char s[100];
		scanf("%s",s);
		int k=0;
		while(s[i]!='\0')
		{
			k=validate(k,s[i],t,a);
			if(k==-1)
			{
				printf("%s - REJECTED\n",s);
				flag=1;
				break;
			}
			i++;
		}
		if(flag==0)
		{
			for(i=1;i<=fn;i++)
				if(k==f[i])
					flag=1;
			if(flag==1)
				printf("%s - ACCEPTED\n",s);	
			else
				printf("%s - REJECTED\n",s);
		}
		char op;
		printf("Enter Y to continue and N to exit : ");
		scanf(" %c",&op);
		if(op=='N')
			break;
	}
	return 0;
}

