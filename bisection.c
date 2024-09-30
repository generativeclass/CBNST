#include <stdio.h>
#include <math.h>
double f(double x) {
    return x * x * x - 2 * x - 5;
}
void bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        printf("You have not assumed right a and b.\n");
        return;
    }
    double c;
    int iteration = 0;
    printf("Iteration\t a\t b\t c\t f(c)\n");
    printf("-------------------------------------\n");   
    while (1) {
        c = (a + b) / 2.0;
        printf("%d\t %lf\t %lf\t %lf\t %lf\n", iteration, a, b, c, f(c));
        if (fabs(f(c)) < tol) {
            break;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else a = c;       
        iteration++;
    }
    printf("The root is approximately: %lf\n", c);
}
int main() {
    double a, b, tol;
    printf("Name -> Prakhar Tyagi\n");
    printf("Section -> C\n");
    printf("Roll no. -> 42\n\n");
    printf("Initial guesses a and b: ");
    scanf("%lf %lf", &a, &b);    
    printf("Enter the tolerance: ");
    scanf("%lf", &tol);    
    bisection(a, b, tol);// one should give - other should +   
    return 0;
}


















// // Online C compiler to run C program online
// #include <stdio.h>
// #include<math.h>
// float f(float x){
//     return x * x * x - 2 * x - 5;
// }
// int main() {
//     float a,b,e,c;
    
//     printf("enter assumed roots a,b: ");
//     scanf("%f%f",&a,&b);
//     while(f(a)*f(b)>0){
//         printf("wrong root assumed try again: ");
//         scanf("%f%f",&a,&b);
//     }
   
//     printf("enter tolerance:  ");
//     scanf("%f",&e);
//     do{
//         c=(a+b)/2.0;
//         if(f(c)*f(a)>0){
//             a=c;
//         }
//         else{
//             b=c;
//         }
        
//     }while(fabs(f(c))>e);
//     printf("root is %f",c);

//     return 0;
// }