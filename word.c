#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char str[100];
    gets(str);
    char temp[100];
    //count uppercase lowercase
    int up = 0, low = 0;
    for(int i = 0;i<strlen(str);i++)
    {
        if(isupper(str[i])== 1)
        up++;
        if(str[i]>='a' && str[i]<='z'){
        low++;
        }
        
    }
    //printf("%d %d", up, low);
    if(up>low)
    {
        for(int i = 0;i<strlen(str);i++)
        {
            char ch = toupper(str[i]);
            printf("%c", ch);
        }
    }
    if(up<=low)
    {
        for(int i = 0;i<strlen(str);i++)
        {
            char ch = tolower(str[i]);
            printf("%c", ch);
        }
    }
    return 0;
}