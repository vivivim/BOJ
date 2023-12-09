#include <stdio.h>

/*int	main(void)
{
	int	 n, i, tmp;
	scanf("%d", &n);

	int	a[n];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int	changed = 0;
	for (i = 0; i < n; i++)
	{
		changed = 0;
		for (int j = 0; j < n - 1 -i; j++)
		{
			if (a[j] > a[j+1])
			{
				changed = 1;
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
		if (!changed)
			break ;
	}
	printf("%d", i+1);
	return (0);
}*/

int	main(void)
{
	int	 n, i, ct = 0;
		scanf("%d", &n);

	int	a[n];
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < n-1; i++)
	{
		if (a[i] > a[i+1])
			ct++;
	}
	printf("%d", ct+1);
	return (0);
}


