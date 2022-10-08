#include <stdio.h>
int main()
{
    int i;
    char c;
    printf("Enter the number:");
    scanf("%d",&i);
    fflush(stdin);
    printf("Enter the character:");
    scanf("%c",&c);
    
    void *ptr; //--------> generic pointer or void pointer

    printf("size of pointer is %d",sizeof(ptr));

    ptr = &i;  //pointing to address of int i
    printf("\nNumber entered is %d",*(int*)ptr);

    ptr = NULL;
    printf("\nValue at null pointer is %d",ptr);
   
    ptr = &c;
    printf("\nCharacter entered is %c",*(char*)ptr);
}
