#include <stdio.h>
int main()
{
   char a[50];
   int ii=0,jj=0;
   char b[50],c[20] ;
    // scanf,printf
    printf("Enter scanf value\n");
    scanf("%s",a);
    printf("Scanf value is %s\n",a);

    //gets,puts
    printf("Enter gets string\n");
    fflush (stdin);
    gets(b);
    puts(b);

    //getchar,putchar
    printf("Enter getchar char\n");
    
    c[ii]=getchar();
    


    printf("Entered getchar character is :\n"); 
    putchar(c[jj]);
    printf("\n");

    printf("Enter in following format: word char number float_number\n");
    fflush(stdin);
    char ar[50];

    gets(ar);

    char str[40],arr2[60];
    char ch;
    int i;
    float f;
    
    sscanf(ar, "%s %c %d %f",str, &ch, &i, &f);
    printf("The value in string is : %s ", str);
    printf("\n");

    printf("The value in char is : %c ", ch);
    printf("\n");

    printf("The value in int is : %d ", i);
    printf("\n");

    printf("The value in float is : %f ", f);
    sprintf(ar, "%s %c %d %f",str, ch, i, f);
    return 0; 
    // printf("%c %c %d %f",str,ch,i,f);
     //sprintf(arr2,ar);
     //puts(arr2);
}

