#include <stdio.h>

int	main(void)
{
	char *str;
	str = malloc(101);
	scanf("%s", str);
	
	char *copy;
	int	count = 0;
	for (int i = 0; i < 26; i++)
	{
		copy = str;
		count = 0;
		while (*copy)
		{
			if (*copy == 'a' + i)
				count++;
			copy++;
		}
		printf("%d ", count);
	}
	return (0);
}
