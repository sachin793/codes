#include<bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  int index;
  struct node* parant;
  struct node* lchild;
  struct node* rchild;

};

void fun(struct node* root,int val)
{

       if(root==NULL)
       {
            struct node* new1 = (struct node*)malloc(sizeof(struct node));
            root=new1;
            root->index=0;
            root->data=val;
            root->parant=NULL;
            root->lchild=NULL;
            root->rchild=NULL;           
       }
       else
       {

           struct node* ptr=root;
           struct node* par=root;
           while(ptr!=NULL)
           {
             par=ptr;
            if(val>ptr->data)
              { 
                ptr=ptr->rchild;
              }
            else
              ptr=ptr->lchild;
           }

           if(par->data<val)
           {
               struct node* new1 = (struct node*)malloc(sizeof(struct node));
               par->rchild=new1;
               new1->parant=par;
               new1->data=val;
               new1->index=0;
               new1->lchild=NULL;
               new1->rchild=NULL; 
           }
           else
           {
               struct node* new1 = (struct node*)malloc(sizeof(struct node));
               par->lchild=new1;
               new1->parant=par;
               new1->data=val;
               new1->index=0;
               new1->lchild=NULL;
               new1->rchild=NULL; 
           }

       }
       
}


void print(struct node* pt)
{
  if(pt==NULL)
    return ;
  else
    {
      print(pt->lchild);
      printf("%d  ",pt->data);
      print(pt->lchild);
    }

}


int main()
{
  int n;
  printf("enter total number of elemnt\n");
  cin>>n;
    printf("enter those element\n");
  int a[n];
  
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  struct node * root=NULL;
  for(int i=0;i<n;i++)
  {
    fun(root,a[i]);
  }
  
   struct node* v=root;
   print(v);
   return 0;
}
