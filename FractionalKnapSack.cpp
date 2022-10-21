#include <bits/stdc++.h>
using namespace std;

struct knaps
{
    float x[20];
    float profit;
} knap;

void merge(float A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(float A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

struct node *knapsack(float *cost, float *weight, int size, float *capacity)
{
    int i;
    float ratio[20];
    for (i = 0; i < size; i++)
    {
        knap.x[i] = 0;
        ratio[i] = cost[i] / weight[i];
    }

    mergeSort(ratio, 0, size - 1);
    cout << "The value of weight is" << endl;
    for (i = 0; i < size; i++)
    {
        cout << weight[i] << endl;
    }
    cout << "The value of cost is" << endl;
    for (i = 0; i < size; i++)
    {
        cout << cost[i] << endl;
    }
    i = 0;

    while (*capacity > 0 && i < size)
    {
        if (*capacity >= weight[i])
        {
            knap.x[i] = knap.x[i] + 1;
        }
        else
        {
            knap.x[i] = *capacity / weight[i];
        }

        *capacity -= knap.x[i] * weight[i];
        knap.profit += knap.x[i] * cost[i];
        i++;
    }
}

int main()
{

    float weight[20], cost[20], capacity;
    int size;
    cout << "Enter the number of objects" << endl;
    cin >> size;

    cout << "Enter the weight of the objects" << endl;
    for (int i = 0; i < size; i++)
    {

        cin >> weight[i];
    }
    cout << "Enter the cost of the object" << endl;
    for (int i = 0; i < size; i++)
    {

        cin >> cost[i];
    }
    cout << "Enter the capacity of the knapsack" << endl;
    cin >> capacity;

    knapsack(cost, weight, size, &capacity);

    cout << "The knap profit is " << knap.profit << endl;

    return 0;
}