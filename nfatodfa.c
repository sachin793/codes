#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 10
struct node
{
    int n;
    int a[M];
}nfa[M][M];
struct n
{
    int s;
    int a[M];
}dfa[1024];
int Dfa[1024][M],states,symbols,finaln,finald,fd[1024],fn[M],sd;
int isSet(int n,int k)
{
    if (n & (1 << (k)))
    return 1;
    return 0;
}
void df()
{   
    int i=3,j=0,k=0,l;
    for(i=0;i<pow(2,states);i++)
    {
        for(j=0;j<symbols;j++)
        {
            Dfa[i][j]=0;
            for(k=0;k<states;k++)
            {
                if(isSet(i,k))
                {
                    //printf("%d ",k);
                    for(l=0;l<nfa[k][j].n;l++)
                    {
                        //printf("\nnfa[k][j].a[l]=%d\t",nfa[k][j].a[l]);
                        //printf("%d\n",(int)pow(2,nfa[k][j].a[l]));
                        Dfa[i][j]=Dfa[i][j] | (int)pow(2,nfa[k][j].a[l]);
                        //printf("%d ",Dfa[i][j]);
                    }
                    //printf("\n");
                }
            }
        }
    }
    for(i=0;i<pow(2,states);i++)
    {
        printf("%d\t",i);
        for(j=0;j<symbols;j++)
        {
            printf("%d\t",Dfa[i][j]);
        }
        printf("\n");
    }
}
int isPresent(int s)
{
    int i;
    for(i=0;i<sd;i++)
    if(dfa[i].s==s)
    return 1;
    return 0;
}
void add(int i)
{
    int j;
    dfa[sd].s=i;
    for(j=0;j<symbols;j++)
    dfa[sd].a[j]=Dfa[i][j];
    sd=sd+1;
}
void N_D()
{
    int i,j,k,cur[M],co=0;
    sd=1;
    dfa[0].s=1;
    for(j=0;j<symbols;j++)
    {
        dfa[0].a[j]=Dfa[1][j];
        cur[j]=Dfa[1][j];
    }
    /*for(j=0;j<symbols;j++)
        printf("%d ",cur[j]);//=dfa[co].a[j];
    printf("\n");*/
    while(co<sd)
    {
        for(i=0;i<symbols;i++)
        {
            if(!isPresent(cur[i]))
            {
                add(cur[i]);
            }
        }
        for(j=0;j<symbols;j++)
        cur[j]=dfa[co+1].a[j];
        co++;
        /*for(j=0;j<symbols;j++)
        printf("%d ",cur[j]);//=dfa[co].a[j];
    printf("\n");*/
    }
}
void print()
{
    int i,j,k,c=0;
    printf("Number of states in DFA=%d\n",sd);
    for(i=0;i<sd;i++)
    {
        printf("q%d\t|",i);
        for(j=0;j<symbols;j++)
        {
            c=0;
            printf("q");
            for(k=0;k<states;k++)
            if(isSet(dfa[i].a[j],k))
            {
                printf("%d",k);
                c++;
            }
            if(c==0)
            printf("phi");
            printf("\t|");
        }
        printf("\n");
    }
}
void read()
{
    int i,j,k;
    printf("Enter the number of states\n");
    scanf("%d",&states);
    printf("Enter the number of symbols\n");
    scanf("%d",&symbols);
    printf("Enter the transition\n");
    for(i=0;i<states;i++)
    {
        for(j=0;j<symbols;j++)
        {   
            printf("Enter the number of transitions in (q%d,%d)\n",i,j);
            scanf("%d",&nfa[i][j].n);
            for(k=0;k<nfa[i][j].n;k++)
            {
                scanf("%d",&nfa[i][j].a[k]);
            }
        }
    }
    printf("Enter the number of final states\n");
    scanf("%d",&finaln);
    printf("Enter the final states\n");
    for(i=0;i<finaln;i++)
    {
        scanf("%d",&fn[i]);
    }
}
int main()
{
    read();
    df();
    N_D();
    print();
    return 0;
}

