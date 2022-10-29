#include <iostream>

using namespace std;

void printarray(int arr[], int size);
void swap(int arr[], int fi, int si, int d);

void leftrotate(int arr[], int d, int n)
{
    if (d == 0 || d == n)
        return;
    if (d > n)
        d = d % n;
    if (n - d == d)
    {
        swap(arr, 0, n - d, d);
        return;
    }
    if (d < n - d)
    {
        swap(arr, 0, n - d, d);
        leftrotate(arr, d, n - d);
    }
    else
    {

        swap(arr, 0, d, n - d);
        leftrotate(arr + n - d, 2 * d - n, d);
    }
}
void printarray(int arr[], int size)
{

    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swap(int arr[], int fi, int si, int d)
{

    int i, temp;
    for (i = 0; i < d; i++)
    {

        temp = arr[fi + i];
        arr[fi + i] = arr[si + i];
        arr[si + i] = temp;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    leftrotate(arr, 2, 7);
    printarray(arr, 7);
    return 0;
}
