#include <stdio.h>
#include <string.h>

int main()

{
    char str[60],new[60];
    int j=0;
    printf("Enter the string\n");
    gets(str);
    for(int i=0;i<strlen(str);i++)
    {
        if((str[i]>='A'&& str[i]<='Z') || (str[i]>='a' && str[i]<='z'))
        {
            new[j]=str[i];
            j++;
        }
    }
    new[j]='\0';
    printf("%s",new);
    return 0;
}
