#include <stdio.h>

int	sum(int pi[], int i)
{
	int	ans = 0;

	for (int j = 0; j <= i; j++)
		ans +=pi[j];
	return (ans);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	pi[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &pi[i]);

	int	tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1-i; j++)
		{
			if (pi[j] > pi[j+1])
			{
				tmp = pi[j];
				pi[j] = pi[j+1];
				pi[j+1] = tmp;
			}
		}
	}
	int	ans = 0;
	for (int i = 0; i < n; i++)
		ans += sum(pi, i);
	printf("%d", ans);
	return (0);
}
