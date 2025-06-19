#include <iostream>
#include <queue>

int	n, k;
std::queue<std::pair<int, int> >	q;
bool	visited[100001];

int	main(void)
{
	std::cin >> n >> k;
	q.push(std::make_pair(n, 0));

	int	subin;
	int	time;
	int	dst = 2147483647;
	while (!q.empty())
	{
		subin = q.front().first;
		time = q.front().second;
		visited[subin] = true;
		q.pop();
		if (subin == k)
		{
			if (dst > time)
				dst = time;
		}
		if (subin+1 < 100001 && !visited[subin+1])
			q.push(std::make_pair(subin+1, time+1));
		if (subin-1 >= 0 && !visited[subin-1])
			q.push(std::make_pair(subin-1, time+1));
		if (subin*2 < 100001 && !visited[subin*2])
			q.push(std::make_pair(subin*2, time));
	}
	std::cout << dst;
}
