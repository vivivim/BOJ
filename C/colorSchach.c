#include <stdio.h>

int	is_white(char c)
{
	if (c == 'W')
		return (0);
	return (1);
}

int	is_black(char c)
{
	if (c == 'B')
		return (0);
	return (1);
}

int	main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	char schach[n][m];

	for (int i = 0; i < n; i++)
		scanf("%s", schach[i]);
	
	int	black = 0, white = 0;
	int bleast = -1, wleast = -1;
	for (int idx = 0; idx < n - 7; idx++)
	{
		for (int jdx = 0; jdx < m - 7; jdx++)
		{
			for (int i = idx; i < 8 + idx; i++)
			{
				if (i%2 == 0)
				{
					for(int j = jdx; j < 8 + jdx; j++)
					{
						if (j%2 == 0)
							black += is_black(schach[i][j]);
						else
							black += is_white(schach[i][j]);
					}
				}
				else
				{
					for(int j = jdx; j < 8 + jdx; j++)
					{
						if (j%2 == 0)
							black += is_white(schach[i][j]);
						else
							black += is_black(schach[i][j]);
					}
				}
			}
			if (bleast == -1)
				bleast = black;
			bleast = black <= bleast ? black : bleast;
			black = 0;
		}
	}
	for (int idx = 0; idx < n - 7; idx++)
	{
		for (int jdx = 0; jdx < m - 7; jdx++)
		{
			for (int i = idx; i < 8 + idx; i++)
			{
				if (i%2 == 0)
				{
					for(int j = jdx; j < 8 + jdx; j++)
					{
						if (j%2 == 0)
							white += is_white(schach[i][j]);
						else
							white += is_black(schach[i][j]);
					}
				}
				else
				{
					for(int j = jdx; j < 8 + jdx; j++)
					{
						if (j%2 == 0)
							white += is_black(schach[i][j]);
						else
							white += is_white(schach[i][j]);
					}
				}
			}
			if (wleast == -1)
				wleast = white;
			wleast = white <= wleast ? white : wleast;
			white = 0;
		}
	}
	int	result;
	result = bleast <= wleast ? bleast : wleast;
	printf("%d", result);
	return (0);
}
