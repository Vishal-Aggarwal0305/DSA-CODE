#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int N,K,shoot=0;
	    cin>>N>>K;
	    for(int i=0;i<N;i++){
	        int H;
	        cin>>H;
	        if(H>K){
	            shoot++;
	        }
	        
	    }
	    cout<<shoot<<endl;
	}
	return 0;
}