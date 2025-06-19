#include <stdio.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	five = 0;
	int	three = 0;
	int	total = 2147483647;
	int	temp = 0;
	for(int i = 0; i <= n/5; i++)
	{
		five = i;
		if ((n - 5*five) % 3)
			total = -1;
		else
		{
			three = (n - 5*five) / 3;
			temp = five + three;
		}
		if ((total == -1 || temp < total) && temp != 0)
			total = temp;
	}
	printf("%d", total);
	return (0);
}

