#include <stdio.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	ct = 0;
	while (ct*ct < n)
	{
		ct++;
		if (n == 1)
			break;
		if (ct * ct > n)
		{
			ct--;
			break;
		}
		else if (ct * ct == n)
			break;
	}
	printf("%d", ct);
	return (0);
}
