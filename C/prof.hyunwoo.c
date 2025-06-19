#include <stdio.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);
	int	num;
	int	ct = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		for (int j = 5; j <= num; j *= 5)
			ct += num / j;
		printf("%d\n", ct);
		ct = 0;
	}
	return (0);
}
