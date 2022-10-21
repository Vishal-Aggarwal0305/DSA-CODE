#include <stdio.h>
#include <stdlib.h>

int arr1[20][20], arr2[20][20], resultant[20][20];
void display(int row, int col, int arr[row][col]);

// FUCNTION TO INPUT THE MATRIX
void inputmatrix(int row, int col, int arr[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter the %d %d element : ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

// FUCNTION TO MULTIPLY MATRIX USING DIVIDE AND CONQUER
void daqmatmul(int m, int n, int a[][m], int b[][n], int c[m][n])
{
    static int i = 0, j = 0, k = 0;
    if (i > m)
        return;
    else if (i < m)
    {
        if (j < n)
        {
            if (k < n)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
                k++;
                daqmatmul(m, n, a, b, c);
            }
            k = 0;
            j++;
            daqmatmul(m, n, a, b, c);
        }
        j = 0;
        i++;
        daqmatmul(m, n, a, b, c);
    }
}

int **strassen(int *nm, int (*a)[*nm], int (*b)[*nm])
{
    int p[7], **result, n, n2;
    n = *nm;

    result = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        result[i] = malloc(sizeof(int *) * n);
    if (n == 1)
    {
        p[0] = a[0][0] * b[0][0];
        result[0][0] = p[0];
        return result;
    }
    p[0] = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    p[1] = (a[1][0] + a[1][1]) * b[0][0];
    p[2] = (a[0][0] * (b[0][1] - b[1][1]));
    p[3] = (a[1][1] * (b[1][0] - b[0][0]));
    p[4] = (a[0][0] + a[0][1]) * b[1][1];
    p[5] = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    p[6] = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    result[0][0] = p[0] + p[3] - p[4] + p[6];
    result[0][1] = p[2] + p[4];
    result[1][0] = p[1] + p[3];
    result[1][1] = p[0] + p[2] + p[5] - p[1];

    return result;
}

void display(int row, int col, int arr[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int **resultarray;
    printf("Gunit Kandhway 21037\n");
    printf("Enter the order of the matrix : ");
    int order;
    scanf("%d", &order);
    printf("Enter the first matrix : \n");
    inputmatrix(order, order, arr1);
    printf("Enter the second matrix : \n");
    inputmatrix(order, order, arr2);
    printf("Enter 1 to multiply using DIVIDE AND CONQUER\n");
    printf("Enter 2 to multiply using STRESSEN's ALGORITHM\n");
    printf("Enter 0 to exit\n");
    int choice;
    scanf("%d", &choice);
    while (choice != 0)
    {
        if (choice == 1)
        {
            daqmatmul(order, order, arr1, arr2, resultant);
            printf("Resultant matrix after matrix multiplication is : \n");
            display(order, order, resultant);
            return 0;
        }
        if (choice == 2)
        {
            resultarray = strassen(&order, arr1, arr2);
            for (int i = 0; i < order; i++)
            {
                printf(" | ");
                for (int j = 0; j < order; j++)
                printf(" %2d  ", resultarray[i][j]);
                printf("|\n");
            }
            return 0;
        }
    }
    return 0;
}
