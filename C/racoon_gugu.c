#include <stdio.h>

void	go_go(int road[][3], int i, int *ct)
{
	for (int j = i+1; j < n-1; j++)
	{
		if (road[i][1] == road[j][0])
		{
			ct[j] += road[i][3];
			gogo(road, j);
			break ;
		}
	}
	return ;
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	road[n][3];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			scanf("%d", &road[i][j]);
	}

	long	ct[1000000] = 0;
	for (int k = 0; k < n-1; k++)
	{
		if (road[k][0] == 1)
			gogo(road, k, ct);

