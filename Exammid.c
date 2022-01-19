#include <stdio.h>
#include <math.h>

typedef struct
{
    double x1, x2;
} Q;

Q solveEq2(double a, double b, double c)
{
    double d = sqrt(b * b - 4 * a * c);
    Q ans = {(-b + d) / (2 * a), (-b - d) / (2 * a)};
    return ans;
}

void solveEq1(double a, double b, double c, double *x1, double *x2)
{
    double d = sqrt(b * b - 4 * a * c);
    *x1 = (-b + d) / (2 * a);
    *x2 = (-b - d) / (2 * a);
}

int main()
{
    double a, b, c;
    double x1, x2;
    printf("enter a b c ->");
    scanf("%lf%lf%lf", &a, &b, &c);
    solveEq1(a, b, c, &x1, &x2);
    Q ans = solveEq2(a, b, c);
    printf("x1 = %.2f, x2 = %.2f\n", x1, x2);
    printf("x1 = %.2f, x2 = %.2f\n", ans.x1, ans.x2);
    printf("prove it: %.2f\n", a * x1 * x1 + b * x1 + c);
    printf("prove it: %.2f\n", a * x2 * x2 + b * x2 + c);
    return 0;
}
