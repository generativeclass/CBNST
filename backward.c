#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float u_cal(float u, int n)
{
	float temp = u;
	for (int i = 1; i < n; i++)
		temp = temp * (u + i);
	return temp;
}
int fact(int n)
{
	int f = 1;
	for (int i = 2; i <= n; i++)
		f *= i;
	return f;
}
int main()
{
    int n;
    printf("Name -> Prakhar Tyagi\n");
    printf("Section -> C\n");
    printf("Roll no. -> 42\n\n");
    printf("Input the no. of values : ");
    scanf("%d",&n);
    float x[n],y[n][n];
    printf("Input the value of x : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&x[i]);
    }
    printf("Input the value of y : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&y[i][0]);
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=n-1;j>=i;j--)
        {
            y[j][i]=y[j][i-1]-y[j-1][i-1];
        }
    }
    
        // Check for uniformity in differences
//    int isUniform = 1;
//    for (int i = 1; i < n; i++) {
 //       if (y[i][1] - y[i - 1][1] != y[1][1] - y[0][1]) {
 //           isUniform = 0;
  //          break;
 //       }
 //   }
//
  //  if (!isUniform) {
        // printf("Error: The differences are not uniform.\n");
 //       return 1; // Exit with an error
  //  }

    printf("Difference table : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("%0.2f\t",y[i][j]);
        }
        printf("\n");
    }

    int val;
    printf("Calculating point : ");
    scanf("%d",&val);

    float u = (val-x[n-1])/(x[1]-x[0]);
    float sum=y[n-1][0];
    for(int i=1;i<n;i++)
    {
        sum=sum+ (u_cal(u,i) * y[n-1][i])/fact(i);
    }
    printf("Value at %d is %0.4f\n",val,sum);  
    return 0;
}







// // Online C compiler to run C program online
// #include <stdio.h>
// float cal_u(float u, int n){
//     float temp=u;
//     for(int i=1;i<n;i++){
//         temp*=(u+i);
//     }
//     return temp;
// }
// int fact(int n){
//     int f=1;
//     for(int i=2;i<=n;i++){
//         f*=i;
//     }
//     return f;
// }
// int main() {
//     // Write C code here
//     printf("enter number of elements: ");
//     int n;
//     float val;
//     scanf("%d",&n);
//     float x[10],y[10][10];
//     printf("enter values of x:\n");
//     for(int i=0;i<n;i++){
//         scanf("%f",&x[i]);
//     }
//     printf("enter values of y:\n");
//     for(int i=0;i<n;i++){
//         scanf("%f",&y[i][0]);
//     }
    
//     // differcence table;
//     for(int i=1;i<n;i++){
//         for(int j=n-1;j>=i;j--){
//             y[j][i]=y[j][i-1]-y[j-1][i-1];
//         }
//     }
    
//     printf("\nDifference table:\n");
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             printf("%f ",y[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
//     printf("enter interpolation value: ");
    
//     scanf("%f",&val);
    
//     float u=(val-x[n-1])/(x[1]-x[0]);
    
//     float sum=y[n-1][0];
//     for(int i=1;i<n;i++){
//         sum+=(cal_u(u,i)*y[n-1][i])/fact(i);
//     }
    
//     printf("Value at %.4f is %.4f\n", val, sum);

//     return 0;
// }