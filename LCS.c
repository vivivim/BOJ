#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char	*str[2];
	for (int i = 0; i < 2; i++)
	{
		str[i] = (char *)malloc(1001);
		scanf("%s", str[i]);
	}

	int	dp[1001][1001] = {0,};
	int	i = 0, j = 0;

	while (str[0][i])
	{
		j = 0;
		while (str[1][j])
		{
			if (str[0][i] == str[1][j])
				dp[i+1][j+1] = dp[i][j] + 1;
			else
				dp[i+1][j+1] = (dp[i][j+1] > dp[i+1][j]) ? dp[i][j+1] : dp[i+1][j];
		j++;
		}
		i++;
	}
	printf("%d", dp[i][j]);
	return (0);
}
