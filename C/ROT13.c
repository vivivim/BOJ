#include <stdio.h>
#include <stdlib.h>

int	is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void	rot13(char *str)
{
	if (*str >= 'a' && *str <= 'a' + 12)
		*str += 13;
	else if (*str >= 'A' && *str <= 'A' + 12)
		*str += 13;
	else if (*str > 'a' + 12 && *str <= 'z')
		*str = 'a' + 12 - ('z' - *str);
	else if (*str > 'A' + 12 && *str <= 'Z')
		*str = 'A' + 12 - ('Z' - *str);
}

int	main(void)
{
	char	*str;
	str = malloc(101);
	scanf("%[^\n]s", str);

	char	*copy = str;
	while (*copy != '\0')
	{
		if (is_alpha(*copy))
			rot13(copy);
		copy++;
	}
	printf("%s", str);
}
