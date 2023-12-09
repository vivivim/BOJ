#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_max(int len[3])
{
	if (len[0] > len[1] && len[0] > len[2])
		return (0);
	else if (len[1] > len[0] && len[1] > len[2])
		return (1);
	else
		return (2);
}

int	ft_mid(int len[3])
{
	if ((len[0] > len[1] && len[0] < len[2]) || (len[0] > len[2] && len[0] < len[1]))
		return (0);
	else if ((len[1] > len[0] && len[1] < len[2]) || (len[1] > len[2] && len[1] < len[0]))
		return (1);
	else
		return (2);
}

int	ft_min(int len[3])
{
	if (len[0] < len[1] && len[0] < len[2])
		return (0);
	else if (len[1] < len[0] && len[1] < len[2])
		return (1);
	else
		return (2);
}

int	main(void)
{
	char	*str[3];

	for (int i = 0; i < 3; i++)
	{
		str[i] = (char *)malloc(100);
		scanf("%s", str[i]);
	}

	int	dp[100] = {0,};
	int	len[3];

	for (int i = 0; i < 3; i++)
		len[i] = strlen(str[i]);
	
	int	max = ft_max(len);
	int	mid = ft_mid(len);
	int	min = ft_min(len);

	for (int i = 0; i < len[max]; i++)
	{
		for (int j = 0; j < len[mid]; j++)
		{
			for (int k = 0; k < len[min]; k++)
			{
				int	a = i, b = j, c = k;
				while (str[max][a] && str[mid][b] && str[min][c] \
						&& str[max][a] == str[mid][b] && str[mid][b] == str[min][c])
				{
					dp[i]++;
					a++;
					b++;
					c++;
				}
			}
		}
	}

	int	dst = -2147483648;
	for (int i = 0; i < 100; i++)
	{
		if (dst < dp[i])
			dst = dp[i];
	}
		printf("%d", dst);
	return (0);
}
