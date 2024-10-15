#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to calculate u used in the interpolation formula
float u_cal(float u, int n) {
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u - i);
    return temp;
}

// Function to calculate factorial of a number
int fact(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main() {
    int n;
    printf("Name -> Prakhar Tyagi\n");
    printf("Section -> C\n");
    printf("Roll no. -> 42\n\n");

    // Input the number of data points
    printf("Input the no. of values: ");
    scanf("%d", &n);

    float x[n], y[n][n];

    // Input the x values
    printf("Input the values of x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    // Input the corresponding y values
    printf("Input the values of y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i][0]);
    }

    // Creating the forward difference table
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }

    // Displaying the forward difference table
    printf("Difference table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%0.2f\t", y[i][j]);
        }
        printf("\n");
    }

    // Input the value for which interpolation is required
    int val;
    printf("Enter the value to interpolate: ");
    scanf("%d", &val);

    // Calculating u
    float u = (val - x[0]) / (x[1] - x[0]);

    // Applying Newton's Forward Interpolation formula
    float sum = y[0][0];
    for (int i = 1; i < n; i++) {
        sum = sum + (u_cal(u, i) * y[i][i]) / fact(i);
    }

    // Displaying the result
    printf("Value at %d is %0.4f\n", val, sum);

    return 0;
}
