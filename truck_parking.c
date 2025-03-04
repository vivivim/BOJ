#include <stdio.h>

int	main(void)
{
	int	a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int	from[3], to[3];
	for (int i = 0; i < 3; i++)
		scanf("%d %d", &from[i], &to[i]);

	int	count = 0, ans = 0;

	for (int i = 1; i < 100; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i >= from[j] && i < to[j])
				count++;
		}
		if (count == 1)
			ans += a;
		else if (count == 2)
			ans += b * 2;
		else if (count == 3)
			ans += c * 3;
		count = 0;
	}
	printf("%d", ans);
	return (0);
}
