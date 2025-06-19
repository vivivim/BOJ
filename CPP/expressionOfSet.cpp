#include <iostream>

int	arr[1000001];

int	union_find(int n)
{
	if (arr[n] == 0)
		return n;
	else
		return arr[n] = union_find(arr[n]);
}

void	combine(int a, int b)
{
	a = union_find(a);
	b = union_find(b);
	
	if (a == b)
		return ;
	else if (a > b)
		arr[b] = a;
	else
		arr[a] = b;
}

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, m;
	std::cin >> n >> m;

	int	z, a, b;
	while (m--)
	{
		std::cin >> z >> a >> b;
		if (z == 0 && a != b)
			combine(a, b);
		if (z == 1)
		{
			if (union_find(a) == union_find(b))
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
		}
	}
	return 0;
}
