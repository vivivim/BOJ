#include <stdio.h>

int	main(void)
{
	int	t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int	k;
		scanf("%d", &k);
		int	size[k];
		for (int j = 0; j < k; j++)
			scanf("%d", &size[j]);

		int	dp[k], tmp, a, b;
		
		dp[0] = 2147483647;
		for (int j = 0; j < k; j++)
		{
			for (int l = j+1; l < k; l++)
			{
				tmp = size[j] + size[l];
				if (tmp < dp[0])
				{
					dp[0] = tmp;
					a = j;
					b = l;
				}
			}
		}
		size[a] = 0;
		size[b] = 0;

		for (int j = 1; j < k-1; j++)
		{
			for (int l = 0; l < k; l++)
			{
				for (int m = l+1; m < k; m++)
				{
					if (size[l] > 0 && size[m] > 0)
						dp[j] = (dp[j-1] + size[l] < size[l] + size[m]) ? (dp[j-1] + size[l]) : (size[l] + size[m]);
				}
			}
		}
		printf("%d", dp[k-2]);
	}
	return (0);
}

