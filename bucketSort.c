#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	float info;
	struct node *link;
	};
	
struct node *head=NULL;


struct node *Insertionsort(struct node *list);		//Doing
void Printbuckets(struct node *list);			//Done
void Bucketsort(float A[],int n);			//Done
void Printarray(float A[],int n);			//Done

void Bucketsort(float A[],int n)
{
	int i, t, j=0;
	struct node *list[20];
	float B[20];
	//list=(struct node *)malloc(sizeof(struct node *));
	for(i=0;i<n;i++)
	{
		list[i]=NULL;
	}
	for(i=0;i<n;i++)
	{
	        struct node *fun;
		int t=n*A[i];
		fun=(struct node *)malloc(sizeof(struct node *));
		fun->info=A[i];
		fun->link=list[t];
		list[t]=fun;
	}
	for(i=0;i<n;i++)
	{
		list[i]=Insertionsort(list[i]);
	}
	printf("\nELEMENTS of sorted array : ");
	for(i=0;i<n;i++)
	{
		Printbuckets(list[i]);
	}
	for (i=0;i<n;i++)
	{
    		struct node *node;
    		node = list[i];
    		while(node)
    		{
      			B[j++] = node->info;
      			node=node->link;
    		}
 	}
}

void Printbuckets(struct node *list)
{
	struct node *node;
	node=list;
	while(node)
	{
        	printf("%f\n", node->info);
                node=node->link;
  	}
}

/*void Printarray(float A[],int n)
{
	int i;
	printf("\nELEMENTS of sorted array are : ");
	for(i=0;i<n;i++)
	{
		printf("\n%f",A[i]);
	}
}*/

struct node *Insertionsort(struct node *list)
{
	if (list==0 || list->link==NULL)
	{
    		return list;
  	}
  	
	struct node *ptr=list, *fun=NULL;
	while(ptr)
	{
		struct node *newnode=ptr->link;
		if(fun==NULL || fun->info>=ptr->info)
		{
			ptr->link=fun;
			fun=ptr;
		}
		else
		{
			struct node *new;
			while(new->link!=NULL && new->link->info < ptr->info)
			{
				new=new->link;
			}
			ptr->link=new->link;
			new->link=ptr;
		}
		ptr=newnode;
	}
	return fun;
}

int main()
{
	int i,n;
	float A[20];
	printf("\nEnter the value of n : ");
	scanf("%d", &n);
	printf("Enter the %d array elements : ",n);
	for(i=0;i<n;i++)
	{
		printf("A[%d]=",i);
		scanf("%f",A+i);
	}
	Bucketsort(A,n);
	//Printarray(A,n);

	return 0;
}
