#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	t, n, j, q, ct = 0;
	scanf("%d", &t);

	char	arr[1000001];
	memset(arr, 1, sizeof(arr));
	arr[0] = '\0';
	arr[1] = '\0';
	for (int i = 2; i <= 1000000; i++)
	{
		for (int j = i+i; j <= 1000000;)
		{
			if (arr[j] && j%i == 0)
				arr[j] = '\0';
			j += i;
		}
	}
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 2; i <= n/2; i++)
		{
			if (arr[i])
			{
				for (int j = n-i; i+j >= n; j--)
				{
					if (arr[j] && i+j == n)
						ct++;
				}
			}
		}
		printf("%d\n", ct);
		ct = 0;
	}
	return (0);
}
