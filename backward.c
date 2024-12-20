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
