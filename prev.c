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
		if (only == 1)
			printf("x+W");
		else if (only == -1)
			printf("-x+W");
		else if (only == 0)
			printf("W");
		else
			printf("%dx+W", only);
		return (0);
	}
	else if (*cp == 'x' && *(++cp) == '\0')
	{
		int	only = atoi(str) / 2;
		if (only == 1)
			printf("xx+W");
		else if (only == -1)
			printf("-xx+W");
		else if (only > 1 || only < -1)
			printf("%dxx+W", only);
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
			if (second > 1)
				printf("xx+%dx+W", second);
			else if (second < -1)
				printf("xx%dx+w", second);
			else if (second == 1)
				printf("xx+x+W");
			else if (second == -1)
				printf("xx-x+W");
			else
				printf("xx+W");
		}
		else if (first == -1)
		{
			if (second > 1)
				printf("-xx+%dx+W", second);
			else if (second < -1)
				printf("-xx%dx+W", second);
			else if (second == 1)
				printf("-xx+x+W");
			else if (second == -1)
				printf("-xx-x+W");
			else
				printf("-xx+W");
		}
		else if (first > 1|| first < -1)
		{
			if (second > 1)
				printf("%dxx+%dx+W", first, second);
			else if (second < -1)
				printf("%dxx%dx+W", first, second);
			else if (second == 1)
				printf("%dxx+x+W", first);
			else if (second == -1)
				printf("%dxx-x+W", first);
			else
				printf("%dxx+W", first);
		}
	}
	return (0);
}
