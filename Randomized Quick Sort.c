#include<stdio.h>
#include<stdlib.h>
#define MAX 100
	void swap(int *x, int *y)
	{
		int t=*x;
		x=y;
		*y=t;
	}
	
	int *randomizedpartition(int *arr, int *p, int *r)
	{
		int pvtadrs=*p+(rand()%(*r-*p+1));
		int i=*p-1;
		int j;
		int pvt=arr[pvtadrs];
		swap(&arr[pvtadrs],&arr[*r]);
		for(j=*p; j<*r;j++)
		{
			if(arr[j]<pvt)
			{
				i++;
				swap(&arr[i],&arr[j]);
			}
		}
		swap(&arr[i+1],&arr[*r]);
		return (i+1);
	}
	
	void randomizedquicksort(int *arr, int *p, int *r)
	{
		int i;
		if(p<r)
		{
			i=randomizedpartition(arr,p,r);
        	randomizedquicksort(arr,p,i-1);
        	randomizedquicksort(arr,i+1,r);
		}
	}
	
	void printelement(int *arr, int *p, int *r)
	{
		int i;
		for (i=1;i<*r;i++)
		{
			printf("%d \n", arr[i]);
		}
	}
	
	int main()
	{
		int i,x,arr[MAX],n;
		do
		{
			printf("\n----MENU----\n");
			printf("Enter 1 to input elements.");
			printf("\nEnter 2 for randomquicksort.");
			printf("\nEnter 3 to print sorted elements.");
			printf("\n---Enter 4 to exit---\n");
			printf("Enter your choice : ");
			scanf("%d",&x);
			switch(x)
			{
				case 1 : 
					printf("\nEnter number of elements : ");
					scanf("%d",&n);
					for(i=0;i<n;i++)
					{
						printf("Enter %dth element : ",i);
						scanf("%d",&arr[i]);
					}
					printf("\n-----Elements got placed.-----\n");
					break;
				case 2 :
					randomizedquicksort(arr,0,n-1);
					printf("\n-----Random Quick Sort Done.-----\n");
					break;
				case 3 :
					printf("\n-----Sorted ellements : \n");
					printelement(arr,0,n-1);
					printf("\n-----Elements printed.\n");
					break;
			}
		}while(x<4);
		return 0;
	}
