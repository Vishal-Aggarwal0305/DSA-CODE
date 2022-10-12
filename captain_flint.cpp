#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void solve (int n)
{
    int a=n-16;
    if(n<=30)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        int b=2*7;
        int c=3*5;
        int d=3*7;
        int e=2*11;
        int f1=a-b;
        int f2=a-c;
        int f3=-a-d;
        int f4=a-e;
        if(f1>0 and f1!=b and f1!=6 and f1!=10)
        {
            cout<<"YES"<<endl;
            cout<<6<<" "<<10<<" "<<b<<" "<<f1<<endl;
        }
        else if(f2>0 and f2!=c and f2!=6 and f2!=10)
        {
            cout<<"YES"<<endl;
            cout<<6<<" "<<10<<" "<<c<<" "<<f2<<endl;
        }
        else if(f3>0 and f3!=d and f3!=6 and f3!=10)
        {
            cout<<"YES"<<endl;
            cout<<6<<" "<<10<<" "<<d<<" "<<f3<<endl;
        }
        else if(f4>0 and f4!=e and f4!=6 and f4!=10)
        {
            cout<<"YES"<<endl;
            cout<<6<<" "<<10<<" "<<e<<" "<<f4<<endl;
        }
    }

}
int main(){
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    solve(n);
}
return 0;
}