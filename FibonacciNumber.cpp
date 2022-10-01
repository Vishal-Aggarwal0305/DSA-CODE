#include <bits/stdc++.h>
using namespace std;
//recursive function for fibonacci
int fibonacci(int n)
{
    //if n is zero or one return the number
    if(n<=1)
    {
        return n;
    }
    //recursive call to n-1 and n-2 
    return fibonacci(n-1)+fibonacci(n-2);

}
int main()
{
  int n;
  n=10;
  cout<<fibonacci(n);
}
