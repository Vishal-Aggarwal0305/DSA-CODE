#include <stdio.h>
#include <string.h>

int main()
{   
    char a[50];
    int len=0,b;
    
    printf("Enter the string\n");
    scanf("%s", a);
    for(int i = 0; i<50; i++){
        if(a[i]=='\0'){
            break;
        }
        else{
            len++;
        }
    }
    
    b=strlen(a);
    printf("length using program is %d and using predefined function is %d",len,b);
}
