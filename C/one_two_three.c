#include <stdio.h>

int	main(void)
{
	int	t;
	scanf("%d", &t);

	int	n[t];
	for (int i = 0; i < t; i++)
		scanf("%d", &n[i]);

	int	ct[12];
	ct[0] = 0;
	ct[1] = 1;
	ct[2] = 2;
	ct[3] = 4;
	for (int i = 4; i < 12; i++)
		ct[i] = ct[i-3] + ct[i-2] + ct[i-1];

	for (int i = 0; i < t; i++)
		printf("%d\n", ct[n[i]]);
	return (0);
}
