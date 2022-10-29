#include <stdio.h>
#include <stdlib.h>

    struct node
    {
        int info;
        struct node *link;
    };
    
	struct node *start=NULL;

    struct node *create(struct node *p, int element)
    {
        struct node *fun;
        int num, i;
        start = (struct node *)malloc(sizeof(struct node));

        if(start == NULL)
        {
            printf("Memory not allocated.");
        }
        else
        {
            printf("Input data for node 1 : ");
            scanf("%d", &num);
            start->info = num;      
            start->link = NULL; 
            p = start;
        
		    for(i=2; i<=element; i++)
            {
                fun = (struct node *)malloc(sizeof(struct node));
                printf("Input data for node %d : ", i);
                scanf(" %d", &num);
                fun->info = num;      // links the num field of fnNode with num
                fun->link = NULL; // links the address field of fnNode with NULL 
                p->link = fun; // links previous node i.e. tmp to the fnNode
                p = p->link;     
            }
        }
    }

    struct node *display(struct node *p)
    {
        if(start == NULL)
        {
            printf("List is empty!");
        }
        printf("\nAddress of the starting list : %u", start);
        p = start;
    
	    while(p != NULL)
        {
            printf("\nThe value at node :%d", p->info);       
            p = p->link;                    
        }
    
    }

    struct node *infirst(struct node *p, int num)
    {   
    
        if(start == NULL)
        {
            printf("List is empty!");
        }
        
		struct node *avail;
   
        avail = (struct node *)malloc(sizeof(struct node));
    
        if(avail == NULL) 
            printf("OVER FLOW");
        avail->info = num;     
        avail->link = start;   
        start = avail;     
        printf("Data has been inserted sucessfully at the begining of the list.");
    }

    struct node *insend(struct node *p, int num)
    {
        struct node *avail;
        avail = (struct node *)malloc(sizeof(struct node));
    
        if(avail == NULL) 
            printf("OVER FLOW");
        avail->info = num;
        avail->link = NULL;
        p = start;
    
	    while (p != NULL && p->link != NULL)
            p = p->link;

        p->link = avail;
        printf("Data has been inserted sucessfully at the end of the list.");    
    }

    struct node *insbagnode(struct node *p, int num, int add)
    {
        struct node *avail, *ptr;
        avail = (struct node *)malloc(sizeof(struct node));
        p = start;
        ptr = p;
        avail->info=add;
    
	    while ( ptr->info != num)
        {
            ptr = p;
            p = p->link;
        }
        ptr->link = avail;
        avail->link = p;
        printf("Data is Inserted sucessfully in the list."); 
        return start;
    }

    struct node *count(struct node *p)
    {
        int count = 0;
    
	    if(start == NULL)
        {
            printf("List is empty!");
        }
        p = start;
    
	    while(p != NULL)
        {
            count++;
            p = p->link;                     
        }
        printf("Total Number in the list: %d", count);
    }

    struct node *delfirst(struct node *p)
    {
        struct node *avail;
    
	    if ( start == NULL)
            printf("UNDER FLOW");
        
		p = start;
        start = start->link;
        p->link = avail;
        avail = p;
        printf("Data has been deleated sucessfully from the begining of the list.");
    }

    struct node *delend(struct node *p)
    {
        struct node *avail;
    
	    if (start == NULL)
            printf("UNDER FLOW");
        p = start;
    
	    while (p->link != NULL)
        {
            avail = p;
            p = p->link;
        }
        avail->link = NULL;
        p->link = avail;
        avail = p;
        printf("Data has been deleated sucessfully from the end of the list.");
    }
    
	struct node *delagn(struct node *p, int num)
    {
        struct node *avail;
    
	    if (start == NULL)
            printf("UNDER FLOW");
        p = start;
        avail = p;
    
	    while(p->info != num)
        {
            avail = p;
            p = p->link;
        }
        
        avail->link = p->link;
        p->link = avail;
        avail = p;
        printf("Data has been deleated sucessfully!");
    }
    
    
    int main()
    {
        struct node *p;
        int choice, element, value, add;
        printf("Enter the number of nodes :");
        scanf("%d", &element);
        create(p, element);
    
	    while (1)
        {
            printf("\n\t\t-----MENU-----\n");
            printf("ENTER................");
            printf("\n 1 to display the list.");
            printf("\n 2 to insert at the beginning of the list.");
            printf("\n 3 to insert at the end of the list.");
            printf("\n 4 to insert at a specified position of the list.");
            printf("\n 5 to count the number of nodes in of the list.");
            printf("\n 6 to delete a node from beginning of the list.");
            printf("\n 7 to delete a node from the end.");
            printf("\n 8 to delete a specified node from the list.");
            printf("\n 9 TO EXIT!!!");
            printf("\n\nNow, enter your choice: ");
            scanf("%d", &choice);
     
	        switch (choice)
            {
                case 1:
                    display(p);
                    break;
                case 2:
                    printf("Enter the value to add in the list :");
                    scanf("%d", &value);
                    infirst(p, value);
                    break;
                case 3:
                    printf("Enter the value to add in the list :");
                    scanf("%d", &value);
                    insend(p, value);
                    break;
                case 4:
                    printf("Enter the value of the node after which you want to add another element : ");
                    scanf("%d", &value);
                    printf("Enter the value to add in the list :");
                    scanf("%d", &add);
                    insbagnode(p, value, add);
                    break;
                case 5:
                    count(p);
                    break;
                case 6:
                    delfirst(p);
                    break;
                case 7:
                    delend(p);
                    break;
                case 8:
                    printf("Enter the value to delete from the list :");
                    scanf("%d", &value);
                    delagn(p, value);
                    break;
                case 9:
                    exit(0);
                default:
                    printf("\n SORRY! Error occured.\n");
                    break;
            }
        }
        return 0;
    }
