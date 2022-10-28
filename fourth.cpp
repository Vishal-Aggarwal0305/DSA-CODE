#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int k=0,max=0;
	    for(int i=0;i<s.length();i++){
	        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
	            k++;
	            if(k>max){
	                max=k;
	            }
	        }
	        else{
	            k=0;
	        }
	    }
	    if(max>2){
	        cout<<"HAPPY"<<endl;
	    }
	    else{
	        cout<<"SAD"<<endl;
	    }
	}
	return 0;
}