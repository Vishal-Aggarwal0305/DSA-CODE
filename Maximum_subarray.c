#include<stdio.h>
#include<stdlib.h>
int m,l,mid;
int maxcrossingsum(int *a,int low,int mid,int high)
{
	int leftsum,rightsum,crosssum,sum,i,j,maxleft,maxright,sum1;
	leftsum=-9999;
	sum=0;
	for(i=mid;i>=low;i--)
	{
		sum=sum+*(a+i);
		if(sum>leftsum)
		{
			leftsum=sum;
			maxleft=i;
			
		}
	}
	rightsum=-9999;
	sum1=0;
	for(j=mid+1;j<=high;j++)
	{
		sum1=sum1+*(a+j);
		if(sum1>rightsum)
		{
			rightsum=sum1;
			maxright=j;
		}
	}
	crosssum=leftsum+rightsum;
	return crosssum;
}
int maxsubarraysumdivcon(int *a,int low,int high)
{
	int mid,leftsum,rightsum,crosssum;
	if(high==low)
	{
		return *(a+low);
	}
	mid=(high+low)/2;
	leftsum=maxsubarraysumdivcon(a,low,mid);
	rightsum=maxsubarraysumdivcon(a,mid+1,high);
	crosssum=maxcrossingsum(a,low,mid,high);
	if((leftsum>rightsum||leftsum==rightsum)&&(leftsum>crosssum||leftsum==crosssum))
	{
		return leftsum;
	}
	else if((rightsum>leftsum||rightsum==leftsum)&&(rightsum>crosssum||rightsum==crosssum))
	{
		return rightsum;
	}
	else
	{
		return crosssum;
	}
}
int maxsubarraynaive(int *a,int n)
{
	int i,sum,j,maxsum;
	maxsum=*(a+1);
	
	for(i=1;i<=n;i++)
	{
		sum=0;
		for(j=i;j<=n;j++)
		{
			sum=sum+*(a+j);
			if(sum>=maxsum)
			{
				m=i;
				l=j;
				maxsum=sum;	
			}
		}
	}
	return maxsum;
}
int main()
{
	int n,x,i,a[20],maxsum,k;
	printf("Enter the number of array elements\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	do
	{
		printf("1. Find the maximum subarray using naive approach\n");
		printf("2. Find the maximum subarray using divide and conquer approach\n");
		printf("3. Exit from the program\n");
		printf("Enter your option\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
			maxsum=maxsubarraynaive(a,n);
			printf("The maximum sum is: %d\n",maxsum);
			printf("The maximum subarray is:");
			for(k=m;k<=l;k++)
			{
				printf("A[%d]=%d",k,a[k]);
				printf("\n");
				
			}
			
			break;
			case 2:
			maxsum=maxsubarraysumdivcon(a,1,n);
			printf("The maximum sum is: %d\n",maxsum);
			for(k=m;k<=l;k++)
			{
				printf("The maximum subarray is: ");
				printf("A[%d]=%d\n",k,a[k]);
			}
			break;
		}
	}
	while(x<=2);
	return 0;
}
