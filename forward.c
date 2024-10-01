#include <stdio.h> 
#define max 10 
void forward(float x[], float y[][max], int n) 
{ 
    int i, j; 
    float a ; 
    float h, u, sum, p; 
    for (j = 1; j < n; j++) { 
        for (i = 0; i < n - j; i++) { 
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1]; 
        } 
    } 
    printf("\n The forward difference table is:\n"); 
    for (i = 0; i < n; i++) { 
        printf("\n"); 
        for (j = 0; j < n - i; j++) { 
            printf("%f\t", y[i][j]); 
        } 
    } 
    printf("\nenter point of interpolation\n");
    scanf("%f",&a);
    p = 1.0; 
    sum = y[0][0]; 
    h = x[1] - x[0]; 
    u = (a - x[0]) / h; 
    for (j = 1; j < n; j++) { 
        p = p * (u - j + 1) / j; 
        sum = sum + p * y[0][j]; 
    } 
    printf("\nThe value of y at x=%0.1f is %0.4f\n", a, sum); 
} 
int main() 
{ 
    int n;
    float x[max],y[max][max];
    printf("Enter number of points\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   
        printf("enter points :x[%d]\n",i);
        scanf("%f",&x[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("enter values:y[%d]\n",i);
        scanf("%f",&y[i][0]);
    }
    forward(x,y,n); 

    return 0; 
} 




