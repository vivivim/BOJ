#include <iostream>
#include <queue>

int	main(void)
{
	int a, b;
	std::cin >> a >> b;
	int	dst = -1;
	std::queue<std::pair<unsigned long long, int> >	q;
	q.push(std::make_pair(a, 1));
	while (!q.empty())
	{
		if (q.front().first == b)
		{
			dst = q.front().second;
			break ;
		}
		if (q.front().first * 2 <= b)
			q.push(std::make_pair(q.front().first*2, q.front().second+1));
		if (q.front().first * 10 + 1 <= b)
			q.push(std::make_pair(q.front().first*10+1, q.front().second+1));
		q.pop();
	}
	std::cout << dst;
	return 0;
}
