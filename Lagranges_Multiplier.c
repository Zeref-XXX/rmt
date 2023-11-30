#include <stdio.h>
#include <math.h>
double objective_function(double x, double y)
{
    return 4 * pow(x, 2) - 2 * x * y + 6 * y * y;
}
double constraint_function(double x, double y)
{
    return x + y - 74;
}
int main()
{
    double x, y, lambda, epsilon;
    double step = 0.01;
    x = 0.0;
    y = 0.0;
    lambda = 1.0;
    epsilon = 0.0001;
    int max_iterations = 1000;
    int iteration = 0;
    while (iteration < max_iterations)
    {
        double gradient_x = 8 * x - 2 * y + lambda;
        double gradient_y = -2 * x + 12 * y + lambda;
        x = x - step * gradient_x;
        y = y - step * gradient_y;
        double constraint_value = constraint_function(x, y);
        lambda = lambda + step * constraint_value;
        if (fabs(constraint_value) < epsilon)
            break;
        iteration++;
    }
    printf("Optimized x: %lf\n", x);
    printf("Optimized y: %lf\n", y);
    printf("Optimized Objective Function Value: %lf\n", objective_function(x, y));
}
