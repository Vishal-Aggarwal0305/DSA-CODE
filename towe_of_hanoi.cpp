
#include <iostream>
using namespace std;

void toh(int n, int s, int d, int h)
{
   if(n==1)
   {
    cout<<"I WILL MOVE THE PLATE "<<n-1<<" FROM THE POLE "<<s<<" TO THE POLE "<<d<<endl;
    return;
   }

   toh(n-1, s, h, d);
   cout<<"I WILL MOVE THE PLATE "<<n-1  <<" FROM THE POLE "<<s<<" TO THE POLE "<<d<<endl;
   toh(n-1, h, d, s);
}
int main()
{
   int n=4;
   toh(n, 1,2,3);
}