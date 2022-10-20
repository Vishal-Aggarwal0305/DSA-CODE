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
     pivot = RandomizedPartition( a, &x, &u );
     int k=pivot-x+1;
     if(k==*q)
     {
      return a[pivot];
     }
     else{
      int ss=pivot-1;
      int sss=pivot+1;
        if(*q <k)
        {
          return Randomized_select(a,&x,&ss,&jj);
        }
        else{
          jj-=k;
          return Randomized_select(a,&sss,&u,&jj);
        }
     }
  }
 }
double median(int *A,int *low,int *high){
     int p= *low, q= *high;
	 int ds=0;
    Randomized_select(A, &p, &q,&ds);
    int n= *high;
    if (n % 2 != 0)
      return (double)A[n/2];
   
   return (double)(A[(n-1)/2] + A[n/2])/2.0;
}
int deter(int *a,int *low,int *high, int *i)
{
   cout<<"jdgdheswgf";
   
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
	
	int f=0;
  int g=n-1;
  int q;
  cout<<"Enter the minimum element you want to search:-";
  cin>>q;

    
    	int c;

	do{
		cout<<"1.Randomised sort"<<endl;
		cout<<"2.Determinostic Approach sort"<<endl;
		cout<<"3.Exit program"<<endl;
	
		cout<<"Enter your Choices:-";
		cin>>c;
		switch (c)
		{
		case 1:
		         cout<<"---------------------"<<endl;
	           cout<<"The minmum element in an array is :-";
              cout<<Randomized_select(a,&f,&g,&q);
			  cout<<endl;
			  break;
		case 2:
		    deter(a,&f,&g,&q);
		       cout<<"jjdg";
			   break;
		
	    
		}
		
      
	
	}while(c<=2);
    
   return 0;
  }