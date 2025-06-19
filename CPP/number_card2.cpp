#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int	n, m, tmp, ct;
	std::cin >> n;
	std::vector<int>	v;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> tmp;
		v.push_back(tmp);
	}
	std::sort(v.begin(), v.end());
	std::cin >> m;
	int	l, mid, h;
	for (int i = 0; i < m; ++i)
	{
		std::cin >> tmp;
		auto	l = lower_bound(v.begin(), v.end(), tmp);
		auto	u = upper_bound(v.begin(), v.end(), tmp);
		std::cout << u - l << " ";
	}
	return 0;
}
