#include <stdio.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	num[n][2];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &num[i][0], &num[i][1]);
	for (int i = 0; i < n; i++)
		printf("%d\n", num[i][0]+num[i][1]);
	return (0);
}
