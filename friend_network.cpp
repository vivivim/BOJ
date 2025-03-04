#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, std::string>	m;
std::unordered_map<std::string, int>			mCt;

std::string	find_route(std::string key)
{
	if (m[key].empty())
		return key;
	return m[key] = find_route(m[key]);
}

void	add(std::string &a, std::string b)
{
	a = find_route(a);
	b = find_route(b);

	if (a == b)
		return ;
	m[b] = a;
	mCt[a] += mCt[b];
}

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int	t, f;
	std::cin >> t;

	std::string	a, b;
	while (t--)
	{
		std::cin >> f;
		for (int i = 0; i < f; ++i)
		{
			std::cin >> a >> b;
			if (m.count(a) == 0)
			{
				m[a] = "";
				mCt[a] = 1;
			}
			if (m.count(b) == 0)
			{
				m[b] = "";
				mCt[b] = 1;
			}
			add(a, b);
			std::cout << mCt[a] << '\n';
		}
		m.clear();
		mCt.clear();
	}
	return 0;
}
