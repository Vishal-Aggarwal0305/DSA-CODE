#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define min(i, j) (((i) < (j)) ? (i) : (j))
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void insertionSort(int *a, int *size)
{
    int n = *size;
    for (int j = 1; j < n; j++)
    {
        int k = a[j];
        int i = j - 1;
        while ((i >= 0) && (a[i] > k))
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = k;
    }
}

int deterministicPartition(int *a, int *size, int x)
{
    int n = *size;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            a[i] = a[n - 1];
            a[n - 1] = x;
        }
    }
    int i = 0;
    for (int j = 0; j < (n - 1); j++)
    {
        if (a[j] <= x)
        {
            int tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
            i++;
        }
    }
    a[n - 1] = a[i];
    a[i] = x;

    return i;
}

int deterministicSelect(int *a, int i, int *size)
{
    int n = *size;
    if (n == 1)
    {
        return a[0];
    }

    int medianNumber = 0;
    for (int i = 0; i < n; i += 5)
    {
        int l = min(5, n - i);
        insertionSort(a + i, &l);
        int tmp = a[i / 5];
        a[i / 5] = a[i + l / 2];
        a[i + l / 2] = tmp;
        medianNumber++;
    }
    int medians;
    if (medianNumber > 1)
    {
        medians = deterministicSelect(a, medianNumber / 2, &medianNumber);
    }
    else
    {
        medians = a[0];
    }

    int k = deterministicPartition(a, &n, medians);

    if (k == i)
    {
        return medians;
    }
    else if (i < k)
    {
        return deterministicSelect(a, i, &k);
    }
    else
    {
        int d = n - k;
        return deterministicSelect(a + k, i - k, &d);
    }
}

// int deterministicSelect(int *a, int i, int n)
// {
//   if(n == 1) {
//     return a[0];
//   }
//   int n_meds = 0;
//   for(int i = 0; i < n; i += 5) {
//     int l = min(5, n - i);
//     insertion_sort(a + i, l);
//     int temp = a[i/5];
//     a[i/5] = a[i + l/2];
//     a[i + l/2] = temp;
//     n_meds++;
//   }

//   int finalmedian;
//   if(n_meds > 1) {
//     finalmedian = deterministicSelect(a, n_meds/2, n_meds);
//   }
//   else {
//     finalmedian = a[0];
//   }

//   int k = partition(a, n, finalmedian);

//   if(k == i) {
//     return finalmedian;
//   }
//   else if (i < k) {
//     return deterministicSelect(a, i, k);
//   }
//   else {
//     return deterministicSelect(a + k, i - k, n - k);
//   }
// }
int randomPartition(int *a, int *start, int *end, int m)
{
    int st = *start;
    int en = *end;
    int *pivotElement, randomNumber;
    if (m == -1)
    {
        time_t tt;
        srand(time(&tt));
        randomNumber = (rand() % (en - st + 1)) + st;
    }
    else
        randomNumber = m;
    swap(&a[en], &a[randomNumber]);
    pivotElement = &a[en]; 
    int i = (st - 1);
    for (int j = st; j <= en - 1; j++)
    {
        if (*(a + j) < *pivotElement)
        {
            i++;
            swap((a + i), (a + j));
        }
    }
    swap((a + i + 1), (a + en));
    return (i + 1);
}

int randomSelect(int *a, int *pn, int *rn, int i)
{
    int p, r;
    p = *pn;
    r = *rn;
    if (r == p)
        return a[p];
    int q = randomPartition(a, &p, &r, -1);
    int k = q - p + 1;
    if (i == k)
        return a[q];
    else if (i < k)
    {
        int d = q - 1;
        return randomSelect(a, &p, &d, i);
    }
    else
    {
        int d = q + 1;
        return randomSelect(a, &d, &r, i - k);
    }
}

void printarray(int *arr, int h)
{
    printf("\n [ %d", arr[0]);
    for (int i = 1; i < h; i++)
    {
        printf(", %d", arr[i]);
    }
    printf(" ]\n");
}

int main()
{
    int arr[50], nm, z;
    int ch, n = 10, d = 0, d2;
    time_t t;
    printf("\nEnter no. of elements : ");
    scanf("%d", &n);
    printf("\nEnter the array elements : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nInserted array is : ");
    printarray(arr, n);
    do
    {
        printf("\n 1 Randomized Select \n 2 Deterministic Select \n 3  Exit :\n");
        scanf("%d", &ch);
        printf("\n Enter the value of i for ith minimum  : ");
        scanf("%d", &nm);
        switch (ch)
        {
        case 1:
            d2 = n - 1;
            z = randomSelect(arr, &d, &d2, nm);
            printf("\n The %d minimum element is %d \n", nm, z);
            printf("\n *************************************************");
            break;

        case 2:
            z = deterministicSelect(arr, nm - 1, &n);
            printf("\n The %d minimum element is %d \n", nm, z);
            printf("\n *************************************************");
            break;
        }
    } while (ch != 3);
    return 0;
}