#include <stdio.h>

int	main(void)
{
	int	n, m;
	scanf("%d %d", &n, &m);

	long long	a[n+1];
	long long	ct[1001] = {0,};
	a[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		a[i] += a[i-1];
		a[i] %= m;
		ct[a[i]]++;
	}

	long long	dst = ct[0];
	for (int i = 0; i < m; i++)
		dst += ct[i] * (ct[i] - 1) / 2;
	printf("%lld", dst);
	return (0);
}
