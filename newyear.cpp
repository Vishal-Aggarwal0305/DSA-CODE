#include <iostream>
using namespace std;
int main()
{
    
    int n,k;
    cin>>n>>k;
    int time = 240,sum = 0,ans = 0;
    time -= k;
    for(int i=1; i<=n; i++){
        sum += i * 5;
        if(sum <= time){
            ans++;
        }
        else{
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}