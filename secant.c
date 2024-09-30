#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double x) {return x * x * x - 5 * x + 1;}
int main() {
    printf("Name -> Prakhar Tyagi\n");
    printf("Section -> C\n");
    printf("Roll no. -> 42\n\n");
    printf(" x^3-5x+1 \n");
    double x0, x1, x2;
    float e;
    int itr=0,i=0;
    do{
        printf("Enter initial guess x0 and x1 ");
        scanf("%lf%lf", &x0,&x1);
        if(f(x0)*f(x1)>=0) printf("wrong input \n");
    }while(f(x0)*f(x1)>=0);
    printf("x0 = %lf\n", x0);
    printf("x1 = %lf\n", x1);
    printf("Error Value : ");
    scanf("%f",&e);
    printf("Input the no. of iteration : ");
    scanf("%d",&itr);
    if (f(x0)==f(x1)) 
    {
        printf("Mathematical error \n");
        return 1;
    }    
    do{
        if (f(x0)==f(x1)) 
        {
            printf("Mathematical error \n");
            return 1;
        }
        x2 = (x0 * f(x1)- x1 * f(x0))/(f(x1) - f(x0));
        printf("x0 = %lf, x1 = %lf, x2 = %lf\n", x0, x1, x2);
        x0=x1;       
        x1=x2;       
        i++;
        if(i>itr)
        {
            printf("ran out of interation");
            exit(0);
        }
    }while (fabs(f(x2)) >= e);
    printf("\nThe final approximate root is %lf\n", x1);
    return 0;
}
