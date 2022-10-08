// 2.	Write a program to demonstrate the concept of void pointer and NULL pointer.

#include <stdio.h>
int main()
{
    int i;
    char c;
    printf("Enter the number:");
    scanf("%d",&i);
    fflush(stdin);
    printf("\nEnter the character:");
    scanf("%c",&c);
    
    void *ptr; //--------> generic pointer or void pointer

    printf("size of pointer is %d\n---------------------------------------",sizeof(ptr));

    ptr = &i;  //pointing to address of int i
    printf("\npointer pointing to Number entered which is %d\n---------------------------------------",*(int*)ptr);

    ptr = NULL;
    printf("\npointer pointing to null pointer and value is %d\n---------------------------------------",ptr);
   
    ptr = &c;
    printf("\npointer pointing to Character entered which is %c\n---------------------------------------",*(char*)ptr);
}

