#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
} 

int Random_partion( int *a, int *low, int *high )
  {
	int forward=*low;
	int backward=*high;
	   int random = forward + rand() % (backward - forward);
      swap(a[random], a[forward]);
  int left, right;
  int pivot_item;
  pivot_item = a[forward];
   left = forward;
  right = backward;
  while ( left < right ) {
  
    while( a[left] <= pivot_item ) left++;
   
    while( a[right] > pivot_item ) right--;
    if ( left < right ) swap(a[left],a[right]);
    }
 
  a[forward] = a[right];
  a[right] = pivot_item;
  return right;
  }


int Randomized_select( int *a, int *low, int *high ,int *q)
  {
  int pivot;
  int x=*low;
  int u=*high;
  int j=*q;
  if(x==u)
  {
    return a[x];
  }
  else{
     pivot = Random_partion( a, &x, &u );
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
          return Randomized_select(a,&x,&ss,&j);
        }
        else{
          j-=k;
          return Randomized_select(a,&sss,&u,&j);
        }
     }
  }


  }
int output(int *a,int *low, int *high)
{
    int x=*low;
    int y=*high;
	for(int i=x;i<y;++i)
	{
		cout<<a[i]<<" ";
	}
}
// median function
double median(int *A,int *low,int *high){
     int p= *low, q= *high;
    Random_partion(A, &p, &q);
    int n= *high;
    if (n % 2 != 0)
      return (double)A[n/2];
   
   return (double)(A[(n-1)/2] + A[n/2])/2.0;
}
// determinstic sort

int determinstic_Sort(int *A, int *p, int *q, int *i){
    int grp;
    int sz= *q;
    if (sz == 1){
        return A[0];
    }
     else{
        grp = ceil(sz / 5.0);
       int part_arr[grp];
        for (int i = 0; i < grp; i++){
            int j = i * 5;
           while (j < ((i * 5) + 5) && j < sz){
                int temp[5];
                for (int k = 0; k < 5; k++){
                    temp[k] = A[j++];
                }
                   part_arr[i] = median(temp, j - (i * 5),&i);

            }

        }
        int median_grp = (int)ceil(grp / 2.0);
        int x = determinstic_Sort(part_arr, &median_grp, &i);



  int main()
  {
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    cout<<"Enter the elements of the array\n";
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
	
	int f=0;
  int g=n-1;
  int q;
  cout<<"Enter the  index of the minimum element you want to search\n";
  cin>>q;

    
    	int c;

cout<<"Enter your choice"<<endl;
		cout<<"1.Randomised sort"<<endl;
		cout<<"2.Deterministic  sort"<<endl;
		cout<<"3.Exit program"<<endl;
	
		cout<<"Enter your Choice\n";
		cin>>c;
		switch (c)
		{
		case 1:
		         cout<<"\n"<<endl;
	           cout<<"The minmum element in this array is "<<endl;
              cout<<Randomized_select(a,&f,&g,&q);
			  cout<<"\n";
			  break;
		case 2:
		       cout<<"";
			   break;
		
    }		
      
   return 0;
  }