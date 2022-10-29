#include<stdio.h>
#include<stdlib.h>
   
   struct node
   {
   	    struct node *prev;
   	    int info;
   	    struct node *next;
   } *start, *tail;                      
   
   
   struct node *createcdll(struct node *);
   struct node *printcdll(struct node *);
   struct node *inscdllfirst(struct node *);
   struct node *inscdllend(struct node *);
   struct node *inscdllafgn(struct node *, struct node *);
   struct node *delcdllfirst(struct node *);
   struct node *delcdllend(struct node *);
   
   struct node *createcdll(struct node *newnode)
   {
   	    start=0;
   	    int choice=1;
   	    
   	    while(choice)
   	    {
		    newnode=(struct node*)malloc(sizeof(struct node));
		    
		    printf("\nTO CREATE THE LIST----\n");
   	        printf("Enter data for node: ");
   	        scanf("%d", &newnode->info);
   	        printf("\n");
		
   	        if(start==0)
   	        {
   	    	    start=tail=newnode;
   	    	    start->next=newnode;
   	    	    start->prev=newnode;
		    }
		    else
		    {
		    	tail->next=newnode;
		    	newnode->prev=tail;
			    newnode->next=start;
			    start->prev=newnode;
			    tail=newnode;
		    }
		    
		    printf("Enter 8 to continue list creatioin and 0 to exit : ");
		    scanf("%d", &choice);
		    
	    }
	    printf("\nLIST CREATED SUCCESSFULLY!\n");
   }
   
   struct node *printcdll(struct node *temp)
   {
   	    temp=start;
   	    
		   if(start==0)
   	    {
   	     	printf("\nList is empty. There is no data in the list.");
		}
		else
		{
			printf("\nThe data of the list are as follows \n");
			while(temp!=tail)
			{
				printf("%d\n", temp->info);
				temp=temp->next;
			}
			printf("%d", temp->info);
		}
		printf("\nDATA OF THE LIST PRINTED SUCCESSFULY!\n");
   }
   
   struct node *inscdllfirst(struct node *newnode)
   {
   	    newnode=(struct node*)malloc(sizeof(struct node));
   	    printf("\nEnter data : ");
   	    scanf("%d", &newnode->info);
   	    
   	    if(start==0)
   	    {
   	    	start=tail=newnode;
   	    	newnode->prev=tail;
   	    	newnode->next=start;
		}
		else
		{
			newnode->next=start;
			start->prev=newnode;
			newnode->prev=tail;
			tail->next=newnode;
			start=newnode;
		}
		printf("\nDATA INSERTED SUCCESSFULLY!\n");
   }
   
   struct node *inscdllend(struct node *newnode)
   {
   	    newnode=(struct node*)malloc(sizeof(struct node));
   	    printf("\nEnter data : ");
   	    scanf("%d", &newnode->info);
   	    
   	    if(start==0)
   	    {
   	    	start=tail=newnode;
   	    	newnode->prev=tail;
   	    	newnode->next=start;
		}
		else
		{
			newnode->prev=tail;
			tail->next=newnode;
			newnode->next=start;
			start->prev=newnode;
			tail=newnode;
		}
		printf("\nDATA INSERTED SUCCESSFULLY!\n");
   }
   
   struct node *inscdllafgn(struct node *newnode, struct node *temp)
   {
   	    int pos, i=1, l;                   
   	    printf("\n Enter the length of the list : ");
   	    scanf("%d", &l);
   	    printf("\nEnter position : ");
   	    scanf("%d", &pos);
   	    
   	    if(pos<1 || pos>l)
   	    {
   	    	printf("\nInvalid position. Try again.");
		}
		else if(pos==1)
		{
			inscdllfirst(newnode);
		}
		else
		{
			printf("\n Enter data : ");
			scanf("%d", &newnode->info);
			
			while(i<pos-1)
			{
				temp=temp->next;
				i++;
			}
			
			newnode->prev=temp;
			newnode->next=temp->next;
			temp->next->prev=newnode;
			temp->next=newnode;
			
			printf("\nDATA INSERTED SUCCESSFULLY!\n");
		}
   }
   
   struct node *delcdllfirst(struct node *temp)
   {
   	    temp=start;
   	    if(start==0)
   	    {
   	    	printf("\nError");
		}
		else if(start->next==start)
		{
			start=tail=0;
		}
		else
		{
			start=start->next;
			start->prev=tail;
			tail->next=start;
		}
		printf("\nDATA DELETED SUCCESSFULLY!\n");
   }
   
   struct node *delcdllend(struct node *temp)
   {
   	    temp=start;
   	    if(start==0)
   	    {
   	    	printf("\nError");
		}
		else if(start->next==start)
		{
			start=tail=0;
		}
		else
		{
			tail=tail->prev;
			tail->next=start;
			start->prev=tail;
		}
		
		printf("\n DATA DELETED SUCCESSFULLY!\n");
   }
   
   int main()
   {
   	    int choice;
        struct node *newnode, *temp;
        newnode=(struct node *)malloc(sizeof(struct node));
        temp=(struct node *)malloc(sizeof(struct node));
        
   	    createcdll(newnode);
   	    
   	    while(1)
		{
   	    	printf("\nChoose an operation to be done in accordance with the menu.\n");
   	        printf("\n\t-----MENU-----\n");
   	        printf("Enter 1 to display the list.\n");
   	        printf("Enter 2 to insert a new data at beginning of the list.\n");
   	        printf("Enter 3 to insert a new data at the end of the list.\n");
   	        printf("Enter 4 to insert a new data at your desired postion in the list.\n");
   	        printf("Enter 5 to delete a data from the first place of the list.\n");
   	        printf("Enter 6 to delete a data from the end of the list.\n");
   	        printf("Enter 7 to exit from the process.\n");
   	        printf("\nEnter your choice : ");
   	        scanf("%d", &choice);
   	        
   	        switch(choice)
   	        {
   	        	case 1 :
   	        		printcdll(temp);
   	        		break;
   	        	case 2 :
   	        		inscdllfirst(newnode);
   	        		break;
   	        	case 3 :
   	        		inscdllend(newnode);
   	        		break;
   	        	case 4 :
   	        		inscdllafgn(newnode, temp);
   	        		break;
   	        	case 5 :
   	        		delcdllfirst(temp);
   	        		break;
   	        	case 6 :
   	        		delcdllend(temp);
   	        		break;
   	        	case 7 :
   	        		exit(0);
   	        	default :
   	        		printf("\n\t\t------ERROR!------");
   	        		break;
			}
   	        
	    }
   	    free(temp);
   	    free(newnode);
   	    
   	    return 0;
   }
