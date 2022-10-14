#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    long long int arr[3];
    while(t--)
    {
        long long sum = 0;
        for(int i = 0;i<3;i++){
        cin>>arr[i];
        sum = sum + arr[i];}
        if(sum %2 == 0)
        cout<<sum/2<<endl;
        else
        cout<<(sum-1)/2<<endl;
    }
    return 0;
}