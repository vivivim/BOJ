#include <stdio.h>

int	main(void)
{
	int	n, k;
	scanf("%d %d", &n, &k);

	int	arr[n+1];
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <= n; i++)
		arr[i] = 1;

	for (int i = 2; i <= n; i++)
	{
		if (arr[i])
		{
			arr[i] = 0;
			k--;
			if (!k)
			{
				printf("%d", i);
				return (0);
			}
		}
		for (int j = i+1; j <= n; j++)
		{
			if (arr[j] && j % i == 0)
			{
				arr[j] = 0;
				k--;
				if (!k)
				{
					printf("%d", j);
					return (0);
				}
			}
		}
	}
	return (0);
}
