//Randomized and Deterministic Select
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//to swap elements
	void swap(int a, int b)
	{
		int t=a;
		a=b;
		b=t;
	}
//random already present in C
	int random(int *low, int *high)
	{
		int num;
		srand(time(NULL));
		num=((rand()%((*high) + (*low) - 1)) + *low);
		
		return num;
	}

//parition for searching pivot element	
	int partition(int A[],int *p,int *r)             //p=low	r=high
	{
		int x=A[*r];						//select last element as pivot element
		int j,i=(*p)-1;						//indicates null element
		for(j=*p; j<=*r-1; j++)
		{
			if(A[j]<=x)
			{
				i=i+1;
				swap(A[i],A[j]);			//this loop finds the pivot element
			}
		}
		swap(A[i+1],A[*r]);				//i+1 is pivot element
		
		return (i+1);			//
	}
	
//randomized partition 
	int random_parti(int A[], int *p, int *r)
	{
		int i=random(p,r);				//select the index i at random
		swap(A[*r], A[i]);				//exchange A[r], A[i]
		int q=partition(A,p,r);			//Create A[p · · · q - 1] and A[q + 1 · · ·r]
		//check passsing and taking of array in the function
		
		return q;					//
	}
	
	
//radomized select
	int random_select(int A[], int *p, int *r, int *i)
	{
		if(p=r)
		{
			return (A[*p]);						//A[p] is the smallest
		}
		else
		{
			int q=random_parti(A,p,r);					//divide A[p...r] into A[p...q-1] and A[q+1...r]
			int k=q-(*p)+1;
			if(*i=k)
			{
				return (A[q]);					//return the pivot element
			}
			else
			{
				return random_select(A,&q+1,r,i-k);
			}
		}
	}
	
//to get the median of an array 
	int getmed(int *arr, int size)
	{
    	if (size % 2 == 0)
    	{
        	return (arr[(size - 1) / 2] + arr[size / 2]) / 2.0;
    	}
    	else
    	{
        	return arr[size / 2];
    	}
	}
	
//deterministic select	
    int determ_select(int A[], int *p, int *r, int *i)
    {
        int n=sizeof(A)/sizeof(A[0]),j,a,b;
        int A1[20],A2[20],A3[20],A4[20];       //since |A|max=20 ==>(g)max=4
        int B[20];
        
        if(n=1)
        {
            return (A[1]);
        }
        else
        {
        	int g;
        	if ((n/5)%5==0)
        	{
        		g=n/5;
        	}
        	else
        	{
        		g=(n/5)+1;
        	}
        	
        	if(n<=5)
        	{
        		for(j=0;j<n;j++)
        		{
        			A1[j]=A[j];
				}
				int x1=getmed(A1,sizeof(A1)/sizeof(A1[0]));
				B[0]=x1;
			}
			else if(n<=10)
			{
				for(j=0;j<g;j++)
				{
					A1[j]=A[j];					//division of array in g=cieling of |A|/5 parts
				}
				for(j=g;j<n;j++)
				{
					A2[j]=A[j];
					
				}
				int x1=getmed(A1,sizeof(A1)/sizeof(A1[0]));
				int x2=getmed(A2,sizeof(A2)/sizeof(A2[0]));
				B[0]=x1;
				B[1]=x2;
			}
			else if(n<=15)
			{
				for(j=0;j<g;j++)
				{
					A1[j]=A[j];
				}
				for(j=g;j<2g;j++)
				{
					A2[j]=A[j];
				}
				for(j=2g;j<n;j++)
				{
					A3[j]=A[j];
				}
				int x1=getmed(A1,sizeof(A1)/sizeof(A1[0]));
				int x2=getmed(A2,sizeof(A2)/sizeof(A2[0]));
				int x3=getmed(A3,sizeof(A3)/sizeof(A3[0]));
				
				B[0]=x1;
				B[1]=x2;
				B[2]=x3;
			}
			
			else if(n<=20)
			{
				for(j=0;j<g;j++)
				{
					A1[j]=A[j];
				}
				for(j=g;j<2g;j++)
				{
					A2[j]=A[j];
				}
				for(j=2g;j<3g;j++)
				{
					A3[j]=A[j];
				}
				for(j=3g;j<n;j++)
				{
					A4[j]=A[j];
				}
				int x1=getmed(A1,sizeof(A1)/sizeof(A1[0]));
				int x2=getmed(A2,sizeof(A2)/sizeof(A2[0]));
				int x3=getmed(A3,sizeof(A3)/sizeof(A3[0]));
				int x4=getmed(A4,sizeof(A4)/sizeof(A4[0]));
				
				B[0]=x1;
				B[1]=x2;
				B[2]=x3;
				B[3]=x4;
			}
        	//int B[20]={x1, x2, x3, x4};
        	
        	x=determ_select(B,&B[0],&B[(sizeof(B)/sizeof(B[0]))-1],sizeof(B)/sizeof(B[0]));
        	
			//division of array in g=ceal of |A|/5 arrays A1, A2,...Ag : each A1, A2, ...Ag-1
			//has 5 elements and Ag has at most 5 elements
				//find the baby median xj belonging to Aj
			//x=determ_select({x1,x2,...xg},upper value of g/2)
			int L[20],E[20],G[20];
			
			for(j=0; j<n; j++)
			{
				if (A[j]<x)
					{
						L[j]=A[j];
				    }
				else if(A[j]==x)
				{
					 E[j]=A[j];
			    }
			    else
			    {
			    	G[j]=A[j];
			    }
			}
			
			int k=sizeof(L)/sizeof(L[0]);
			int l=sizeof(E)/sizeof(E[0]);
			int m=sizeof(G)/sizeof(G[0]);
			
			if(i<=k)
		    {
				determ_select(L,L[0],L[k-1],k);
			}
			else if(i<=k+l)
			{
				return x;
			}
			else
			{
				determ_select(G,G[0],G[m-1],i-k-l);
        	}
    	}
    }

	
int main()
{
	int i,j,n,x,z,A[20];
	printf("\nEnter the number of array elements ____ ");
    scanf("%d",&n);
    printf("\nEnter the array elements -----  \n");
    for(j=1; j<=n; j++)
    {
        scanf("%d",&A[j]);
    }
    printf("\nEnter the minimum element you want to search ___ ");
    scanf("%d",&i);
    int p=A[0], q=A[n-1];

    do
    {
        printf("\n-------------MENU : ------------------\n");
        printf("\n1.Randomized Select");
        printf("\n2.Deterministic Select");
        printf("\n3.Exit from the program");
        printf("\nEnter your option : ");
        scanf("%d",&x);
        
        switch(x)
        {
            case 1 :
                z=random_select(A,&p,&q,&i);           //ampersand erased
                printf("\nThe %d minimum element is %d",i,z);

                break;
            case 2 :
                z=determ_select(A,&p,&q,&i);
                printf("\nThe %d minimum element is %d",i,z);

                break;
        }
    }
    while(x<=2);
	
	return 0;
}
