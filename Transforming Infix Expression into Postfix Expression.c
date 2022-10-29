#include<stdio.h>
#include<stdlib.h>
#include<string.h>

    struct stack
    {
    	int max;
    	int top;
    	char *array;
	};

    int precedence(char);
    struct stack *inftopfx(char *);
    struct stack *stackTop(struct stack *);
    int isOperator(char);
    struct stack *isEmpty(struct stack *);
    struct stack *isFull(struct stack *);
    struct stack *stackTop(struct stack *);
    
    struct stack *stackTop(struct stack *sp)
	{
    	return (sp->array[sp->top]);
    }
	
	
    struct stack *isEmpty(struct stack *ptr)                
    {
    	if(ptr->top == -1)
    	{
    		return 1;
		}
		else
		{
			return 0;
		}
	}
	
	struct stack *isFull(struct stack *ptr)                    
	{
		if(ptr->top == ptr->max-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	struct stack *pop(struct stack *ptr)                   
	{
		if(isEmpty(ptr))
		{
			printf("---UNDERFLOW---");
			return -1;
		}
		else
		{
			char val = ptr->array[ptr->top];
			ptr->top--;
			return val;
		}
	}
	
	struct stack *push(struct stack *ptr, char val)                    
	{
	    if(isFull(ptr))
	    {
	    	printf("---OVERFLOW---");
		}
		else
		{
			ptr->top++;
			ptr->array[ptr->top] = val;
		}
	}
	
    int precedence(char ch)
    {
    	if(ch=='*' || ch=='/')
    	{
    		return 3;
		}
		else if(ch=='+' || ch=='-')
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
	
    int isOperator(char ch)
	{
		if(ch == '*' || ch == '/' || ch == '+' || ch == '-')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	struct stack *inftopfx(char *infix)                        
	{
		struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
		sp->max = 100;
		sp->top = -1;
		sp->array = (char *)malloc(sp->max * sizeof(char));
		char *postfix = (char *)malloc((strlen(infix)+1) * sizeof(char));
		
		int i=0;         //track infix traversal
		int j=0;            //track postfix addition
		
		
		while(infix[i]!='\0')
		{
			if(isOperator(infix[i]))
			{
				postfix[j]=infix[i];
				j++;
				i++;
			}
			else
			{
				if(precedence(infix[i]) > precedence(stackTop(sp)))
				{
					push(sp, infix[i]);
					i++;
				}
				else
				{
					postfix[j] = pop(sp);
					j++;
				}
			}
		}
		
		while(!isEmpty(sp))
		{
			postfix[j] = '\0';
			return postfix;
		}
	}

    int main()
    {	
	    char * infix, exp[1000];
	    printf("Enter the expression to convert : ");
	    scanf("%s", &exp[1000]);
	    infix = &exp[1000];
	    
	    printf("\n\t-----Postfix is : '%s'", inftopfx(infix));
	
	    return 0;
    }
