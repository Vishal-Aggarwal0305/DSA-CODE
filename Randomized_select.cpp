#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
} 

int RandomizedPartition( int *a, int *low, int *high )
  {
	int l=*low;
	int h=*high;
	int random = l + rand() % (h - l);
        swap(a[random], a[l]);
        int left, right;
        int pivot_item;
        pivot_item = a[l];
        left = l;
        right = h;
    while ( left < right ) {
  
        while( a[left] <= pivot_item ) left++;
   
        while( a[right] > pivot_item ) right--;
    if ( left < right ) swap(a[left],a[right]);
    }
 
  a[l] = a[right];
  a[right] = pivot_item;
  return right;
  }


int Randomized_select( int *a, int *low, int *high ,int *q)
  {
  int pivot;
  int x=*low;
  int u=*high;
  int jj=*q;
  if(x==u)
  {
    return a[x];
  }
  else{
     pivot = RandomizedPartition(a, &x, &u);
     int k=pivot-x+1;
     if(k==*q)
     {
      return a[pivot];
     }
     else{
      int s1=pivot-1;
      int s2=pivot+1;
        if(*q <k)
        {
          return Randomized_select(a,&x,&s1,&jj);
        }
        else{
          jj-=k;
          return Randomized_select(a,&s2,&u,&jj);
        }
     }
   }
  }
int RandomizedQuickSort( int *A, int *low, int *high )
  {
  int pivot;
  int x=*low;
  int u=*high;
  if ( u > x )
    {
    pivot = RandomizedPartition( A, &x, &u );
    int f=pivot-1;
    int g=pivot+1;
    RandomizedQuickSort( A, &x, &f );
    RandomizedQuickSort( A, &g, &u );
    }
    return 0;
  }

double median(int *A,int *low,int *high){
     int p= *low, q= *high;
    RandomizedQuickSort(A, &p, &q);
    int n= *high;
    if (n % 2 != 0)
      return (double)A[n/2];

   return (double)(A[(n-1)/2] + A[n/2])/2.0;
}

//int determ_select(int *A, int *p, int *q, int *k){

//}
int main()
  {
    int n;
    cout<<"Enter the Number of Index: ";
    cin>>n;
    cout<<"Enter the Array Elements : ";
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
	
  int f=0,c=0,q;
  int g=n-1;
  cout<<"Enter the minimum element you want to search:";
  cin>>q;
	do{
		cout<<"1.Randomized select"<<endl;
		cout<<"2.Deterministic select"<<endl;
		cout<<"3.Exit from the program"<<endl;
        	cout<<"Enter your option:";
		cin>>c;
		switch (c)
		{
		case 1:
		      cout<<"\nThe minmum element in an array is \n";
          	      cout<<Randomized_select(a,&f,&g,&q);
	              cout<<endl;
		      break;
		case 2:
		      cout<<"Not yet done\n";
		      break;
		
	    
		}
		
      
	
  }while(c<=2);
    
return 0;
 }
