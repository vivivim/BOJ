#include <stdio.h>
#include <string.h>

int	n;

int	recursion(const char *s, int l, int r)
{
	n++;
	if (l >= r)
		return (1);
	else if (s[l] != s[r])
		return (0);
	return (recursion(s, l+1, r-1));
}

int	isPalindrome(const char *s)
{
	return (recursion(s, 0, strlen(s)-1));
}

int	main(void)
{
	int	t;
	scanf("%d", &t);

	char	str[1001];
	for (int i = 0; i < t; i++)
	{
		n = 0;
		scanf("%s", str);
		printf("%d", isPalindrome(str));
		printf(" %d\n", n);
	}
	return (0);
}
