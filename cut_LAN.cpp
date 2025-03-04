#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int	k, n, tmp;
	std::cin >> k >> n;
	std::vector<int>	v;
	long long	l, mid, h;
	for (int i = 0; i < k; ++i)
	{
		std::cin >> tmp;
		v.push_back(tmp);
	}
	std::sort(v.begin(), v.end());
	l = 1;
	h = v[k-1];
	int	ct, ans;
	while (l <= h)
	{
		ct = 0;
		mid = (l+h)/2;
		for (int i = 0; i < k; ++i)
			ct += v[i]/mid;
		if (ct < n)
			h = mid - 1;
		else
		{
			ans = mid;
			l =  mid + 1;
		}
	}
	std::cout << ans;

	return 0;
}
