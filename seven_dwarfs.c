#include <stdio.h>

void	sort(int *ans)
{
	int	tmp;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (ans[j] > ans[j+1])
			{
				tmp = ans[j];
				ans[j] = ans[j+1];
				ans[j+1] = tmp;
			}
		}
	}
}

int	main(void)
{
	int	ki[9];
	for (int i = 0; i < 9; i++)
		scanf("%d", &ki[i]);

	int	hap = 0, count = 0, ans[7];
	for (int a = 0; a < 3; a++)
	{
		ans[0] = ki[a];
		for (int b = a+1; b < 4; b++)
		{
			ans[1] = ki[b];
			for (int c = b+1; c < 5; c++)
			{
				ans[2] = ki[c];
				for (int d = c+1; d < 6; d++)
				{
					ans[3] = ki[d];
					for (int e = d+1; e < 7; e++)
					{
						ans[4] = ki[e];
						for (int f = e+1; f < 8; f++)
						{
							ans[5] = ki[f];
							for (int g = f+1; g < 9; g++)
							{
								ans[6] = ki[g];
								hap = ans[0] + ans[1] + ans[2] + ans[3] + ans[4] + ans[5] + ans[6];
								if (hap == 100)
								{
									sort(ans);
									for (int i = 0; i < 7; i++)
										printf("%d ", ans[i]);
									return (0);
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}
