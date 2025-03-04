#include <iostream>
#include <queue>

int	n, k;
std::queue<std::pair<int, int> >	q;
bool	visited[100001];

int	main(void)
{
	std::cin >> n >> k;
	q.push(std::make_pair(n, 0));

	int	ct = 0;
	int	dst = 0;
	while(!q.empty())
	{
		visited[q.front().first] = true;
		if (q.front().first == k)
		{
			if (!dst)
				dst = q.front().second;
			if (dst == q.front().second)
				ct++;
		}
		if (dst && dst < q.front().second)
			break ;
		int	walk = q.front().first + 1;
		int	back = q.front().first - 1;
		int	fly = q.front().first * 2;
		int	time = q.front().second + 1;
		q.pop();
		if (walk < 100001 && !visited[walk] )
			q.push(std::make_pair(walk, time));
		if (back >= 0 && !visited[back])
			q.push(std::make_pair(back, time));
		if (fly < 100001 && !visited[fly])
			q.push(std::make_pair(fly, time));
	}
	std::cout << dst << '\n' << ct;
	return 0;
}
