/*For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains 
only rounded brackets or parenthesis and the input expression will always be balanced. A pair of the bracket is said to be redundant when a 
sub-expression is surrounded by unnecessary or needless brackets.

Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.
*/



bool checkRedundantBrackets(string str) {
	// Write your code here
     stack<char>v;
    for(int i=0;i<str.length();i++){
        if(str[i]!=')') v.push(str[i]);
        else {
            bool isredun=true;
            while(v.top()!='('){
                if(v.top()=='+' || v.top()=='-' || v.top()=='*' || v.top()=='/') isredun=false;
                v.pop();
            }
            if(isredun)return true;
            v.pop();
        }
    }
    return false;    
}
