#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define val 0.0174444444444444
double fun(double x) {return cos(x * val) - 3 * x + 1;}
double g(double x, int choice) {
    if (choice == 1) {
        return (cos(x * val) + 1) / 3; // Rearranged function for fixed-point iteration
    } else {
        return acos((3 * x* val - 1) ); // Alternate function for fixed-point iteration
    }}
double g_prime1(double x) {return (-sin(x * val)) / 3; }
double g_prime2(double x) {return -3 / sqrt(1 - pow((3 * x - 1), 2));}
int main() {
    double x0, x, error;
    int itr = 0;
    double a, b;   
    printf("Name -> Prakhar Tyagi\n");
    printf("Section -> C\n");
    printf("Roll no. -> 42\n\n");   
    printf("Input the initial guesses (in degree) a and b: ");
    scanf("%lf %lf", &a, &b);
    if (fun(a) * fun(b) >= 0) {
        printf("INVALID INITIAL GUESS\n");
        return 1;}
    double t1 = fabs(fun(a));
    double t2 = fabs(fun(b));
    x0 = (t1 < t2) ? a : b; // Choose the closer initial guess
    printf("Initial guess considered x: %lf\n", x0);
    printf("Input the error value: ");
    scanf("%lf", &error);
    double val1 = fabs(g_prime1(x0));
    double val2 = fabs(g_prime2(x0));
    int choice = 0;
    if (val1 < 1 && val2 < 1)choice = (val1 < val2) ? 1 : 0;
    else if (val1 < 1) choice = 1;        
    else choice = 0;
    do {
        x = g(x0, choice); // Perform iteration
        printf("xn = %lf , g(xn) = %lf , xn-1 = %lf where n=%d\n", x, g(x, choice), x0, itr);
        x0 = x;
        itr++;
    } while (fabs(fun(x)) >= error);
    printf("The final approximate root: %lf\n", x);
    printf("Number of iterations: %d\n", itr);   
    return 0;
}












// iterative
// #include <stdio.h>
// #include<math.h>
// #define val 0.0174444444444444
// float f(float x){
//    return 3 * x - cos(x*val) - 1;
// }

// float g(float x,int ch){
//     if(ch==0){
//         return (cos(x*val)+1)/3;
//     }
//     else return acos(3*x-1);
// }

// float g1(float x){
//     return -(sin(x*val))/3;
// }

// float g2(float x){
//     return -3 / sqrt(1 - pow((3 * x - 1), 2));
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
    
//     float val1=fabs(g1(x0));
//     float val2=fabs(g2(x0));
//     int ch;
    
//     if(val1<1 && val2<1){
//         ch=(val1<val2)?0:1;
//     }
//     else if(val1<1) ch=0;
//     else ch=1;
    
//     do{
//         x1=g(x0,ch);
        
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