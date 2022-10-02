#include <bits/stdc++.h>
using namespace std;

int SubsetSum(int arr[], int sum, int n){
    // means that sum come to a stopping condition that means true
    if(sum==0){
        return true;
    }
    // means size come to zero but above condition might be not true or may be yes
    if(n==0){
        return false;
    }

    if(arr[n-1]>sum){
        return SubsetSum(arr, sum, n-1);
    }
    else{
        return SubsetSum(arr, sum, n-1) || SubsetSum(arr, sum-arr[n-1], n-1);
    }
}

int main(){
    int arr[] = {3, 3, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    
    
        cout<<"Possible";
        int sum = 0;
        for(auto x: arr){
        sum+=x;
        }
        sum = sum/2;
        cout<<n;
    // cout<<SubsetSum(arr, sum, n);
        if(SubsetSum(arr, sum, n)){
        cout<<"Done";
        }
        else{
            cout<<"Not done";
        }
    
    
    

    
return 0;
}
