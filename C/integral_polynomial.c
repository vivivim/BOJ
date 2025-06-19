#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*str;
	str = malloc(100);
	scanf("%s", str);

	char	*cp;
	int		i = 0;
	cp = str;
	if (*cp == '-')
		cp++;
	while (*cp >= '0' && *cp <= '9')
		cp++;
	if (!(*cp))
	{	
		int	only = atoi(str);
		if (!only)
		{
			printf("W");
			return (0);
		}
		else if (only == -1)
			printf("-");
		else if (only != 1 && only != -1)
			printf("%d", only);
		printf("x+W");
		return (0);
	}
	else if (*cp == 'x' && *(++cp) == '\0')
	{
		int	only = atoi(str) / 2;
		if (only != 1 && only != -1)
			printf("%d", only);
		else if (only == -1)
			printf("-");
		printf("xx+W");
		return (0);
	}	
	else
	{
		int first = atoi(str) / 2;
		str++;
		while (*str != '+' && *str != '-')
			str++;
		int	second = atoi(str);
		if (first == 1)
		{
			printf("xx");
			if (second > 1)
				printf("+%d", second);
			else if (second < -1)
				printf("%d", second);
			else if (second == 1)
				printf("+");
			else if (second == -1)
				printf("-");
			printf("x+W");
		}
		else if (first == -1)
		{
			printf("-xx");
			if (second > 1)
				printf("+%d", second);
			else if (second < -1)
				printf("%d", second);
			else if (second == 1)
				printf("+");
			else if (second == -1)
				printf("-");
			else
			{
				printf("+W");
				return (0);
			}
			printf("x+W");
		}
		else if (first > 1|| first < -1)
		{
			printf("%dxx", first);
			if (second > 1)
				printf("+%d", second);
			else if (second < -1)
				printf("%d", second);
			else if (second == 1)
				printf("+");
			else if (second == -1)
				printf("-");
			else
			{
				printf("+W");
				return (0);
			}
			printf("x+W");
		}
	}
	return (0);
}
