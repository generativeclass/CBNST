// #include<stdio.h>

// #define SIZE 10

// // Function to display the matrix
// void displayMatrix(float a[SIZE][SIZE], int n) {
//     int i, j;
//     printf("\nMatrix:\n");
//     for(i=1; i<=n; i++) {
//         for(j=1; j<=n+1; j++) {
//             printf("%0.3f\t", a[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     float a[SIZE][SIZE], x[SIZE], ratio;
//     int i, j, k, n;

//     // Basic Information
//     printf("Name -> Prakhar Tyagi\n");
//     printf("Section -> C\n");
//     printf("Roll no. -> 42\n\n");

//     // Input number of unknowns
//     printf("Enter number of unknowns: ");
//     scanf("%d", &n);

//     // Input augmented matrix
//     printf("Enter the elements of the augmented matrix row-wise:\n");
//     for(i=1; i<=n; i++) {
//         for(j=1; j<=n+1; j++) {
//             printf("a[%d][%d] = ", i, j);
//             scanf("%f", &a[i][j]);
//         }
//     }
    
//     // Display the initial augmented matrix
//     displayMatrix(a, n);

//     /* Applying Gauss Elimination */
//     for(i=1; i<=n-1; i++) {
//         if(a[i][i] == 0.0) {
//             printf("Mathematical Error: Pivot element is zero at step %d!\n", i);
//             return -1;
//         }
//         for(j=i+1; j<=n; j++) {
//             ratio = a[j][i] / a[i][i];  // Calculate the ratio to make elements zero below the pivot
//             for(k=1; k<=n+1; k++) {
//                 a[j][k] = a[j][k] - ratio * a[i][k];  // Row operation
//             }
//         }
//         // Display the intermediate matrix after each step
//         printf("\nMatrix after step %d:\n", i);
//         displayMatrix(a, n);
//     }

//     // Display the upper triangular matrix
//     printf("\nUpper Triangular Matrix:\n");
//     displayMatrix(a, n);

//     /* Back Substitution to find solution */
//     x[n] = a[n][n+1] / a[n][n];  // Solution for last variable
//     for(i=n-1; i>=1; i--) {
//         x[i] = a[i][n+1];  // Start with the constant from augmented matrix
//         for(j=i+1; j<=n; j++) {
//             x[i] = x[i] - a[i][j] * x[j];  // Substitute known values
//         }
//         x[i] = x[i] / a[i][i];  // Final division to isolate the variable
//     }

//     /* Displaying the solution */
//     printf("\nSolution:\n");
//     for(i=1; i<=n; i++) {
//         printf("x[%d] = %0.3f\n", i, x[i]);
//     }

//     return 0;
// }



#include <stdio.h>
void display(double a[10][10], int n) {
    printf("\n");    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
}
int main() {
    printf("Name -> Prakhar Tyagi\n");
    printf("Section -> C\n");
    printf("Roll no. -> 42\n\n");
    int n;
    printf("Enter unknowns: ");
    scanf("%d", &n);
    double a[10][10], x[10]; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }   
    printf("\nInitial Augmented Matrix");
    display(a, n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio = a[j][i] / a[i][i];
            for (int k = 0; k < n + 1; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
        printf("\nMatrix");
        display(a, n);
    }
    printf("\nUpper Triangular Matrix:\n");
    display(a, n);
    x[n-1] = a[n-1][n] / a[n-1][n-1];  // Start with the last variable
    for (int i = n - 2; i >= 0; i--) {  // Moving upwards
        x[i] = a[i][n];  // Start with the constant term
        for (int j = i + 1; j < n; j++) {
            x[i] = x[i] - a[i][j] * x[j];  // Subtract known terms
        }
        x[i] = x[i] / a[i][i];  // Divide by the coefficient of the unknown
    }
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }
    return 0;
}
