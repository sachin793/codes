#include<stdio.h>
int main()
{
   int right=0,left=0,flag=0,nfa=0;
   while(1)
   {   
       char s[100];
       printf("Enter the Production Rules and Q:to quit\n");
       scanf("%s",s);
       if(s[0]=='Q')
         break;
       if(!((s[0]>='A'&&s[0]<='Z')&&s[1]=='-'&&s[2]=='>'&&s[3]!='\0'))
       {
          flag=1;
          printf("Enter Valid Moves like A->a or A->e or A->aB or A->Ba or A->B or A->a etc\n");
          continue;
       }
       if(s[3]=='e')
       {
          if((s[4]>='A'&&s[4]<='Z')&&s[5]=='\0')
           {
               printf("Nfa Move\n");
               nfa=1;
           }
          else if(s[4]!='0')
               flag=1;
          continue;
       }
       if(s[3]<='z'&&s[3]>='a')
       {
           if((s[4]>='A'&&s[4]<='Z')&&s[5]=='\0')
            {
              if(left==0)
                 right=1,printf("Right production\n");
              else
                 flag=1,printf("Previously Left Production is used\n");
              continue;
            }
           if(s[4]!='\0')
              flag=1;
           continue;
       }
       if(s[3]>='A'&&s[3]<='Z')
       {
           if((s[4]>='a'&&s[4]<='z')&&s[5]=='\0')
           {
              if(right==0)
                 left=1,printf("Left production\n");
              else
                 flag=1,printf("Previously Right Production is used\n");
              continue;
           }

           if(s[4]!='\0')
              {
                  flag=1;
              }
           nfa=1;
           printf("Nfa Move\n");
       }
   }
   if(flag==1)
     printf("Not Regular Grammar\n");
   else
   {
      if(nfa==1)
         printf("NFA ");
      if(left==1)
         printf("Left Linear ");
      else
         printf("Right Linear ");
      printf("Regular Grammar\n");
   }
  return 0;
}

