#include<iostream>
#include<cstdlib>
#include<ctype.h>
#include<string.h>
using namespace std;
int stack[100];
int top = -1, front = 0;                               
void push(char);                                       
void pop();                                            

void push(char a)                                 
{
    top++;             
    stack[top]  =  a;      
}

void pop()                                
{
    top--;        
}

int main()
{
    int i, choice;
    char s[100],s1[100], b;
    cout<<"\n UID: 20BCS1474\n NAME:MOHIT KAUSHAL\n\n";
    cout<<"Enter the String\n";
    cin>>s1;

    for(i=0;i<=strlen(s);i++)
    {
        s[i]=tolower(s1[i]);                
    }          
    cout<<"\nLowercase of String "<<s1<<" is "<<s<<endl;    
 
    for (i=0;s[i]!='\0';i++)                   
    {
        if(int(s[i])>=65 && int(s[i])<=122)   
        {
            b = s[i];                          
            push(b);                          
        }
    }

    for (i=0;i<(strlen(s)/2);i++)             
    {
        if (stack[top] == stack[front])        
        {
            pop();                             
            front++;                        
        }
        else
        {
            cout<<endl<<s<<" is not a Palindrome\n"; 
            break;
        }
    }
    if ((strlen(s)/2)==front)                  
    cout<<endl<<s1<<" is Palindrome\n"; 
    cout<<endl<<"reverse of "<<s1<<" is ";
    for(int i=strlen(s);i>=0;i--)
    {
        cout<<s1[i];
    }
    return 0;
}
