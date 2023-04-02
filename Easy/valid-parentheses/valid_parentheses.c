#include <stdbool.h>

char oneToOne(char c)
{
	if (c == ']')
		return ('[');
	else if (c == '}')
		return ('{');
	else
		return ('(');
}

bool isValid(char *s){
	char	opened[5001];
	int		i = 1;

	while (*s)
	{
		if (*s == ']' || *s == '}' || *s == ')')
		{
			char c = oneToOne(*s++);
			if (opened[i-- - 1] != c)
				return (false);
		}
		else
			opened[i++] = *s++;
	}
	return (i == 1);
}
