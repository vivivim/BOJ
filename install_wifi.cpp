#include <iostream>
#include <vector>

int	main(void)
{
	int	n, c, tmp;
	std::cin >> n >> c;
	std::vector<int>	v;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> tmp;
		v.push_back(tmp);
	}
	std::sort(v.begin(), v.end());
	int	l = 1;
	int	h = v[n-1] - v[0];
	int	ct = 0;
	int	mid, from, ans;
	while (l <= h)
	{
		ct = 0;
		mid = (l+h)/2;
		from = v[0];
		for (int i = 1; i < n; ++i)
		{
			if (v[i] - from >= mid)
			{
				++ct;
				from = v[i];
			}
		}

		if (ct < c - 1)
			h = mid - 1;
		else
		{
			l = mid + 1;
			ans = mid;
		}
	}
	std::cout << ans << std::endl;

	return 0;
}
