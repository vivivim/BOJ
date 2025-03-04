#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int	n, m, tmp;
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
		l = 0;
		h = n-1;
		while (l <= h)
		{
			mid = (l+h)/2;
			if (tmp < v[mid])
				h = mid - 1;
			else if (tmp > v[mid])
				l = mid + 1;
			else
				break;
		}
		if (l > h)
			std::cout << "0\n";
		else
			std::cout << "1\n";
	}
	return (0);
}
