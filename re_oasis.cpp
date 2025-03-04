#include <iostream>
#include <stack>
#include <utility>

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int	n;
	std::cin >> n;
	int	in, same;
	long long	ct = 0;
	std::stack<std::pair<int, int> >	s;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> in;
		same = 1;
		while (!s.empty() && s.top().first < in)
		{
			ct += s.top().second;
			s.pop();
		}
		if (!s.empty() && s.top().first == in)
		{
			ct += s.top().second;
			same = s.top().second + 1;
			if (s.size() > 1)
				++ct;
			s.pop();
		}
		else if (!s.empty() && s.top().first != in)
			++ct;
		s.push(std::make_pair(in, same));
	}
	std::cout << ct;
	return 0;
}
