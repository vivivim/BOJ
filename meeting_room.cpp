#include <iostream>
#include <algorithm>
#include <vector>

bool	compare(std::pair<int, int>a, std::pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int	main(void)
{
	int	n, a, b;
	std::cin >> n;
	std::vector<std::pair<int, int> >	v;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a >> b;
		v.push_back(std::make_pair(a, b));
	}
	//끝나는 시각 기준 내림차순 정렬
	std::sort(v.begin(), v.end(), compare);
	int	ct = 1, prevEnd = v[0].second;
	for (int i = 1; i < n; ++i)
	{
		if (prevEnd <= v[i].first)
		{
			ct++;
			prevEnd = v[i].second;
		}
	}
	std::cout << ct;
	return 0;
}
