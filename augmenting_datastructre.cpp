#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node* left;
	struct node* right;
	struct node* par;
	int size;
};

struct node* binarysearchtree(struct node* root,int value)
{
	
     struct node* ptr=root;
     struct node* par;
     if(root==NULL)
     {
     	root=(struct node*)malloc(sizeof(struct node));
        root->info=value;
        root->left=root->right=NULL;
        root->size=0;
        root->par=NULL;     
     }
     else     
     {
        while(ptr!=NULL)
        {
        	if(ptr->info==value)
     		{
     		printf("wrong input\n");
     		return root;
     		}
     	
     		else
     		{
          		par=ptr;
     			if(ptr->info>value)
     			{
     				ptr=ptr->left;
     			}
     			else
     			{
     				ptr=ptr->right;
     			}
        	}
     	}

     if(par->info>value)
     {
            struct node* temp =(struct node*) malloc(sizeof(struct node));
            par->left=temp;
            temp->info=value;
            temp->left=temp->right=NULL;
            temp->par=par;
            temp->size=0;
     }
     else
     {
            
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            par->right=temp;
            temp->info=value;
            temp->left=temp->right=NULL;
            temp->par=par;
            temp->size=0;

     }
 }

return root;

     
}


void inorder(struct node* root)
{
	if(root==NULL)
	{
		return ;
	}
	else
	{
		 
          inorder(root->left);
           printf("%d ",root->info);
          inorder(root->right);
          
	}
}

int main()
{


       printf("enter total element \n");
       int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++)
        {
        	scanf("%d",&a[i]);
        }
        struct node* root=NULL;
        root=NULL;
        for(int i=0;i<n;i++)
        {
             root=binarysearchtree(root,a[i]);
        }
       
       inorder(root);
       return 0;
}
