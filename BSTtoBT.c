#include<stdio.h>
#include<stdlib.h>

	struct node
	{
		int data;
		struct node*left;
		struct node*right;
	};

	struct node*root;

	struct node*createnode(int data)
	{
		struct node*newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=data;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	};

	struct node*build_tree(struct node*root, int data)
	{
		if(root==NULL){
    	return createnode(data);
	}
		if(data<root->data){
  		root->left=build_tree(root->left,data);
	}
		if(data>root->data){
    	root->right=build_tree(root->right,data);
	}
	return root;
	};

	struct node* summation(struct node *root, int *p)
	{
		if (root == NULL)
		{
			return;
		}
		summation(root->right, p);
		*p += root->data;
		root->data = *p;
		summation(root->left, p);
	}

	void inorder(struct node*root)
	{
		if(root!=NULL)
		{
    		inorder(root->left);
    		printf("%d  ",root->data);
    		inorder(root->right);
		}
	}

	int main()
	{
		int o,choice=1,input,sum=0;

    	while(choice=1)
		{
    		printf("\nPress 1 to Input Data\n");
    		printf("Press 2 for Inorder Traversal\n");
    		printf("Press 3 to Display Output\n");
    		printf("Press 4 to Terminate\n");
    		scanf("%d",&o);

    	switch(o)
		{
			case 1:
       			printf("Enter an element: ");
       			scanf("%d",&input);
       			root=build_tree(root,input);
       			break;

		    case 2:
        		printf("Inorder Display OF BST: ");
        		inorder(root);
       			break;

    		case 3:
    		    summation(root,&sum);
       			inorder(root);
       			break;

		    case 4:
        		choice=0;
        		exit(0);
    		}
   		}
    	return 0;
	}
