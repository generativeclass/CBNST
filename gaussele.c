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
