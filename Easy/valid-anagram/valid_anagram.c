#include <stdbool.h>

bool isAnagram(char *s, char *t)
{
    int slen = strlen(s);
    int a[26] = {0};

    if(slen == strlen(t))
    {
        for (int i=0; i < slen; i++)
        {
            a[s[i] - 97]++;
            a[t[i] - 97]--;
        }
        for (int i=0; i < slen; i++)
            if(a[s[i]-'a'])
                return (0);
        return (1);
    }
    return (0);
}
