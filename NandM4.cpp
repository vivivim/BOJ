#include <iostream>
#include <vector>

std::vector<int>	v;

void	letsGoNandM(int n, int m, int s)
{
	if (v.size() == m)
	{
		std::vector<int>::iterator	it = v.begin();
		for (; it != v.end(); ++it)
			std::cout << *it << ' ';
		std::cout << '\n';
		return ;
	}
	for (int i = s; i <= n; ++i)
	{
		v.push_back(i);
		letsGoNandM(n, m, i);
		v.pop_back();
	}
}

int	main(void)
{
	int n, m;
	std::cin >> n >> m;
	
	letsGoNandM(n, m, 1);
	return 0;
}
