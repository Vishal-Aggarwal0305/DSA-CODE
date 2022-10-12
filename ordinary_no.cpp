#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int ordinary(int n);
int main(){
int t,n;
cin>>t;
while(t--)
{
    cin>>n;
    cout<<ordinary(n)<<endl;
}
return 0;
}
int ordinary(int n)
{
    int c=0;
    for(int i=1;i<=n;i=i*10+1)
    {
        for(int j=1;j<=9;j++)
        {
            if(i*j<=n)
            {
                c++;
            }
        }
    }
    return c;
} 
