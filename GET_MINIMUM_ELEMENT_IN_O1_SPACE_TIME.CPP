	#include <iostream>
	#include <stack>
	using namespace std;

	class mystack{
		stack<int> st;
		int min_ele=-1;
	public:
		
		void pushing(int ele)
		{
	       if(st.empty())
	       	{
	       		min_ele=ele;
	       		st.push(ele);
	       	}

	       	else  if(ele<min_ele)
	       	{
	       		st.push(2*ele - min_ele);
	       		min_ele=ele;
	       	}

	       	else 
	       		st.push(ele);
		}


		void poping()
		{  if(!st.empty())
	        {
	        	if(st.top()>min_ele)	
	        	st.pop();
	        else{
	        	min_ele=2*min_ele - st.top();
	        	st.pop();
	        }
	    }

	    else cout<<"THE STACK IS EMPTY! CANT POP!"<<endl;
		}

	    int getmin()
	    {
	    	return min_ele;
	    }
	};

	int main()
	{
	 mystack mt;
	 mt.pushing(-9999);
	 mt.pushing(2);    // 1 2 3 4 8 
	 mt.pushing(3);
	 mt.pushing(-4400);
	 mt.pushing(5);
	 mt.pushing(6);
	 mt.pushing(7);
	 mt.poping();
	 mt.poping();
	 mt.poping();
	 mt.pushing(8);
	 mt.pushing(-100);
	 mt.pushing(9);
	 mt.pushing(0);

	 cout<<mt.getmin()<<" ";

	 return 0;

	}