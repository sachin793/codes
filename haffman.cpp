#include<stdio.h>
#include<stdlib.h>
typedef struct  node
{
	char c;
	int freq;
	struct node* lchild,*rchild;
} NODE ;

int n,size;
int stack[100]={0};
char c[100];
int fre[100]={0};
NODE* heap[100];


NODE* newNode(int f,char y)
{
	//printf("**%c%d\n",y,f);
	NODE* new1=(NODE*)malloc(sizeof(NODE));
	new1->freq=f;
	new1->c=y;
	new1->lchild=new1->rchild=NULL;
	return new1;
}


void minHeapify(int idx)
{
	NODE * new1=heap[idx];
	int lc=2*idx;
	int rc=lc+1;
	int smallest=idx;
	if(lc<=size&&((heap[lc]->freq)<(heap[smallest]->freq)))
	{
		smallest=lc;
	}
	if(rc<=size&&((heap[rc]->freq)<(heap[smallest]->freq)))
	{
		smallest=rc;
	}
	
	if(smallest!=idx)
	{
		NODE* temp=heap[idx];
		heap[idx]=heap[smallest];
		heap[smallest]=temp;
		
		minHeapify(smallest);
	}
	return ;
}

void buildMinHeap()
{
	int i;
	
	for(i=size/2;i>=1;i--)
	{
		//printf("*%d\n",i);
		minHeapify(i);
	}
}

void fillHeap()
{
	int i;
	for(i=1;i<=n;i++)
	{
		heap[i]=newNode(fre[i],c[i]);
		//printf("%d %c\n",fre[i],c[i]);
	}
}

NODE * extractMin()
{
	NODE* temp=heap[1];
	heap[1]=heap[size];
	heap[size]=temp;
	size--;
	//printf("*%d\n",size);
	minHeapify(1);
	return temp;
}

void insert(NODE * new1)
{
	size++;
	heap[size]=new1;
	int k=size;
	while(k>1&&(heap[k]->freq)<(heap[k/2]->freq))
	{
		NODE* temp=heap[k];
		heap[k]=heap[k/2];
		heap[k/2]=temp;
		k/=2;
	}
	return ;
}

NODE * HauffmanCoding()
{
	
	while(size!=1)
	{
		//printf("*%d\n",size);
		NODE* n1=extractMin();
		NODE * n2=extractMin();
		printf("**%d %d\n",(n1->freq),(n2->freq));
		NODE* ne=newNode(((n1->freq)+(n2->freq)),'*');
		//printf("***%d\n",size);
		ne->lchild=n1;
		ne->rchild=n2;
		//printf("**%d\n",size);
		insert(ne);
	}
	return heap[1];
}

void printCodes(NODE* root,int top)
{
	if(root->lchild)
	{
		stack[top]=0;
		printCodes(root->lchild,top+1);
	}
	
	if(root->rchild)
	{
		stack[top]=1;
		printCodes(root->rchild,top+1);
	}
	
	if((root->lchild==NULL)&&(root->rchild==NULL))
	{
		printf("%c ----> ",root->c);
		int i=0;
		for(i=0;i<top;i++)
		printf("%d",stack[i]);
		printf("\n");
	}
	
	return ;
	
}

int main()
{
	printf("Enter the no. of characters: ");
	int i,j;
	scanf("%d",&n);
	size=n;
	printf("Enter the characters and their corresponding frequency: \n");
	getchar();
	for(i=1;i<=n;i++)
	{
		scanf("%c %d",&c[i],&fre[i]);
		getchar();
	}
	fillHeap();
	buildMinHeap();
	NODE* treeHead=HauffmanCoding();
	printCodes(treeHead,0);
}
