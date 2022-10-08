#include <iostream>
using namespace std;
//function to print the array elements
void print(float a[], int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
//function for partition of the array elements
int splitting(float a[], int low, int high)
{
    float piv_elem = a[low];
    int p,q;
    p=low;
    q=high;
    while (p<q)
    {
        while (a[p]<=piv_elem)
            p++;
        while (a[q]>piv_elem)
            q--;
        if (p<q)
        {
            float temp=a[p];
            a[p]=a[q];
            a[q]=temp;
        }
    }
    a[low]=a[q];
    a[q]=piv_elem;
    return q;
}
//function to sort the array elements
void quickSort(float a[], int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=splitting(a,low,high);
        quickSort(a,low,pivot-1);
        quickSort(a,pivot+1,high);
    }
}

int main()
{
    float a[]={666,333,888,999,444};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<endl<<"Array elements are : ";
    print(a, n);
    quickSort(a,0,n-1);
    cout<<"The sorted array in descending order is: ";
    for (int i=0;i<=n/2;i++)
    {
        float temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;
    }
    print(a, n);
    return 0;
}
