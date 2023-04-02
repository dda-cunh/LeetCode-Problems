#include <stdlib.h>

char	*longestCommonPrefix(char **strs, int strsSize){
	int		i;
	char	*common;

	if (strsSize == 1 || !strs[0][0])
		return (strs[0]);
	common = (char *)malloc(201);
	for (i = 0; i < 200; i++)
	{
		int bad = 0;
		for (int j = 1; j < strsSize; j++)
		{
			if (!strs[j][i] || strs[0][i] != strs[j][i])
			{
				bad = 1;
				break ;
			}
		}
		if (bad)
			break ;
		common[i] = strs[0][i];
	}
	common[i] = '\0';
	return (common);
}
