#include <iostream>
#include <vector>

std::vector<int>	seq;
bool				used[9];
void	goNandM(int n, int m)
{
	if (seq.size() == m)
	{
		std::vector<int>::iterator	it = seq.begin();
		for (; it != seq.end(); ++it)
			std::cout << *it << ' ';
		std::cout << '\n';
	}
	for (int i = 1; i <= n; ++i)
	{
		if (used[i] == false)
		{
			used[i] = true;
			seq.push_back(i);
			goNandM(n, m);
			used[i] = false;
			seq.pop_back();
		}
	}
}

int	main(void)
{
	int	n, m;
	std::cin >> n >> m;

	goNandM(n, m);
	return 0;
}
