#include <iostream>
#include <vector>

std::vector<int>	seq;

void	goNandM(int n, int m, int s)
{
	if (seq.size() == m)
	{
		std::vector<int>::iterator	it;
		for (it = seq.begin(); it != seq.end(); ++it)
			std::cout << *it << ' ';
		std::cout << '\n';
	}
	for (int i = s; i <=n; ++i)
	{
		seq.push_back(i);
		goNandM(n, m, i+1);
		seq.pop_back();
	}
}

int	main(void)
{
	int	n, m;
	std::cin >> n >> m;
	goNandM(n, m, 1);
	return 0;
}
