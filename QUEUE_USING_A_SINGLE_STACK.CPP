#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;

void poping(stack < int > s) {
    if (s.empty())
      cout << "THE QUEUE IS EMPTY!" << endl;
    else {
      string str = "";
      while (s.size() != 1) {
        str += s.top();
        s.pop();
      }
      s.pop();   // removing the last element aka queue front

      for (int i = str.length() - 1; i >= 0; i--) 
        {
          s.push(str[i]);   // pushing back the remaining elements
        }
      }
}

void pushing(stack < int > &s, int ele) {
     s.push(ele);
}

void print(stack<int> st)
{
	string s="";
	while(!st.empty())
	{
		s+=st.top();
		st.pop();
	}

	reverse(s.begin(), s.end());
	for(auto i: s)
		cout<<(int)i<<" ";
}

    int main() {
      stack < int > st;
      pushing(st, 1);
      pushing(st, 2);
      pushing(st, 3);
      pushing(st, 4);
      pushing(st, 5);
      pushing(st, 6);
      poping(st);
      poping(st);
      poping(st);
      pushing(st, 7);
      pushing(st, 8);
      pushing(st, 9);
      pushing(st, 10);
     print(st);
return 0;
    }