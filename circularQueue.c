//Implementing circular queue
#include<stdio.h>
#include<stdlib.h>
    
    //define struct
    struct node
    {
    	int info;        //declare integer type variable to store data of the node
    	struct node *link;        //dclare a pointer to point next of the node
	};
	
	//declare pointers of struct types
	struct node *front;         //to point the first node
	struct node *rear;         //to point the last node
	struct node *newnode=NULL;           //initialize to nothing
	struct node *temp=NULL;            //provide no space
		
	
	//function prototypes
	struct node *cirqcrt(struct node *);       //to create a circulaar queue
	struct node *cirqins(struct node *);        //to insert an element in the circular queue
	struct node *cirqdel(struct node *);       //to delete the element from the circular queue
	struct node *cirqdisplay(struct node *);        //to display all the elements of the circular queue
	
	struct node *cirqcrt(struct node *newnode)              //function definition
	{
		int choice=1;           //define and initialize integer type variable
		
		while(choice)
		{
			//create space for new node
			newnode=(struct node *)malloc(sizeof(struct node));
			
			printf("Enter the data : ");
			scanf("%d", &newnode->info);         //take user input
		
			if(front==NULL)           //if front points nothing (i.e., queue is empty)
			{
				front=rear=newnode;           //point front and rear to new node, first node
			//	front->link=newnode;   same as next line
				newnode->link=front;      //first node stores address of itself and becomes circular
			}
			else
			{
				rear->link=newnode;       //last node points to next new node
				newnode->link=front;      //now new node points to the first node and become circular
				rear=newnode;       //new node is pointed by the rear
			}
			printf("Enter 1 to continue the creation and 0 to exit :");
			scanf("%d", &choice);   //take user input to either continue the loop or not
		}
		printf("\nYOUR CIRCULAR QUEUE IS SUCCESSFULLY CREATED!!!\n");
	}
	
	struct node *cirqdisplay(struct node *temp)            //function definition
	{
		//to traverse
		temp=front;                      //temp points the first node of the queue
		
		if(front==NULL)             //if the queue isn't created
		{
			printf("\nThe queue has no elements.\n");
		}
		else
		{
			printf("\nThe data of the queue are as follows...\n");
			
			//while loop will continue untill temp points rear
			while(temp!=rear)
			{
				printf("%d\n", temp->info);   //print the data of the node to which temp is pointing
				temp=temp->link;     //move temp to the next node
			}
			
			printf("%d", temp->info);          //print data of the last node
		}
		printf("\nDATA PRINTED SUCCESSFULLY!\n");
	}
	
	struct node *cirqdel(struct node *temp)          //function definition
	{
		temp=front;              //temp points first node
		
		if(front==NULL)          //if first node is empty
		{
			printf("ERROR! Queue has no data.\n");
		}
		else if(front->link==front)          //if theres only one node in the circular queue
		{
			front=rear=NULL;            //front and rear pointer pointing to nothing
			printf("\nDATA DELETED SUCCESSFULLY FROM THE QUEUE.  :)\n");
		}
		else
		{
			front=front->link;           //move front to the 2nd node
			rear->link=front;       //rear node pointing to the new front
			printf("\nDATA DELETED SUCCESSFULLY FROM THE QUEUE.  :)\n");
		}
		
		printf("\nThe element %d is deleted.\n", temp->info);
	}
	
	struct node *cirqins(struct node *newnode)             //function definition
	{
		newnode=(struct node *)malloc(sizeof(struct node));   //provide space to temp
		printf("Enter the data : ");
		scanf("%d", &newnode->info);             //take user input in the newnode
		
		if(front==NULL)             //if the queue isn't created
		{
			//create it  :)
			front=rear=newnode;           //front and rear point to new node, first node
			newnode->link=front;          //next of the newnode points to front pointer
			//itself storing it's own address making it circular
		}
		else
		{
			rear->link=newnode;        //rear node storing the address of ne node (connection)
		    newnode->link=front;          //newnode stores the address of first node (make circular)
		    rear=newnode;           //new node is the rea now
		}
		printf("\nDATA INSERTED SUCCESSFULLY!\n");
	}
	
	int main()
	{
		int x;                             //declare integer type variable  
		
		cirqcrt(newnode);                //function call to create the circular queue
		
		//play do-while loop to do stuffs
		do
		{
			//instructions to user to make choice
			printf("\nChoose an option from the menu\n");
	    	printf("-------MENU-------\n");
	    	printf("1 : Insert an element.\n");
	    	printf("2 : Delete an element.\n");
	    	printf("3 : Display the queue.\n");
	    	printf("4 : Exit from the program.\n");
    		printf("\nEnter your choice : ");
	    	scanf("%d", &x);         //take user input
	    	
	    	//switch-case to do the operation according to made choice
	    	switch(x)
	    	{
	    		case 1 :
	    			cirqins(newnode);     //function call to insert a newnode in the queue
	    			break;
	    		case 2 :
	    			cirqdel(temp);            //function call to delete a node from the queue
	    			break;
	    		case 3 :
	    			cirqdisplay(temp);           //function call to print the elements of the queue
	    			break;
			}
	    	
		}while(x<=3);            //till the condition is met, the loop will continue
		
		return 0;
	}
