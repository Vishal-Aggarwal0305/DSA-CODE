#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for (int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    string s;
	    int count=0;
	    int top=0;
	    for (int j=0;j<n;j++){
	        cin>>s;
	        if (s=="START38"){
	            count++;
	        }
	        else if (s=="LTIME108"){
	            top++;
	        }
	    }
	    cout<<count<<" "<<top<<endl;
	}
	return 0;
}