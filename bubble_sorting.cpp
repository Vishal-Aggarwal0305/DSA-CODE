#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the value for n : ";
    cin >> n;
    int arr[n];
    cout << "enter the elements for array : ";
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int counter = 1;
    while (counter < n)
    {
        for (int i = 1; i <= n-counter ; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        counter++;
    }
    cout << "Sorted Elements are : ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}
