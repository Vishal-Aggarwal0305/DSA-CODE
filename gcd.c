#include <stdio.h> 

  

int gcd(int num1, int num2) 

{  if(num2==0)

  {

    return num1;

  }

  while (num1 != num2) 

  { 

    if (num1 > num2)     

      num1 = num1 - num2;     

    else     

      num2 = num2 - num1;     

  }

   

  return num1; 

} 

int main() 

{ 

  int num1,num2;

  printf("Enter numbers: ");

  scanf("%d %d", &num1, &num2);

  printf(" Greatest Divisor is %d\n", gcd(num1, num2));  

  return 0; 

} 
