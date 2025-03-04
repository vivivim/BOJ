#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len = 0;

	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	main(void)
{
	char	*str;
	str = malloc(101);
	scanf("%s", str);

	int	len = ft_strlen(str);

	for (int i = 0; i < len/2; i++)
	{
		if (str[i] != str[len-1-i])
		{
			printf("0");
			return (0);
		}
	}
	printf("1");
	return (0);
}
