#include <stdio.h>
# include <string.h>
int my_strspn(char str1[],char str2[])
{
    int i;
    for(i=0;i<strlen(str1);i++)
    {
        if(str1[i]!=str2[i])
        {
            break;
        }
    }
    return i;

}
int main()
{

     printf("\n%d",my_strspn("sonu","on"));
    printf("\n%d",strspn("son sonu","son"));
}


