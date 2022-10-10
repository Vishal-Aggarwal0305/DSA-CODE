#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void solve(int arr[],int x,int a,int b,int c,int k)
{
    if(arr[x]==0 and k==2)
    {
        cout<<"YES"<<endl;
    }
    else if(arr[x]==0 and k!=2)
    {
        cout<<"NO"<<endl;
    }
    if(arr[x]==a and arr[x]!=0)
    {
        k++;
        x=a;
        solve(arr,x,a,b,c,k);
    }
    else if(arr[x]==b and arr[x]!=0)
    {
        k++;
        x=b;
        solve(arr,x,a,b,c,k);
    }
    else if(arr[x]==c and arr[x]!=0)
    {
        k++;
        x=c;
        solve(arr,x,a,b,c,k);
    }
}
int main(){
int t,k=0;
cin>>t;
while(t--)
{
    int x,a,b,c;
    cin>>x;
    cin>>a>>b>>c;
    int arr[4];
    arr[1]=a;
    arr[2]=b;
    arr[3]=c;
    solve(arr,x,a,b,c,k);
}
return 0;
}