#include <stdio.h>
#include <math.h>
float f(float x)
{
    return pow(x, 2) - 2 * x;
}
int main()
{
    float t;
    printf("Enter the Tolerance Level: ");
    scanf("%f", &t);
    float L, R, FI, x1, x2, fx1, fx2;
    char ch;
    printf("Enter the Lower Limit: ");
    scanf("%f", &L);
    printf("Enter the Upper Limit: ");
    scanf("%f", &R);
    printf("K\t\tL\t\tR\t\tx1\t\tx2\t\tfx1\t\tfx2\t\tL/R\n");
    int k = 0;
    while ((R - L) > t)
    {
        FI = 1 / 1.618;
        x2 = L + FI * (R - L);
        x1 = L + R - x2;
        k++;
        if (f(x1) > f(x2))
        {
            ch = 'R';
        }
        if (f(x2) >= f(x1))
        {
            ch = 'L';
        }
        if ((R - L) <= t)
        {
            printf("%d\t\t%.2f\t\t%.2f\n", k, L, R);
            break;
        }
        else
        {
            printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%c\n", k, L, R, x1, x2, f(x1), f(x2), ch);
        }
        if (f(x1) > f(x2))
        {
            L = x1;
        }
        if (f(x2) >= f(x1))
        {
            R = x2;
        }
    }
    printf("The final interval is [%.2f,%.2f]\n", L, R);
    float xmin = (L + R) / 2;
    float fxmin = f(xmin);
    printf("Xmin = %.3f\nFXmin = %.3f\n", xmin, fxmin);
    return 0;
}
