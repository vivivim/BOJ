#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string>	pocketmon;

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int	n, m;
	std::cin >> n >> m;

	std::string	idx;
	for (int i = 1; i <= n; ++i)
	{
		idx = std::to_string(i);
		std::cin >> pocketmon[idx];
		pocketmon[pocketmon[idx]] = idx;
	}

	std::string	quiz;
	while (m--)
	{
		std::cin >> quiz;
		std::cout << pocketmon[quiz] << '\n';
	}
		return 0;
}
