#include <stdio.h>

int	max(int num[], int n)
{
	int	dst = -10001;

	for (int i = 0; i < n; i++)
	{
		if (dst < num[i])
			dst = num[i];
	}
	return (dst);
}

int	min(int num[], int n)
{
	int	dst = 10001;

	for (int i = 0; i < n; i++)
	{
		if (dst > num[i])
			dst = num[i];
	}
	return (dst);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	x[n], y[n];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);
	
	printf("%d", (max(x, n)-min(x, n)) * (max(y, n)-min(y, n)));
	return (0);
}
