#include <iostream>
#include<string>
using namespace std;

int main() {
	// your code goes here
	int t;
	string h,g,n;
	cin>>t;
	for(int l=0;l<t;l++)
	{
	    cin>>h>>g;
	    n="BBBBB";
	for(int i=0;i<5;i++)
	{
	    if(h[i]==g[i])
	    n[i]='G';
	}
	cout<<n<<endl;
	}
	return 0;
}
