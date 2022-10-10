#include<bits/stdc++.h>

using namespace std;
int main()
{
    int t,n;
    cin>>t;
while(t--)
    {
        cin>>n;
        if(n%3==0)
        cout<<n/3<<" "<<n/3<<endl;
        else if(n%3==1)
        cout<<(n/3)+1<<" "<<n/3<<endl;
        else if(n%3==2)
        cout<<n/3<<" "<<(n/3)+1<<endl;
    }

return 0;
}