#include <iostream>  
using namespace std;  
int main()  
{  
   int fact=1,n;    
   cout<<"Enter no. :";    
   cin>>n;    
   for(int i=1;i<=n;i++){    
      fact=fact*i;    
   }    
   cout<<"Factorial is: "<<fact<<endl;  
   return 0;  
} 
