#include <iostream>

void	goNandM(int n, int m, int num, int ct)
{
	if (ct && ct--)
		std::cout << num << '\n';
	else if (!ct)
		return ;
}

int	main(void)
{
	int	n, m;
	std::cin >> n >> m;
	goNandM(n, m, 1, m);
	for (int i = 0; i < n; i++)
	{

	}
}
