#include <stdbool.h>

bool isPowerOfThree(int n){
	long cube = 3;

	if (n < 1)
		return (0);
	if (n == 1 || n ==3 || n == 9)
		return (1);
	if (!(n % 9))
		return (0);
	while (cube < n)
		cube *= 3;
	return (cube == n);
}
