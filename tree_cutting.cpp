#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	int n, m, tmp;
	std::vector<int>	v;
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	int	l = 0;
	int	h = v[n-1] - 1;
	int	mid;
	long long	namu = 0, ans = 0;
	while (l <= h)
	{
		mid = (l+h)/2;
		for (int i = 0; i < n; ++i)
		{
			tmp = v[i] - mid;
			if (tmp > 0)
				namu += tmp;
		}
		if (namu >= m)
		{
			ans = mid;
			l = mid + 1;
		}
		else
			h = mid - 1;
		namu = 0;
	}
	std::cout << ans;

	return 0;
}
