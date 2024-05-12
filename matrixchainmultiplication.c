#include <stdio.h>

void printParenthesis(int i, int j, int n, int bracket[][n])
{
    if (i == j)
    {
        printf("%c ", 'A' + i - 1);
        return;
    }

    printf("(");
    printParenthesis(i, bracket[i][j], n, bracket);
    printParenthesis(bracket[i][j] + 1, j, n, bracket);
    printf(")");
}

void matrixChainOrder(int arr[], int n)
{
    int minMul[n][n];
    int bracket[n][n];

    for (int i = 1; i < n; i++)
        minMul[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            minMul[i][j] = 99999999;

            for (int k = i; k <= j - 1; k++)
            {
                int q = minMul[i][k] + minMul[k + 1][j] + arr[i - 1] * arr[k] * arr[j];

                if (q < minMul[i][j])
                {
                    minMul[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }

    printf("Pyramid based on MinMul Matrix in the optimal substructure:\n");

    // Print pyramid based on minMul matrix values
    for (int i = 1; i < n; i++)
    {
        // Print spaces
        for (int space = 1; space <= n - i; ++space)
        {
            printf(" ");
        }

        // Print values
        for (int j = 1; j < n; j++)
        {
            if (j >= i)
            {
                printf("%d ", minMul[i][j]);
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    printf("Minimum number of multiplications required for matrix multiplication: %d\n", minMul[1][n - 1]);

    printf("Optimal Parenthesization: ");
    printParenthesis(1, n - 1, n, bracket);
    printf("\n");
}

int main()
{
    int n;
    int arr[10];

    printf("Enter the size of the array:\n ");
    scanf("%d", &n);

    printf("Enter the dimensions of %d matrices:\n ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    printf("\n");

    matrixChainOrder(arr, n);

    return 0;
}
   
