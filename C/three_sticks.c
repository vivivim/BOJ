#include <stdio.h>

int	max(int len[3])
{
	int dst = len[0];

	for (int i = 1; i < 3; i++)
	{
		if (dst < len[i])
			dst = len[i];
	}
	return (dst);
}

int	sum(int len[3])
{
	int dst = len[0] + len[1] + len[2];
	return (dst);
}

int	main(void)
{
	int	len[3];
	for (int i = 0; i < 3; i++)
		scanf("%d", &len[i]);

	if (len[0] == len[1] && len[1] == len[2])
		printf("%d", len[0]*3);
	else if (max(len) < sum(len)-max(len))
		printf("%d", sum(len));
	else if (max(len) == sum(len)-max(len))
		printf("%d", sum(len)-1);
	else if (max(len) > sum(len)-max(len))
		printf("%d", sum(len)*2-max(len)*2 - 1);
	return (0);
}
