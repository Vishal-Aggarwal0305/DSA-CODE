#include<bits/stdc++.h>

using namespace std;
int main()
{   
    int k,r;
    cin>>k>>r;
    int a=k%10;
    int flag=-1;
    for(int i=1;i<=10;i++)
    {
        if((a*i)%10==r || (k*i)%10==0)
        {
            flag=i;
            break;
        }
    }
    cout<<flag;
return 0;
}