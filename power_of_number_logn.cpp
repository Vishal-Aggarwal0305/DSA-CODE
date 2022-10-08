#include "bits/stdc++.h"
using namespace std; 
// Recursive function to return gcd of a and b 
double calc_pow(int x, int n) 
{
    double ans=1.0;
    long long n1=n;
    if(n1<0) n1=-1*n1;
        while(n1){
            if(n1%2){
                ans*=x;
                n1-=1;
            }
            else{
                x*=x;
                n1/=2;
            }
        }
    
    if(n<0){
        ans=(double)(1.0)/(double)(ans);
    }
    return ans;
} 

int main() 
{ 
 int x, n;
 cout<<"Enter two numbers: ";
 cin>>x>>n;
 cout<<calc_pow(x, n); 
 return 0; 
}
