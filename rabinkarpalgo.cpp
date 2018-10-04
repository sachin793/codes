#include<bits/stdc++.h>
using namespace std;
int piindex[100]={0};

void pi(string p)
{
    piindex[0]=0;
    int size=p.length();
    int q=1;
    int k=0;

    while(q<size)
    {
      if(p[q]==p[k])
      {
        piindex[q]=k+1;
            q++;
            k++;
      }

      else
      {
        if(k)
        {
          k=piindex[k];
        }
        else
        {
          piindex[q]=0;
          q++;
        }
      }
    }
}


int main()
{
  printf("enter pattern\n");
  string p;
  cin>>p;

  printf("enter text\n");
  
  char t[100];
  scanf(" %[^\t\n]s",&t);
  
  printf("%s\n",t);
  
  pi(p);

    for(int i=0;i<p.length();i++)
    cout<<piindex[i]<<" ";
    cout<<endl;
  int i=0;
  int j=0;
  int flag=0;
  while(i<sizeof(t))
  {
       if(t[i]==p[j])
       {
        i++;
        j++;
       }
       else
       {
          if(j)
          {
            j=piindex[j];     
        }
        else
        {
          i++;
      }
       }

       if(j==p.length())
       {
         flag=1;
         printf("pattern found\n");
         break;
       }
  }
  if(flag==0)
    printf("pattern not found\n");

  return 0;
}

