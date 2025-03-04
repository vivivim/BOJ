#include <stdio.h>

int	max(int incre[], int n)
{
	int	max = -2147483648;
	while (n--)
	{
		if (max < incre[n])
			max = incre[n];
	}
	return (max);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	num[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	int	incre[n], temp = 0;
	incre[0] = 1;
	for (int i = 1; i < n; i++)
	{
		incre[i] = 1;
		temp = 0;
		for (int j = i-1; j >= 0; j--)
		{
			if (num[j] < num[i] && temp < incre[j])
			{
				incre[i] = incre[j] + 1;
				temp = incre[j];
			}
		}
	}

	int	decre[n];
	decre[n-1] = 1;
	for (int i = n-2; i >= 0; i--)
	{
		decre[i] = 1;
		temp = 0;
		for (int j = i+1; j < n; j++)
		{
			if (num[j] < num[i] && temp < decre[j])
			{
				decre[i] = decre[j] + 1;
				temp = decre[j];
			}
		}
	}

	int	dp[n];
	for (int i = 0; i < n; i++)
		dp[i] = incre[i] + decre[i];
	printf("%d", max(dp, n)-1);
}
