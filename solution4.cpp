#include <iostream>
using namespace std;

int main() {
	int t,d;
	string n;
	cin>>t;
	while(t--)
	{
	    int yes=0,i;
	    cin>>d;
	    cin>>n;
	    for(i=0;i<d;i++)
	        if(n[i]=='5' || n[i]=='0')
	        {
	            yes++;
	            break;
	        }
	       
	     if(yes!=0)
	        cout<<"Yes\n";
	     else 
	        cout<<"No\n";
	}
	
	return 0;
}