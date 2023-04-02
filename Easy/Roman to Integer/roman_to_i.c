const int	values[7] = {1, 5, 10, 50, 100, 500, 1000};
const char	keys[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int slen(char *s)
{
	if (!*s)
		return (0);
	return (slen(s + 1) + 1);
}

int align_dict(char lastChar)
{
	int i;

	i = 0;
	while (keys[i] != lastChar)
		i++;
	return (i);
}

int romanToInt(char *s)
{
	int integer = 0;
	int prev_value = 0;

	for (int i = slen(s) - 1; i >= 0; i--)
	{
		int curr_value = values[align_dict(s[i])];
		if (curr_value < prev_value)
			integer -= curr_value;
		else
			integer += curr_value;
		prev_value = curr_value;
	}
	return integer;
}
