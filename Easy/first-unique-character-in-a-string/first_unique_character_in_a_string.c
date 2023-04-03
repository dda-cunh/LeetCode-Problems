int firstUniqChar(char *s){
	int	lowAlphabet[123] = {0};
	int	i = 0;

	for (i = 0; s[i]; i++)
		lowAlphabet[(int)s[i]]++;
	for (i = 0; s[i]; i++)
		if (lowAlphabet[(int)s[i]] == 1)
			return (i);
	return (-1);
}
