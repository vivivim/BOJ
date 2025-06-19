#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	print(char *str[2], int dp[][1001], int i, int j)
{
	if (dp[i][j])
	{
		if (str[0][i-1] == str[1][j-1])
		{
			print(str, dp, i-1, j-1);
			printf("%c", str[0][i-1]);
		}
		else
			dp[i-1][j] > dp[i][j-1] ? print(str, dp, i-1, j) : print(str, dp, i, j-1);
	}
}

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
	char	lcs[1001][1001];
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
	printf("%d\n", dp[i][j]);
	print(str, dp, i, j);
	return (0);
}
