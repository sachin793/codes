#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[25][25];
char symbols[200];
int hash[26]={0},encountered[26]={0};
char start_symbol;

int parseString(char *s,int l)
{
	int i,j;
	int countVar=0,posVar=-1;
	hash[s[0]-'A']++;
	for(i=2;i<l;i++)
	{
		if(s[i]>=65&&s[i]<=90)
		{
			encountered[s[i]-'A']++;
			countVar++;
			posVar=i;
		}
	}
	
	if(countVar>1)
	return 0;
	
	if(posVar==-1)
	return 1;
	if(posVar==2)
	return 2;
	if(posVar==l-1)
	return 3;
	
	return 0;
}


int main()
{
  printf("Enter starting symbol --> ");
  scanf("%c",&start_symbol);
  
  int n;
  printf("Enter the no of productions --> ");
  scanf("%d",&n);
  
  int gtype=-2;
  
  int i,j;
  printf("Enter the productions: \n");
  
  for(i=1;i<=n;i++)
  {
  	printf("%d --> ",i);
	scanf("%s",str[i]);
  }
  int linearity=-1;
  int flag=0;
  for(i=1;i<=n;i++)
  {
    int l=strlen(str[i]);
    int indx=0;
    if(str[i][0]==start_symbol)
    flag=1;
    int check=parseString(str[i],l);
    if(!check)
    {
    	printf("The above Grammar is not regular as it can't be decided whether it is left linear or right linear\n");
    	return ;
    }
   
   if(linearity!=-1&&check!=1&&(linearity!=check))
    {
    	printf("The above Grammar is not regular as it can't be decided whether it is left linear or right linear\n");
    	return ;
    }
    
    if(linearity==-1&&check!=1)
    linearity=check;
    
  }
  
  	for(i=0;i<26;i++)
  	{
  		if(encountered[i]>0&&hash[i]==0)
  		{
  			printf("Undefined grammar for the variable--> %c\nHence Irregular Grammar\n",'A'+i);
  			return ;	
  		}
  		
  	}
  
  
  
  
  
  
 	if(!flag)
 	{
 		printf("There is not start state in the production from where we can start\nHence the Grammar is irregular\n");
 		return ;
 	}
 	if(linearity==-1)
 	printf("The Grammar is regular and it is finite\n");
	else if(linearity==2)
 	printf("The above Grammar is regular and left linear\n");
 	else if(linearity==3)
 	printf("The above Grammar is regular and right linear\n");
 
 return 0;
}
