#include <stdio.h>
#define MAX 10 // maximum size for rows/cols
// Input matrix
int inputMatrix(int rows, int cols, int arr[MAX][MAX])
{
     printf("Enter elements of the matrix:\n");
     for (int i = 0; i < rows; i++)
     {
          for (int j = 0; j < cols; j++)
          {
               printf("Matrix[%d][%d]: ", i, j);
               scanf("%d", &arr[i][j]);
          }
     }
     return 1; // success
}
// Print matrix
int printMatrix(int rows, int cols, int arr[MAX][MAX])
{
     for (int i = 0; i < rows; i++)
     {
          for (int j = 0; j < cols; j++)
          {
               printf("%d ", arr[i][j]);
          }
          printf("\n");
     }
     return 1; // success
}
// Addition
int addMatrix(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX])
{
     for (int i = 0; i < rows; i++)
          for (int j = 0; j < cols; j++)
               C[i][j] = A[i][j] + B[i][j];
     return 1;
}
// Subtraction
int subtractMatrix(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX])
{
     for (int i = 0; i < rows; i++)
          for (int j = 0; j < cols; j++)
               C[i][j] = A[i][j] - B[i][j];
     return 1;
}
// Multiplication
int multiplyMatrix(int r1, int c1, int A[MAX][MAX], int r2, int c2, int B[MAX][MAX], int C[MAX][MAX])
{
     if (c1 != r2)
     {
          printf("Matrix multiplication not possible!\n");
          return 0;
     }
     for (int i = 0; i < r1; i++)
     {
          for (int j = 0; j < c2; j++)
          {
               C[i][j] = 0;
               for (int k = 0; k < c1; k++)
               {
                    C[i][j] += A[i][k] * B[k][j];
               }
          }
     }
     return 1;
}
// Element-wise Division
int divideMatrix(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], float C[MAX][MAX])
{
     for (int i = 0; i < rows; i++)
          for (int j = 0; j < cols; j++)
          {
               if (B[i][j] != 0)
                    C[i][j] = (float)A[i][j] / B[i][j];
               else
                    C[i][j] = 0; // avoid division by zero
          }
     return 1;
}
int main()
{
     int rows, cols;
     printf("Enter number of rows (<=%d): ", MAX);
     scanf("%d", &rows);
     printf("Enter number of columns (<=%d): ", MAX);
     scanf("%d", &cols);

     int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
     float D[MAX][MAX];

     printf("\nMatrix A:\n");
     inputMatrix(rows, cols, A);
     printf("\nMatrix B:\n");
     inputMatrix(rows, cols, B);

     int choice;
     printf("\nChoose operation:\n");
     printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division (element-wise)\n");
     scanf("%d", &choice);

     if (choice == 1)
     {
          addMatrix(rows, cols, A, B, C);
          printf("\nResult (Addition):\n");
          printMatrix(rows, cols, C);
     }
     else if (choice == 2)
     {
          subtractMatrix(rows, cols, A, B, C);
          printf("\nResult (Subtraction):\n");
          printMatrix(rows, cols, C);
     }
     else if (choice == 3)
     {
          if (multiplyMatrix(rows, cols, A, rows, cols, B, C))
          {
               printf("\nResult (Multiplication):\n");
               printMatrix(rows, cols, C);
          }
     }
     else if (choice == 4)
     {
          divideMatrix(rows, cols, A, B, D);
          printf("\nResult (Division - element-wise):\n");
          for (int i = 0; i < rows; i++)
          {
               for (int j = 0; j < cols; j++)
               {
                    printf("%.2f ", D[i][j]);
               }
               printf("\n");
          }
     }
     else
     {
          printf("Invalid choice!\n");
     }

     return 0;
}