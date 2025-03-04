#include <iostream>

long long	f(int n, int k)
{
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += std::min((int)(k/i), n);
	}
	return ans;
}
int	main(void)
{
	long long	k, n, h, l = 1;
	std::cin >> n >> k;
	h = k;

	while (l <= h)
	{
		long long	mid = (l + h) / 2;
		if (f(n, mid) >= k)
			h = mid - 1;
		else
			l = mid + 1;
	}
	std::cout << l;
	return 0;
}
