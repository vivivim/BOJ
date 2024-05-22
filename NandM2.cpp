#include <iostream>

void	goNandM(int n, int m, int num, int ct)
{
	if (!ct)
	{
		std::cout << '\n';
		return ;
	}
}

int	main(void)
{
	int	n, m;
	std::cin >> n >> m;
	goNandM(n, m, 1, 0);
	return 0;
}
