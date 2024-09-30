#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double f(double x) {return 3 * x - cos(x) - 1;}
double g(double x) {return 3 + sin(x);}
int main() {
    printf("Name -> Prakhar Tyagi\n");
    printf("Section -> C\n");
    printf("Roll no. -> 42\n\n");
    double a, b, x0, x1, f0, f1, g0, e;
    int step = 1, N;
    do {
        printf("Input the initial guess a and b: "); 
        scanf("%lf %lf", &a, &b); 
        if (f(a) * f(b) >= 0) {
            printf("INVALID INITIAL GUESS: Please ensure f(a) * f(b) < 0\n");
        }
    } while (f(a) * f(b) >= 0);
    x0 = (fabs(f(a)) < fabs(f(b))) ? a : b;
    printf("Initial guess considered :%lf \n",x0);
    printf("Enter tolerable error:\n");
    scanf("%lf", &e);
    printf("Enter maximum iterations:\n");
    scanf("%d", &N);
    printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do {
        g0 = g(x0);
        f0 = f(x0);
        if (g0 == 0.0) {
            printf("Mathematical Error: Derivative is zero.\n");
            exit(0);}
        x1 = x0 - (f0 / g0);
        f1 = f(x1); // Calculate f(x1) before printing
        printf("%d\t\t%lf\t%lf\t%lf\t%lf\n", step, x0, f0, x1, f1);
        x0 = x1;
        step++;
        if (step > N) {
            printf("Not Convergent: Maximum iterations reached.\n");
            exit(0);
        }
    } while (fabs(f1) > e);
    printf("\nRoot is: %lf\n", x1);
    return 0;
}







// // newton rapson
// #include <stdio.h>
// #include<math.h>
// float f(float x){
//    return 3 * x - cos(x) - 1;
// }

// float g(float x){
//     return 3 + sin(x);
// }
// int main() {
//     float a,b,e;
//     float x1;
//     int maxitr,itr=0;
//     printf("enter initial guesses a,b: ");
//     scanf("%f%f",&a,&b);
//     while(f(a)*f(b)>=0){
//         printf("wrong initial guesses try again: ");
//         scanf("%f%f",&a,&b);
//     }
    
//     float x0=(fabs(f(a))<fabs(f(b)))?a:b;
    
//     printf("\ninitial guess asssumed = %f",x0);
    
//     printf("\nenter tolerance: ");
//     scanf("%f",&e);
//     printf("\nenter maxIteration: ");
//     scanf("%d",&maxitr);
    
//     do{
//         x1=x0-f(x0)/g(x0);
        
//         x0=x1;
//         itr++;
//         if(itr>=maxitr){
//             printf("\nmax itr reached\n");
//             break;
//         }
//     }while(fabs(f(x1))>e);
    
//     printf("ans= %f", x1);

//     return 0;
// }