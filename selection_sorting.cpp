#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter the value of n: ";
    cin >> n;
    int arr[n];
    cout << "enter the values of array:  " << endl;
    for (int i = 1; i <= n; i++) // getting input 
    {

        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) // selection sorting 
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    cout << "the sorted array is : ";
    for (int i = 1; i <= n; i++) // printing output 
    {
        cout << arr[i] << " ";
    }
}
