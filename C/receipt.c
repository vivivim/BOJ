#include <stdio.h>

int	main(void)
{
	int	x;
	scanf("%d", &x);

	int	n;
	scanf("%d", &n);

	int	item[n][2];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &item[i][0], &item[i][1]);
	int	sum = 0;
	for (int i = 0; i< n; i++)
		sum += item[i][0] * item[i][1];
	if (x == sum)
		printf("Yes");
	else
		printf("No");
	return (0);
}
