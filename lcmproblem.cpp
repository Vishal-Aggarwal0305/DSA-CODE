#include <iostream>
using namespace std;
int lcm(int a , int b);
int main(){
    int t;
    cin>>t;
    int ans;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        for(int i = l;i<=r;i++)
        {
            int a = i;
            int b = r-i;
            int temp = lcm(a,b);
            if(temp<=r){
            cout<<a<<" "<<b<<endl;
            return 0;
            }
        }
    }
}

int lcm(int a , int b)
{
    int greater = (a>b)?a:b;
    while(greater++)
    {
        if(greater%a==0 && greater%b==0)
        break;
    }
    return greater;
}
