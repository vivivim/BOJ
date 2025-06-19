#include <stdio.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	ans = 666, tmp = 0;
	while (n)
	{
		if (ans%1000 == 666)
			n--;
		else
		{
			tmp = ans / 10;
			while (tmp)
			{
				if (tmp%1000 == 666)
				{
					n--;
					if (n)
						tmp += 1;
					break;
				}
				else
					tmp /= 10;
			}
		}
		if (n)
			ans += 1;
	}
	printf("%d", ans);
}
