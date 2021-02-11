#include <stdio.h>

int main()
{
    printf("Pow function: %f\n Fib function: %d", pow(3, 4), fib(6));
    return 0;
}

int fib(x) int x;
{
    if(x == 0 || x == 1) return 1;
    return fib(x-1) + fib(x-2);
}

int calcsum(x, y, z) int x, y, z;
{
    return x+y+z;
}

int factorial(int a)
{
    if(a <= 1) return 1;
    return a*factorial(a-1);
}

double pow(double a, int b)
{
    if(b == 0) return 1;

    if(b > 0)
    {
        return a * pow(a, b-1);
    }
    else
    {
        return a * pow(a, b+1);
    }
}
