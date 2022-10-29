#include<iostream>

using namespace std;

void rotate(int arr[], int n)
{
	int x = arr[n-1];
	int i;

	for(int i = n-1; i>0; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[0]=x;

}

int main()
{
	int arr[] = {1,2,3,4,5};

	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<"given array is : ";

	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	rotate(arr,n);

	cout<<"the final array :";

	for(int i =0; i<n; i++)
	{

		cout<<arr[i]<<" ";
	}
	cout<<end;
}
