#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int	n, m;
	scanf("%d %d", &n, &m);

	char	*dic[n];
	for (int i = 0; i < n; i++)
	{
		dic[i] = malloc(21);
		scanf("%s", dic[i]);
	}
	char	*quiz[m];
	for (int i = 0; i < m; i++)
	{
		quiz[i] = malloc(21);
		scanf("%s", quiz[i]);
	}
	int	num;
	for (int i = 0; i < m; i++)
	{
		if (*quiz[i] >= '0' && *quiz[i] <= '9')
		{
			num = atoi(quiz[i]);
			printf("%s\n", dic[num-1]);
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				if (!strcmp(dic[j], quiz[i]))
					printf("%d\n", j+1);
			}
		}
	}
	return (0);
}
