#include <iostream>

int	city[201];

int	find(int n)
{
	if (city[n] == 0)
		return n;
	else
		return city[n] = find(city[n]);
}

void	add(int i, int j)
{
	i = find(i);
	j = find(j);

	if (i == j)
		return ;
	else if (i > j)
		city[j] = i;
	else
		city[i] = j;
}

int	can(int travel[], int m)
{
	for (int i = 1; i < m; ++i)
	{
		if (find(travel[0]) != find(travel[i]))
			return 0;
	}
	return 1;
}

int	main(void)
{
	int	n, m, tmp;
	std::cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			std::cin >> tmp;
			if (tmp)
				add(i, j);
		}
	}

	int	travel[m];
	for (int i = 0; i < m; ++i)
		std::cin >> travel[i];
	if (can(travel, m))
		std::cout << "YES\n";
	else
		std::cout << "NO\n";

	return 0;
}
