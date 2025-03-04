#include <stdio.h>

int	main()
{
	int n;
	scanf("%d", &n);

	int	num[n];
	int	i = 0;
	while (i < n)
		scanf("%d", &num[i++]);

	i = 0;
	int	idx = 2;
	int	ct = 0;
	while (i < n)
	{
		while (idx < num[i])
		{
			if (num[i] % idx == 0)
				break;
			else
				idx++;
		}
		if (num[i] == 2 || idx == num[i])
			ct++;
		i++;
		idx = 2;
	}

	printf("%d", ct);
}
