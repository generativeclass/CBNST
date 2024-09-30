#include <stdio.h>
#include <math.h>
double f(double x) {
    return x * x * x - 2 * x - 5;
}
int main() {
    printf("Name -> Prakhar Tyagi\n");
    printf("Section -> C\n");
    printf("Roll no. -> 42\n\n");

    double a, b, c,e;
    int itr = 0;
    do {
        printf("\nEnter two initial guesses (a, b):\n");
        scanf("%lf %lf", &a, &b);  // Correct format specifier for `double`
        if (f(a) * f(b) > 0) {
            printf("Incorrect guesses, try again. f(a) and f(b) should have opposite signs.\n");
        }
    } while (f(a) * f(b) > 0);   
    printf("Enter tolerable error:\n");
    scanf("%lf", &e); 
    printf("Iteration \t a \t  \t b \t\t\t c \t\t\t f(c)\n");
    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));  // Update c
        printf("%d\t\t %lf\t %lf\t %lf\t %lf\n", itr + 1, a, b, c, f(c));  // Using `itr + 1` for current iteration number
        if (f(a) * f(c) < 0) {
            b = c;  // Root is in the left half
        } else {
            a = c;  // Root is in the right half
        }
        itr++;
    } while (fabs(f(c)) >= e);
    printf("\nThe approximate root is %lf\n", c);
    printf("No. of iterations = %d\n", itr);
    return 0;
}
