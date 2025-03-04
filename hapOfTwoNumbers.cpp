#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int	n, tmp;
	std::cin >> n;
	std::vector<int>	v;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> tmp;
		v.push_back(tmp);
	}
	int	x, ct = 0;
	std::cin >> x;
	std::sort(v.begin(), v.end());

	int	i = 0, j = n-1;
	while (i != j && i < n && j >= 0)
	{
		if (v[i] + v[j] == x)
		{
			++ct;
			++i;
			--j;
		}
		else if (v[i] + v[j] > x)
		{
			--j;
		}
		else if (v[i] + v[j] < x)
		{
			++i;
		}
	}
	std::cout << ct;
	return 0;
}
