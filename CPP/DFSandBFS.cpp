#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

int	peak[1001][1001];
std::vector<int>	dst;
int	visited[1001];
int	n, m, v;

void	print()
{
	std::vector<int>::iterator	it = dst.begin();
	for (; it != dst.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

void	dfs(int k)
{
	dst.push_back(k);
	visited[k] = 1;
	if (dst.size() == n)
		return ;
	for (int i = 1; i <= n; ++i)
	{
		if (peak[k][i] && !visited[i])
		{
			dfs(i);
		}
	}
}

void	bfs(int k)
{
	std::queue<int>	q;
	q.push(k);
	dst.push_back(k);
	visited[k] = 1;
	int	next = 0;
	while (!q.empty())
	{
		k = q.front();
		q.pop();
		for (int i = 1; i <= n; ++i)
		{
			if (peak[k][i] && !visited[i])
			{
				dst.push_back(i);
				visited[i] = 1;
				q.push(i);
			}
		}
		if (dst.size() == n)
			break ;
	}
}

int	main(void)
{
	std::cin >> n >> m >> v;
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		std::cin >> a >> b;
		peak[a][b] = 1;
		peak[b][a] = 1;
	}
	dfs(v);
	print();
	dst.clear();
	memset(visited, 0, sizeof(visited));
	bfs(v);
	print();
	return 0;
}
