#include <stdio.h>

int	main(void)
{
	int	num;
	scanf("%d", &num);

	int	ct = 1;
	int	dp[1000000] = {0};
	dp[ct] = 0;
	while (ct != num)
	{
		ct++;
		dp[ct] = dp[ct-1] + 1;
		if (ct%3 == 0)
			dp[ct] = dp[ct] < dp[ct/3]+1 ? dp[ct] : dp[ct/3]+1;
		if (ct%2 == 0)
			dp[ct] = dp[ct] < dp[ct/2]+1 ? dp[ct] : dp[ct/2]+1;
	}
	printf("%d", dp[ct]);
	return (0);
}
