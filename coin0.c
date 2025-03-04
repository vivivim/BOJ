#include <stdio.h>

int	main(void)
{
	int	n, k;
	scanf("%d %d", &n, &k);

	int	coin[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);

	int	ans = 0;
	for (int i = n-1; i >= 0; i--)
	{
		if (!k)
			break;
		while(k - coin[i] >= 0)
		{
			k -= coin[i];
			ans++;
		}
	}
	printf("%d", ans);
}
