#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    float x[10];  
    float profit; 
};
int index1(float a, float c[20], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a == c[i])
        {
            return i;
        }
    }
}

void merge(float arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    
    float L[n1], R[n2];

    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(float *arr, int l, int r)
{
    if (l < r)
    {
        
        
        int m = l + (r - l) / 2;

        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

struct node knapsack(int *n, float *w, float *c, float *W)
{
    struct node p;
    int i, I[20];
    float v[20], unsortv[20], sortv[20], O[20], unsortc[20], unsortw[20];
    for (i = 0; i < *n; i++)
    {
        p.x[i] = 0;
        v[i] = c[i] / w[i];
        printf("%f ", v[i]);
    }
    for (i = 0; i < *n; i++)
    {
        unsortv[i] = v[i];
    }
    mergeSort(v, 0, *n - 1);

    for (i = 0; i < *n; i++)
    {
        sortv[i] = v[i];
    }
    for (i = 0; i < *n; i++)
    {
        unsortc[i] = c[i];
    }
    for (i = 0; i < *n; i++)
    {
        unsortw[i] = w[i];
    }
    for (i = 0; i < *n; i++)
    {
        v[i] = sortv[*n - i - 1];
    }
    printf("\n\n");

    for (i = 0; i < *n; i++)
    {
        printf("%f ", v[i]);
    }
    for (i = 0; i < *n; i++)
    {
        I[i] = index1(v[i], unsortv, *n);
    }
    printf("\nIndex array: ");
    for (i = 0; i < *n; i++)
    {
        printf("%d ", I[i]);
    }
    for (i = 0; i < *n; i++)
    {
        c[i] = unsortc[I[i]];
        w[i] = unsortw[I[i]];
    }
    i = 0;
    while ((*W != 0) && (i < *n))
    {
        if (*W >= w[i])
        {
            p.x[i] = 1;
            *W = *W - p.x[i] * w[i];
        }
        else
        {
            p.x[i] = *W / w[i];
            *W = *W - p.x[i] * w[i];
        }
        i = i + 1;
    }
    return p;
}
int main()
{
    float w[20], c[20], W; 
    int n, i;              
    cout<<"Enter the Number of Objects:";
    cin>>n;
    for (i = 0; i < n; i++)
    {
        
        cout<<"Enter the weight o object:";
        cin>>w[i];
    }
    for (i = 0; i < n; i++)
    {
        cout<<"Enter the cost :";
        cin>>c[i];
    }
   cout<<"Enter the Capacity ";
   cin>>W;
    struct node str = knapsack(&n, w, c, &W);
    cout<<"Final Solution is :";
    for (i = 0; i < n; i++)
        {
            cout<<str.x[i]<<" ";
        }
    str.profit = 0;
    for (i = 0; i < n; i++)
    {
        str.profit = str.profit + (c[i] * str.x[i]);
    }
    printf("\nMaximum profit is: %f", str.profit);
    return (0);
};