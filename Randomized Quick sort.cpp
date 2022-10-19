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
	int ff=*low;
	int dd=*high;
	   int random = ff + rand() % (dd - ff);
      swap(a[random], a[ff]);
  int left, right;
  int pivot_item;
  pivot_item = a[ff];
   left = ff;
  right = dd;
  while ( left < right ) {
  
    while( a[left] <= pivot_item ) left++;
   
    while( a[right] > pivot_item ) right--;
    if ( left < right ) swap(a[left],a[right]);
    }
 
  a[ff] = a[right];
  a[right] = pivot_item;
  return right;
  }


int RandomizedQuickSort( int *a, int *low, int *high )
  {
  int pivot;
  int x=*low;
  int u=*high;
  if ( u > x )
    {
    pivot = RandomizedPartition( a, &x, &u );
    int f=pivot-1;
    int g=pivot+1;
    RandomizedQuickSort( a, &x, &f );
    RandomizedQuickSort( a, &g, &u );
    }
  }
int print(int *a,int *low, int *high)
{
    int x=*low;
    int y=*high;
	for(int i=x;i<y;++i)
	{
		cout<<a[i]<<" ";
	}
}
  int main()
  {
    int n;
    cout<<"Enter the Number of Index:-";
    cin>>n;
    cout<<"Enter the Array Elements :- ";
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    cout<<"Intial Array"<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
	int f=0;
  int g=n-1;
    
    cout<<endl;
    cout<<"---------------------"<<endl;
    RandomizedQuickSort(a,&f,&g);
    cout<<"Sorted Array Using Randomized QuickSort"<<endl;
	 print(a,&f,&n);
   return 0;
  }