#include <stdio.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int a, back = 0, dp[1000001] = {1000001};
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a > dp[back])
			dp[++back] = a;
		else
		{
			int left = 0, right = back, mid, idx;
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
	printf("%d", back+1);
	return (0);
}
