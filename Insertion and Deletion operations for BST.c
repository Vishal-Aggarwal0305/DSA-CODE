//Playing with BST
#include<stdio.h>
#include<stdlib.h>
    
    struct node
	{
		int info;
		struct node *left;
		struct node *right;
	};
	
	struct node *createbst(struct node *, int);
	struct node *smallestbst(struct node *);
	struct node *largestbst(struct node *);
	struct node *searchanodebst(struct node *, int);
	struct node *deleteanodebst(struct node *, int);
	struct node *inorder(struct node *);
	
	struct node *root;
	struct node *ptr;
	
	struct node *func1(struct node *, struct node *, struct node *);
	struct node *func2(struct node *, struct node *, struct node *);
	struct node *func3(struct node *, struct node *, struct node *);
	
	struct node *createbst(struct node *root, int item)   //non recursive
	{
		struct node *par, *temp;
		ptr=root;
		par=NULL;
		while(ptr!=NULL)
        {
            par=ptr;
            
            if(item<ptr->info)
                ptr=ptr->left;
            
            else if(item>ptr->info)
                ptr=ptr->right;
        }
        
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=item;
        temp->left=NULL;
        temp->right=NULL;
        
        if(par==NULL)
            root=temp;
        else if(item<par->info)
            par->left=temp;
        else
            par->right=temp;
        return root;
	}
	
	struct node *smallestbst(struct node *root)    //recursive
	{
		if(root==NULL)
		{
			return NULL;
		}
		else if(root->left!=NULL)
		{
			return smallestbst(root->left);
		}
		return root;
	}
	
	struct node *largestbst(struct node *root)           //recursive
	{
		if(root==NULL)
		{
			return NULL;
		}
		else if(root->right!=NULL)
		{
			return largestbst(root->right);
		}
		return root;
	}
	
	struct node *searchanodebst(struct node *root, int item)    //non recursive
	{
		ptr=root;
		if(ptr!=NULL)
		{
			while(ptr!=NULL)
			{
				if(item<ptr->info)
				{
					ptr=ptr->left;
				}
				else if(item>ptr->info)
				{
					ptr=ptr->right;
				}
				else
				{
					return ptr;
				}
			}
		}
		else
		{
			return NULL;
		}
	}
	
	struct node *deleteanodebst(struct node *root, int item)   //non recursive
	{
		struct node *par;
		ptr=root;
		par=NULL;
		while(ptr!=NULL)
		{
			if(item==ptr->info)
			{
				break;
			}
			par=ptr;
			if(item<ptr->info)
			{
				ptr=ptr->left;
			}
			else
			{
				ptr=ptr->right;
			}
		}
		
		if(ptr==NULL)
		{
			printf("\nNode %d isn't present in this BST", item);
		}
		else if(ptr->left!=NULL && ptr->right!=NULL)
		{
			root=func3(root, par, ptr);
		}
		else if(ptr->left!=NULL)
		{
			root=func2(root, par, ptr);
		}
		else if(ptr->right!=NULL)
		{
			root=func2(root, par, ptr);
		}
		else
		{
			root=func1(root, par, ptr);
		}
		
		return root;
	}
		
	struct node *inorder(struct node *root)           //recursive
    {
        if(root!=NULL)
        {
        	inorder(root->left);
        	printf("%d\n", root->info);
        	inorder(root->right);
		}
    }
	
	struct node *func1(struct node *root, struct node *par, struct node *ptr)
	{
		if(par==NULL)
		{
			root==NULL;
		}
		else if(ptr==par->left)
		{
			par->left=NULL;
		}
		else
		{
			par->right=NULL;
		}
		free(ptr);
		return root;
	}
	
	struct node *func2(struct node *root, struct node *par, struct node *ptr)
	{
		struct node *fun2;
		
		if(ptr->left!=NULL)
		{
			fun2=ptr->left;
		}
		else
		{
			fun2=ptr->right;
		}
		
		if(par==NULL)
		{
			root=fun2;
		}
		else if(ptr==par->left)
		{
			par->left=fun2;
		}
		else
		{
			par->right=fun2;
		}
		free(ptr);
		return root;
	}
	
	struct node *func3(struct node *root, struct node *par, struct node *ptr)
	{
		struct node *fun2, *fun3;
		
		fun3=ptr;
		fun2=ptr->right;
		while(fun2->left!=NULL)
		{
			fun3=fun2;
			fun2=fun2->left;
		}
		
		ptr->info=fun2->info;
		
		if(fun2->left==NULL && fun2->right==NULL)
		{
			root=func1(root, fun3, fun2);
		}
		else
		{
			root=func2(root, fun3, fun2);
		}
        return root;
	}
	
	int main()
	{
		int x, item;
		// it's wrong to define "struct node *root;" here
		//struct node *ptr;
		do
		{
			printf("\n1. Create a binary search tree.\n");
			printf("2. Find the smallest element.\n");
			printf("3. Find the largest element.\n");
			printf("4. Search a node from the BST.\n");
			printf("5. Deleting a node from the BST.\n");
			printf("6. Inorder Traversal.\n");
			printf("7. Exit from the program.\n");
			printf("Enter your option : ");
			scanf("%d", &x);
			
			switch(x)
			{
				case 1 :
					printf("Enter -1 to terminate\n");
					printf("\nEnter the data item : ");
					scanf("%d", &item);
					while(item!=-1)
					{
						root=createbst(root, item);
						printf("Enter the data item : ");
						scanf("%d", &item);
					}
					printf("\nBinary Tree is created!\n");
				break;
				
				case 2 :
					ptr=smallestbst(root);
					printf("\nSmallest element is : %d\n", ptr->info);   //
				break;
				
				case 3 :
					ptr=largestbst(root);
					printf("\nLargest element is : %d\n", ptr->info);    //
				break;
				
				case 4 :
					printf("\nWhich element you want to search? ");
					scanf("%d", &item);
					ptr=searchanodebst(root, item);
					
					if(ptr==NULL)
					{
						printf("\nGiven node isn't present in the formed BST.\n");
					}
					else
					{
						printf("\nNode found!\n");
					}
				break;
				
				case 5 :
					printf("\nWhich element you want to delete? ");
					scanf("%d", &item);
					root=deleteanodebst(root, item);
					printf("\nNode %d deleted successfully!\n", item);
				break;
				
				case 6 :
					if(root==NULL)
					{
						printf("\nInorder Traversal : Binary tree is empty.");
					}
					else
					{
						printf("\nInorder Traversal : \n");
						root=inorder(root);
					break;
					}
				break;
			}
		}
		while(x<=6);
		
		return 0;
	}
