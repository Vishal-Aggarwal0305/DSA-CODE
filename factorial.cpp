#include <iostream>
#include <vector>
using namespace std;

long long findFactorial(int n) {
    vector<long long> dp(n);
    // Factorial of 0 is 1
    dp[0] = 1;

    // We multiply previous calculated answer with the current number
    for(int i = 1; i <= n; i++) {
        dp[i] = i * dp[i-1];
    }

    return dp[n];

}

int main() {
    cout<<"Enter a number to find the factorial"<<endl;
    int n;
    cin>>n;
    cout<<findFactorial(n)<<endl;
    return 0;
}