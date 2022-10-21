#include<stdio.h>
#include<stdlib.h>

struct knap{
	float x[10];//solution vector
	float profit;//total profit
};

void Merge(float * , int , int , int );
void MergeSort(float *array, int left, int right){
   int middle = (left+right)/2;
   if(left<right){
      //Sorting the left part
      MergeSort(array, left, middle);
      //Sorting the right part
      MergeSort(array, middle + 1, right);
      // Merge the two parts
      Merge(array, left, middle, right);
   }
}
void Merge(float *array, int left, int middle, int right){
   float tmp[right - left + 1];
   int pos = 0, left_posi = left, right_posi = middle + 1;
   while (left_posi <= middle && right_posi <= right){
      if (array[left_posi] > array[right_posi]){
         tmp[pos++] = array[left_posi++];
      }
      else{
         tmp[pos++] = array[right_posi++];
      }
   }
   while (left_posi <= middle)
      tmp[pos++] = array[left_posi++];
   while (right_posi <= right)
      tmp[pos++] = array[right_posi++];
   int i;
   for (i = 0; i < pos; i++){
      array[i + left] = tmp[i];
   }
   return ;
}

struct knap*knapsack(int *n,float*w,float*c,float*W){
    struct knap*kn=(struct knap*)malloc(sizeof(struct knap));
    kn->profit=0;
	float copy[*n]; float cpw[*n];
	int i=0;
	for(i=0;i<*n;i++){
		cpw[i]=c[i]/w[i];
	}
	for(i=0;i<*n;i++){
		copy[i]=cpw[i];
	}
	MergeSort(copy,0,*n);
	float newcost=*W;
	float*ptr=copy+0;
	while(newcost!=0){
   	 int i=0;
       while(cpw[i]!=*ptr){
           i++;
   }
  
   ptr++;
   if(newcost<w[i]){
   	w[i]=newcost;
   }
   kn->profit+=w[i]*cpw[i];
   kn->x[i]=w[i]*cpw[i];
   printf(" %d object is picked up making profit of %f\n",i+1,kn->x[i]);
    newcost=newcost-w[i];
   cpw[i]=0;
   }
	printf("Net Profit-%f",kn->profit);
}
int main(){
	float w[20],c[20],W;
	int n;
	printf("Enter number of objects: ");
	scanf("%d",&n);
	printf("Enter knapsack capacity: ");
	scanf("%f",&W);
	int i;
	for(i=0;i<n;i++){
		printf("Enter object weight: ");
		scanf("%f",&w[i]);
		printf("Enter cost of object: ");
		scanf("%f",&c[i]);
	}
	knapsack(&n,w,c,&W);
return 0;
}