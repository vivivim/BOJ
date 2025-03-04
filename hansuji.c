#include <stdio.h>
#include <stdlib.h>

int	*get_su(int n)
{
	int	*su = malloc(sizeof(int) * 4);

	su[3] = n % 10;
	if (n / 10)
		su[2] = (n / 10) % 10;
	if (n / 100)
		su[1] = (n / 100) % 10;
	if (n / 1000)
		su[0] = 1;
	return (su);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int ct = 0;
	int	*su = malloc(sizeof(int) * 4);
	while (n)
	{
		su = get_su(n);
		if (su[0])
			;
		else if (su[1])
		{
			if (su[1] - su[2] == su[2] - su[3])
				ct++;
		}
		else if (su[2])
			ct++;
		else
			ct++;
		n--;
	}
	printf("%d", ct);
	return (0);
}
