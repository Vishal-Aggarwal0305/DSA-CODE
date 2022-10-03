#include <stdio.h>
#include <string.h>

int main()
{   
    char a[50];
    int len=0,b;
    
    printf("Enter the string\n");
    gets(a);
    
    while(a[len]!='\0')
    {
        len++;
    }
    b=strlen(a);
    printf("length using program is %d and using predefined function is %d",len,b);
}
