#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a[] ={6,2,5,5,4,5,6,3,7,6};
	    int A,B,sum=0,sum1=0,r=0;
	    cin>>A>>B;
	    sum = A+B;
	    while(sum!=0){
	        r = sum%10;
	        sum1 = sum1 + a[r];
	        sum = sum /10;
	    }
	    cout<<sum1<<endl;
	}
	return 0;
}