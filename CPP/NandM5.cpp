#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>	num;
std::vector<int>	seq;
bool				used[9];

void	letsGoNandM(int n, int m)
{
	if (seq.size() == m)
	{
		std::vector<int>::iterator	it;
		for (it = seq.begin(); it != seq.end(); ++it)
			std::cout << *it << ' ';
		std::cout << '\n';
	}

	for (int i = 0; i < n; ++i)
	{
		if (used[i] == false)
		{
			used[i] = true;
			seq.push_back(num[i]);
			letsGoNandM(n, m);
			seq.pop_back();
			used[i] = false;
		}
	}
}

int	main(void)
{
	int n, m, tmp;
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());

	letsGoNandM(n, m);
	return 0;
}
