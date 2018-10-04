#include<stdio.h>
#include<string.h>
int top=-1;
char stk[100];

void push(char c)
{
   stk[++top]=c;
}

void pop()
{
	top--;
}

int main()
{
	printf("enter string\n");
	char st[100];
    scanf("%s",st);
    int size=strlen(st);
    int temp=0;
    int flag=0;
    push('z');
  //  printf("%c",stk[top]);
  int i;
    for(i=0;i<size;i++)
    {
          if(stk[top]=='z' && st[i]=='a' && flag==0)
          	push(st[i]);
          else
          	if(stk[top]=='a' && st[i]=='a' && flag==0)
          		push(st[i]);
          	else
          		if(stk[top]=='a' && st[i]=='b' )
          		{
          			flag=1;
          			temp=1;
          			pop();
          		}
          	

    }

    if(stk[top]=='z' && temp==1)
    {
    	temp=2;
    	pop();
    }

    if(top==-1 && temp==2)
    	printf("accepted\n");
    else
    	printf("not accepted\n");

    return 0;
}
