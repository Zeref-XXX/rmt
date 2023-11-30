#include <stdio.h>
#include <math.h>
float f(float x)
{
    return pow(x, 2);
}
int main()
{
    int n;
    printf("Enter the Number of Iterations: ");
    scanf("%d", &n);
    float F[100];
    F[0] = 1;
    F[1] = 1;
    int i;
    for (i = 2; i <= n; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
    float L, R, fx1, fx2, x1, x2, FI;
    char ch;
    printf("Enter the Lower Limit : ");
    scanf("%f", &L);
    printf("Enter the Upper Limit : ");
    scanf("%f", &R);
    printf("K\t\tFk\t\tL\t\tR\t\tx1\t\tx2\t\tfx1\t\tfx2\t\tL/R\n");
    int k;
    for (k = 1; k <= n; k++)
    {
        FI = F[n - k] / F[n - k + 1];
        x2 = L + FI * (R - L);
        x1 = L + R - x2;
        if (f(x1) <= f(x2))
            ch = 'L';
        else
            ch = 'R';
        if (FI == 1)
        {
            printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n", k, FI, L, R);
        }
        else
        {
            printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%c\n", k, FI, L, R, x1, x2, f(x1), f(x2), ch);
        }
        if (f(x2) < f(x1))
        {
            L = x1;
        }
        if (f(x1) <= f(x2))
        {
            R = x2;
        }
    }
    printf("Final Interval is [%.2f,%.2f]\n", L, R);
    float xmin = (L + R) / 2;
    float fxmin = f(xmin);
    printf("Xmin = %.3f\nfxmin = %.3f\n", xmin, fxmin);
    return 0;
}
