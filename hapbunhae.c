#include <stdio.h>

int	main(void)
{
	int	n, k;
	scanf("%d %d", &n, &k);

	int	bunhae[200][200];
	bunhae[0][0] = 1;
	for (int i = 1; i < 200; i++)
	{
		bunhae[i][0] = 1;
		bunhae[0][i] = i+1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < k; j++)
		{
			bunhae[i][j] = (bunhae[i-1][j] + bunhae[i][j-1]) % 1000000000;
		}
	}
	printf("%d", bunhae[n-1][k-1]);
	return (0);
}
