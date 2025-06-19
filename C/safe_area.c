#include <stdio.h>

int	sink[101][101];

void	finding(int n, int a, int b)
{
	sink[a][b] = 1;
	if (a+1 < n && !sink[a+1][b])
		finding(n, a+1, b);
	if (a-1 >= 0 && !sink[a-1][b])
		finding(n, a-1, b);
	if (b+1 < n && !sink[a][b+1])
		finding(n, a, b+1);
	if (b-1 >= 0 && !sink[a][b-1])
		finding(n, a, b-1);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	map[101][101], max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
			if (max < map[i][j])
				max = map[i][j];
		}
	}

	int	tmp = 0, dst = -10;
	for (int i = 0; i <= max; i++)
	{
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < n; b++)
			{
				if (map[a][b] <= i)
					sink[a][b] = 1;
				else
					sink[a][b] = 0;
			}
		}
		
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < n; b++)
			{
				if (!sink[a][b])
				{
					tmp++;
					finding(n, a, b);
				}
			}
		}
		if (dst < tmp)
			dst = tmp;
		tmp = 0;
	}
	printf("%d", dst);
	return (0);
}
