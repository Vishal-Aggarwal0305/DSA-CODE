#include <iostream>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    int temp=n;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]==a[i+1])
	        {
	            temp--;
	            continue;
	        }
	    }
	    cout<<temp<<endl;
	}
	return 0;
}