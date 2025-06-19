#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);

	char	*str[n];
	for (int i = 0; i < n; i++)
	{
		str[i] = malloc(31);
		scanf("%s", str[i]);
	}
	
	int	count = 0, printed = 0;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (*str[j] == 'a' + i)
				count++;
		}
		if (count >= 5)
		{
			printf("%c", 'a'+i);
			printed = 1;
		}
		count = 0;
	}
	
	if (!printed)
		printf("PREDAJA");
	return (0);
}
