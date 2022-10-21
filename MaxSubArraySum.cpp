#include<bits/stdc++.h>
using namespace std;
int a[3];
int *find_max(int arr[], int low, int high)
{
    int maxA = INT_MIN, maxB = 0,
        start = 0, end = 0, s = 0;

    for (int i = 0; i < high; i++)
    {
        maxB += arr[i];

        if (maxA < maxB)
        {
            maxA = maxB;
            start = s;
            end = i;
        }

        if (maxB < 0)
        {
            maxB = 0;
            s = i + 1;
        }
    }

    a[0] = maxA;
    a[1] = start;
    a[2] = end;
    int *ptr = a;
    return ptr;
}

int max(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    else if (b > a && b > c)
        return b;
    else
        return c;
}

int crossingSubarray(int *arr, int low, int mid, int high)
{
    int leftMax = INT_MIN, rightMax = INT_MIN, sum = 0, i;

    for (i = mid; i >= low; i--)
    {
        sum += arr[i];

        if (sum > leftMax)
            leftMax = sum;
    }

    sum = 0;

    for (i = mid + 1; i <= high; i++)
    {
        sum += arr[i];

        if (sum > rightMax)
            rightMax = sum;
    }

    return (leftMax + rightMax);
}

int maximumSubarraySum(int *arr, int low, int high)
{
    int mid, leftSubarraySum, rightSubarraySum, crossingSubarraySum, maximum;

    if (low >= high)
        return arr[low];

    mid = (low + high) / 2;

    leftSubarraySum = maximumSubarraySum(arr, low, mid);
    rightSubarraySum = maximumSubarraySum(arr, mid + 1, high);
    crossingSubarraySum = crossingSubarray(arr, low, mid, high);

    return max(leftSubarraySum, rightSubarraySum, crossingSubarraySum);
}

int main()
{
    int arr[6] = {-2,-1,7,8,-5};
    int ch;
    int n = 6;
    int *d;

     cout << "PRESS\n 1.To see the result through navie approach\n";
    cout << "2 To see the result through divide and conqueror\n";
    cout << "3.exit\n";
    cout<<"{-2,-1, 7, 8, -5}"<<endl;
    do
    {

        cout << "Enter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:

            d = find_max(arr, 0, n);
            cout << *d << endl;
            cout << *(d + 1) << endl;
            cout << *(d + 2) << endl;
            break;
        case 2:
            //  int x=a[2];
            //   int y=a[1];
            for (int i = a[1]; i < a[2] + 1; ++i)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << maximumSubarraySum(arr, 0, n - 1) << endl;

            break;
        default:
            break;
        }
    } while (ch <= 2);

    return 0;
}