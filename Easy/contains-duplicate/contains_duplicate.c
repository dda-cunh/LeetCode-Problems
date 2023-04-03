#include <stdlib.h>

static int	ilen(long nb)
{
	int		l;

	l = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		l++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

char		*ft_itoa(int n)
{
	long	nb;
	char	*a;
	int		i;

	nb = n;
	i = ilen(nb);
	if (!(a = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	a[i--] = '\0';
	if (nb == 0)
	{
		a[0] = '0';
		return (a);
	}
	if (nb < 0)
	{
		a[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		a[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (a);
}

bool containsDuplicate(int *nums, int numsSize){
	int	universe[2000000001] = {0};

	for (int i = 0; i < numsSize; i++)
	{
		int absolute = nums[i];
		if (absolute < 0)
		{
			absolute *= -1;
		}
		universe[nums[absolute]]++;
		if (universe[nums[absolute]] > 1)
			return (true);
	}
	return (false);
}
