#include<stdio.h>
#include<stdlib.h>

#define MAX 20

	struct node{
		int data;
		struct node *left;
		struct node *right;
	};

	int sum,top=0,temp;

	struct node *build_tree(struct node *root,int x)
	{
		struct node *newnode,*ptr,*p;
		newnode=(struct node*)malloc(sizeof(struct node));
	
		if(newnode==NULL)
		{
			printf("\nNO ELEMENTS ARE IN TREE\n");
		}
		
		newnode->data=x;
		newnode->left=NULL;
		newnode->right=NULL;
	
		if(root==NULL)
		{
			root=newnode;
		}
		else
		{
			ptr=root;
			p=NULL;
			
			while(ptr!=NULL)
			{
				p=ptr;
				
				if(x<=ptr->data)
				{
					ptr=ptr->left;
				}
				else
				{
					ptr=ptr->right;
				}
			}
		
			if(x<p->data)
			{
				p->left=newnode;
			}
			else
			{
				p->right=newnode;
			}
		}
		return root;
	}

	struct node *stack[MAX];
	int trav_list[MAX],l,n;

	struct node *inorder(struct node*root)
	{
		struct node *ptr;
		stack[top]=NULL;
		ptr=root;
	
		while(ptr!=NULL)
		{
			top=top+1;
			stack[top]=ptr;
			ptr=ptr->left;
		}
		ptr=stack[top];
		top=top-1;
		
		while(ptr!=NULL)
		{
			trav_list[l]=ptr->data;
			l++;
			
			if(ptr->right!=NULL)
			{
				ptr=ptr->right;
				while(ptr!=NULL)
				{
					top=top+1;
					stack[top]=ptr;
					ptr=ptr->left;
				}
			}
			ptr=stack[top];
			top=top-1;
		}
		return root;
	}
	
	
	struct node *postorder(struct node *root)
	{
		stack[top]=NULL;
		struct node*ptr,*q;
		ptr=q=root;
	
		while(1)
		{
			while(ptr->left!=NULL)
			{
				top=top+1;
				stack[top]=ptr;
				ptr=ptr->left;
			}
			while(ptr->right==NULL||ptr->right==q)
			{
				temp=ptr->data;
				ptr->data=trav_list[n];
				trav_list[n]=temp;
				n++;
				q=ptr;
			
				if(stack[top]==NULL)
				{
					return root;
				}
				ptr=stack[top];
				top=top-1;
			}
			top=top+1;
			stack[top]=ptr;
			ptr=ptr->right;
		}
		return root;
	}


	struct node *heapify(struct node *root)
	{
		struct node*ptr;
		stack[top]=NULL;
		ptr=root;

		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			if(ptr->right!=NULL)
			{
				ptr=ptr->right;
				while(ptr!=NULL)
				{
					top=top+1;
					stack[top]=ptr;
					ptr=ptr->left;
				}
			}
			ptr=stack[top];
			top=top-1;
		}

		while(ptr!=NULL)
		{
			top=top+1;
			stack[top]=ptr;
			ptr=ptr->left;
		}
		ptr=stack[top];
		top=top-1;

		return root;
	}

	int main()
	{
		int inp,i,j;
		struct node*root=NULL;
		struct node *c;
		printf("Enter -5 to terminate\n");
		printf("\nInput Data::");
		scanf("%d",&inp);
		
		while(inp!=-5)
		{
			root=build_tree(root,inp);
			printf("Input Data::");
			scanf("%d",&inp);
		}
		printf("Initial Traversal(BST):");

		inorder(root);
		for(i=0;i<l;i++)
		{
			printf("%d ",trav_list[i]);
		}
		printf("\n");
		root=postorder(root);
		printf("Final Traversal (max heap):");
		heapify(root);
		return 0;
	}

