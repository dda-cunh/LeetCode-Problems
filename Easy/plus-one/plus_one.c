#include <stdlib.h>
#include <stdbool.h>

bool    isFull(int *digits, int digitsSize)
{
	for (int i = 0; i < digitsSize; i++)
		if (digits[i] != 9)
			return (0);
	return (1);
}

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    bool    plus = 1;
	int     rSize;
	int     *r;

	*returnSize = isFull(digits, digitsSize) ? digitsSize + 1 : digitsSize;
	r = (int *)malloc(sizeof(int) * *returnSize);
	rSize = *returnSize - 1;
	for (int i = digitsSize - 1; i >= 0; i--, rSize--)
    {
        if (plus)
        {
            digits[i] = (digits[i] + 1) % 10;
            if (i > 0 && digits[i] == 0)
                plus = 1;
            else
                plus = 0;
        }
        r[rSize] = digits[i]; 
    }
    if (*returnSize != digitsSize)
        r[0] = 1;
	return (r);
}
