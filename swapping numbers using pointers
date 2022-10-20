/* Simple Program for Swap Numbers Using Pointers In C++
Swap Definition
In computer programming, the act of swapping two variables refers to mutually exchanging the values of the variables. Usually, this is done with the data in memory
Using a temporary variable
The simplest and probably most widely used method to swap two variables is to use a third temporary variable: */
/*##Simple Example Program for Swap Numbers Using Pointers In C++*/
/*##Simple swap Programs, pointers Example C++ Programming*/
/*##Pass By Referense Function Example Program In C++ Programming*/

// Header Files
#include <iostream>
#include<conio.h>

using namespace std;

// Declare Swap Function Using Pointer 

void swap_numbers(int *value1, int *value2) {
   int temp;
   temp = *value1;
   *value1 = *value2;
   *value2 = temp;
}

int main() {
   // Declare Variables
   int number1, number2;

   cout << "Simple Example Program for Swap Numbers Using Pointers In C++\n";

   // Read User Input
   cout << "Enter value of Swap Number # 1: ";
   cin>>number1;
   cout << "Enter value of Swap Number # 2: ";
   cin>>number2;

   //Print Values before Swapping
   cout << "Before Swapping :  Number # 1=" << number1 << ",  Number # 2=" << number2 << "\n";

   //Call Swap Function By Passing Reference
   swap_numbers(&number1, &number2);

   //Print Values after Swapping
   cout << "After  Swapping :  Number # 1=" << number1 << ",  Number # 2=" << number2 << "\n";

   getch();
   return 0;
}
