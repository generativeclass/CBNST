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
