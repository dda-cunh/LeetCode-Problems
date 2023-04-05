int indexInBase(char *base, char c)
{
	if (*base == c)
		return (0);
	return (1 + indexInBase(base + 1, c));
}

int titleToNumber(char *columnTitle){
	char    base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	long    pow = 1;
	int     n = 0;

	for (int i = strlen(columnTitle) - 1; i >= 0; i--, pow *= 26)
		n += pow * (indexInBase(base, columnTitle[i]) + 1);
	return (n);
}
