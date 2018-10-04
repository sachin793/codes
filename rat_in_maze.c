#include<stdio.h>
#define MAX 100
int cell[MAX][MAX];
int count=0;
int possible(int x,int y,int row,int coulmn,int arr[MAX][MAX])
{
  if(x>=0 && x<row && y>=0 && y<coulmn && arr[x][y]=='#' && cell[x][y]==1)
    return 1;
  else
    return 0;
}

int solve(int x_cur,int y_cur,int row,int coulmn,int x_move[],int y_move[],int arr[MAX][MAX])
{
   
   if(x_cur==row-1 && y_cur==coulmn-1)
     {
      for(int i=0;i<row;i++)
      {
        for(int j=0;j<coulmn;j++)
          printf("%c ",arr[i][j]);
          printf("\n");
      }
      count++;
      return 1;
    }
int i,j;
    for (i = 0; i < 4; ++i)
    {
      /* code */
      int x_next_move=x_cur+x_move[i];
      int y_next_move=y_cur+y_move[i];
        


      if(possible(x_next_move,y_next_move,row,coulmn,arr))
      {
        if(i==0)
        {
          arr[x_cur][y_cur]='R';
        }
        else
          if(i==1)
          {
            arr[x_cur][y_cur]='L';
          }
          else
            if(i==2)
            {
              arr[x_cur][y_cur]='D';
            }
            else
            {
              arr[x_cur][y_cur]='U';
            }
           
             int p=solve(x_next_move,y_next_move,row,coulmn,x_move,y_move,arr);
             
            if(p)
            {
              return 1;
            }
            else
            {
                arr[x_cur][y_cur]='#';

            }
      }

    }
    return 0;
}

int main()
{
   printf("enter row and coulmn\n");
   int row,coulmn;
   int arr[MAX][MAX];
   scanf("%d%d",&row,&coulmn);

     for (int i = 0; i < row; ++i)
    {
      /* code */
      for (int j = 0; j < coulmn; ++j)
      {
        /* code */
        scanf("%d",&cell[i][j]);
      }
    } 

 

    for (int i = 0; i < row; ++i)
    {
      /* code */
      for(int j=0;j<coulmn;++j)
      {
        arr[i][j]='#';
      }
    }

    int x_move[4]={0,0,1,-1};
    int y_move[4]={1,-1,0,0};

    // start from cell[0][0] index

    if(solve(0,0,row,coulmn,x_move,y_move,arr))
    {
      printf("%d\n",count);
      printf("path exist\n");
      for (int i = 0; i < row; ++i)
      {
        /* code */
        for(int j=0;j<coulmn;++j)
        {
          printf("%c  ",arr[i][j]);
        }

        printf("\n");
      }
    }

    else
    {
      printf("path does not exist\n");
    }

    return 0;
}