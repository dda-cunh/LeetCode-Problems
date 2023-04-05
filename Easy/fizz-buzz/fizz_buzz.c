#include <stdlib.h>

char    *iToA(int i)
{
    int     ii = i;
    int     j = 0;
    char    *a;

    while (ii)
    {
        ii /= 10;
        j++;
    }
    a = (char *)malloc(j + 1);
    a[j] = '\0';
    while (i)
    {
        a[--j] = (i % 10) + 48;
        i /= 10;
    }
    return (a);
}

char    **fizzBuzz(int n, int *returnSize)
{
    char    **matrix;

    matrix = (char **)malloc(sizeof(char *) * n);
    *returnSize = n;
    for (int i = 0; i < n; i++)
    {
        if (!((i + 1) % 15))
            matrix[i] = "FizzBuzz";
        else if (!((i + 1) % 5))
            matrix[i] = "Buzz";
        else if (!((i + 1) % 3))
            matrix[i] = "Fizz";
        else
            matrix[i] = iToA(i + 1);
    }
    return (matrix);
}
