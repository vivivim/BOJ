#include <stdio.h>

int	min(int rt[4])
{
	int	dst = rt[0];
	for (int i = 1; i < 4; i++)
	{
		if (dst > rt[i])
			dst = rt[i];
	}
	return (dst);
}

int	main(void)
{
	int	w, h, x, y;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	int	route[4];
	route[0] = x;
	route[1] = y;
	route[2] = w - x;
	route[3] = h - y;

	printf("%d", min(route));
	return (0);
}
