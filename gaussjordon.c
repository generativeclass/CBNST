// #include <stdio.h>
// #include <math.h>

// #define SIZE 10

// // Function to display the matrix
// void displayMatrix(float a[SIZE][SIZE], int n) {
//     int i, j;
//     printf("\nMatrix:\n");
//     for(i = 0; i < n; i++) {
//         for(j = 0; j < n + 1; j++) {
//             printf("%0.3f\t", a[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     printf("Name -> Prakhar Tyagi\n");
//     printf("Section -> C\n");
//     printf("Roll no. -> 42\n\n");
//     float a[SIZE][SIZE], x[SIZE], ratio;
//     int i, j, k, n;
    
//     // 1. Reading number of unknowns
//     printf("Enter number of unknowns: ");
//     scanf("%d", &n);
    
//     // 2. Reading the Augmented Matrix
//     printf("Enter coefficients of Augmented Matrix:\n");
//     for(i = 0; i < n; i++) {
//         for(j = 0; j < n + 1; j++) {
//             printf("a[%d][%d] = ", i+1, j+1);  // Display in 1-based index but store in 0-based
//             scanf("%f", &a[i][j]);
//         }
//     }

//     printf("\nInitial Augmented Matrix\n");
//     displayMatrix(a, n);
    
//     // Applying Gauss-Jordan Elimination
//     for(i = 0; i < n; i++) {
//         // Checking for division by zero
//         if(a[i][i] == 0.0) {
//             printf("Mathematical Error: Division by zero!\n");
//             return 1;
//         }

//         // Making the other rows zero in current column
//         for(j = 0; j < n; j++) {
//             if(i != j) {
//                 ratio = a[j][i] / a[i][i];
//                 for(k = 0; k <= n; k++) {
//                     a[j][k] = a[j][k] - ratio * a[i][k];
//                 }
//             }
//         }

//         // Displaying the matrix after each step
//         printf("\nMatrix after step %d\n", i+1);
//         displayMatrix(a, n);
//     }
    
//     // Displaying the diagonal matrix
//     printf("\nFinal Diagonal Matrix\n");
//     displayMatrix(a, n);
    
//     // Obtaining and displaying the solution
//     for(i = 0; i < n; i++) {
//         x[i] = a[i][n] / a[i][i];
//     }

//     printf("\nSolution:\n");
//     for(i = 0; i < n; i++) {
//         printf("x[%d] = %0.3f\n", i+1, x[i]);
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
    double a[10][10], x[10];  // Adjusted size of x to match n
    // Input the augmented matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }    
    printf("\nInitial Augmented Matrix");
    display(a, n);
    for (int i = 0; i < n; i++) {       
        for (int j =0; j < n; j++) {
            if(i!=j){
            double ratio = a[j][i] / a[i][i];
            for (int k = 0; k < n + 1; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }}
        }
        printf("\nMatrix");
        display(a, n);
    }
    printf("\nDiagonal Matrix:\n");
    display(a, n);
   for(int i=0;i<n;i++){
       x[i]=a[i][n]/a[i][i];
   }
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }
    return 0;
}
