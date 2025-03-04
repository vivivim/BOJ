#include <stdio.h>

long long	sum(long long arr[], int from, int to)
{
	long long	ans = 0; 
	for (int i = from; i >= to; i--)
		ans += arr[i];
	return (ans);
}
/*전체적으로 최솟값을 구하고 계산하면 시간 초과, 앞에서부터 지금 가격보다 적은 게 나올 때까지 주유하면 통과 아하@!*/
int	main(void)
{
	int	n;
	scanf("%d", &n);
	long long	dis[n-1];
	for (int i = 0; i < n-1; i++)
		scanf("%lld", &dis[i]);
	long long	oil[n];
	for (int i = 0; i < n; i++)
		scanf("%lld", &oil[i]);

	long long	ans = 0;
	int	idx = 0, i = 0;

	for (i = 0; i < n - 1; i++)
	{
		if (oil[i] < oil[idx])
		{
			ans += oil[idx] * sum(dis, i-1, idx);
			idx = i;
		}
	}
	ans += oil[idx] * sum(dis, i-1, idx);
	printf("%lld", ans);
	return (0);
}
