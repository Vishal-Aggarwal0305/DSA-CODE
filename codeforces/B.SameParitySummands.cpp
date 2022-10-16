#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;while(t--){
        long long n;int k;cin>>n>>k;
        if(n<k)
        cout<<"NO"<<endl;
       else if(n==k)
       {
        cout<<"YES"<<endl;
        for(int i=1;i<=k;i++)
        cout<<"1 ";
        cout<<endl;
       }

        else 
        {
            if(((n-(2*(k-1)))%2==0)&&(n-(2*(k-1)))>0)
            {
            cout<<"YES"<<endl;
            for(int i=1;i<=k-1;i++)
            cout<<"2 ";
            cout<<(n-2*(k-1))<<endl;
            }
            else if(((n-(k-1))%2!=0)&&(n-(k-1))>0)
            {
                cout<<"YES"<<endl;
                for(int i=1;i<=k-1;i++)
                 cout<<"1 ";
                 cout<<(n-(k-1))<<endl;
            }
            else
            cout<<"NO"<<endl;

        }
    }
}
