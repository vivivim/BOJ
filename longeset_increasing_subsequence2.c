#include <stdio.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	a, back = 0, dp[n];
	int	left, right, mid, idx;
	for (int i = 0; i < n; i++)
		dp[i] = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a > dp[back])
			dp[++back] = a;
		else
		{
			left = 0;
			right = back;
			while (left <= right)
			{
				mid = (left + right) / 2;
				if (dp[mid] >= a)
				{
					idx = mid;
					right = idx - 1;
				}
				else
					left = mid + 1;
			}
			dp[idx] = a;
		}
	}
	printf("%d", back);
	return (0);
}
