#include <stdio.h>

int main() {
   int array[10];
   int even[5] = {20, 22, 24, 26, 28};
   int odd[5]  = {21, 23, 25, 27, 29};
   
   int loop, index, e-len, o-len;
   
   e-len = o-len = 5;
   
   index = 0;
 
   for(loop = 0; loop < e-len; loop++) {
      array[index] = even[loop];
      index++;
   }
 
   for(loop = 0; loop < o-len; loop++) {
      array[index] = odd[loop];
      index++;
   }

   printf("\nEven -> ");
   
   for(loop = 0; loop < e-len; loop++)
      printf(" %d", even[loop]);
   printf("\nOdd  -> ");
   
   for(loop = 0; loop < o-len; loop++)
      printf(" %d", odd[loop]);

   printf("\nConcat -> ");
   
   for(loop = 0; loop < 10; loop++)
      printf(" %d", array[loop]);
   
   return 0;
}
