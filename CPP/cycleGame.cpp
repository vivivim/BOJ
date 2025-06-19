#include <iostream>
#include <cstring>

int	find(int n, int *num)
{
	if (num[n] == 0)
		return n;
	else
		return num[n] = find(num[n], num);
}

void	add(int a, int b, int *num)
{
	a = find(a, num);
	b = find(b, num);

	if (a == b)
		return ;
	else if (a > b)
		num[a] = b;
	else
		num[b] = a;
}

int	isCycled(int num[], int a, int b)
{
	if (find(a, num) != find(b, num))
		return 0;
	return 1;
}

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int	n, m, i;
	std::cin >> n >> m;

	int	num[n];
	std::memset(num, 0, sizeof(num));
	int	a, b, ans = 0;
	for (i = 1; i <=m; ++i)
	{
		std::cin >> a >> b;
		if (ans == 0 && isCycled(num, a, b))
			ans = i;
		add(a, b, num);
	}
	std::cout << ans;
	return 0;
}
