#include<stdio.h>
#define q 100
int ans[q][q];
bool possible(int x,int y,int row,int coulmn)
{
  if(x>=1 && x<=row && y>=1 && y<=coulmn && ans[x][y]==-1)
    return true;

  else
    return false;
}

bool solve(int count,int cur_x,int cur_y,int x_move[],int y_move[],int row,int coulmn)
{
   if(count==(row*coulmn+1))
    return true;

  for(int i=0;i<8;i++)
  {
     int next_x_move=cur_x+x_move[i];
     int next_y_move=cur_y+y_move[i];

     if(possible(next_x_move,next_y_move,row,coulmn))
     {
        
      ans[next_x_move][next_y_move]=count;
      bool val=solve(count+1,next_x_move,next_y_move,x_move,y_move,row,coulmn);
      if(val)
        return true;
      else
      {
        ans[next_x_move][next_y_move]=-1;
      }
     }
  }

  return false;
}

int main()
{
  
  // printf("enter size of row and coulmn\n");
   int n,m;
   scanf("%d%d",&n,&m);
   for(int i=0;i<=n;i++)
   {
    for(int j=0;j<=m;j++)
    {
      ans[i][j]=-1;
    }
   }
 
   int x_move[8]={1,-1,2,2,1,-1,-2,-2};
   int y_move[8]={2,2,1,-1,-2,-2,1,-1};
   int count=1;
   ans[1][1]=count;
   bool finans=solve(count+1,1,1,x_move,y_move,n,m);
   if(finans)
    {
       printf("solution exit\n");
       for(int i=1;i<=n;i++)
       {
            for(int j=1;j<=m;j++)
            {
              printf("%d  ",ans[i][j]);
            }
            printf("\n");
       }
    }
    else
    {
      printf("solution does not exit\n");
    }

    return 0;

}