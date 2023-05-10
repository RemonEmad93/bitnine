#include <stdio.h>
#include <stdlib.h>

//method 1
/*
    Advantages:
        + Simple to implement
        + Easy to understand

    Disadvantages:
        - Can be inefficient for large values of n
*/
long piecewiseRecursion(int n) 
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return piecewiseRecursion(n - 3) + piecewiseRecursion(n - 2);
}

//method 2
/*
    Advantages:
        + More efficient than the first method for large values of n
        + Simple to implement
        + Easy to understand

    Disadvantages:
        - Requires more memory than method 1
        - Can be wasteful of memory for small values of n
*/
long fibonacci_memoization(int n, int *memo) 
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (memo[n] != -1)
        return memo[n];
    else 
    {
        memo[n] = fibonacci_memoization(n - 3, memo) + fibonacci_memoization(n - 2, memo);
        return memo[n];
    }
}

//method 3
/*
    Advantages:
        + Very efficient for large values of n
        + Simple to implement
        + Easy to understand

    Disadvantages:
        - Can be wasteful of memory for small values of n
*/
long piecewiseDP(int n) 
{
    long f[n + 1];
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;

    for (int i = 3; i <= n; i++)
        f[i] = f[i - 3] + f[i - 2];

    return f[n];
}


// int main() 
// {
//     int n, method;
//     long result;

//     printf("value of n: ");
//     scanf("%d", &n);

//     printf("choose method 1, 2 or 3: ");
//     scanf("%d", &method);

//     if(method == 1)
//         result = piecewiseRecursion(n);
//     else if(method ==2)
//     {
//         int *memo;
//         memo = (int *)malloc(sizeof(int) * (n + 1));
//         for (int i = 0; i <= n; i++)
//             memo[i] = -1;

//         result = fibonacci_memoization(n, memo);
//     }
//     else if(method ==3)
//         result = piecewiseDP(n);
//     else
//     {
//         printf("wrong number ");
//         return 0;
//     }

//     printf("F(%d) = %d\n", n, result);
//     return 0;
// }