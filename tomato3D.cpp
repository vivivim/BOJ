#include <iostream>
#include <queue>
using namespace std;

int	m, n, h, toma[101][101][101];
int	dst;
int	dx[6] = { 1, -1, 0, 0, 0, 0 };
int	dy[6] = { 0, 0, 1, -1, 0, 0 };
int	dz[6] = { 0, 0, 0, 0, 1, -1 };
queue<pair<pair<int, int>, int> >	q;

void	bfs()
{
	while (!q.empty())
	{
		int	curX = q.front().second;
		int	curY = q.front().first.second;
		int	curZ = q.front().first.first;
		q.pop();
		for (int i = 0; i < 6; ++i)
		{
			int	nextX = curX + dx[i];
			int	nextY = curY + dy[i];
			int	nextZ = curZ + dz[i];
			if (nextX > m || nextX < 1 || \
				nextY > n || nextY < 1 || \
				nextZ > h || nextZ < 1)
				continue;
			if (toma[nextZ][nextY][nextX] == 0)
			{
				toma[nextZ][nextY][nextX] = toma[curZ][curY][curX] + 1;
				q.push(make_pair(make_pair(nextZ, nextY), nextX));
			}
		}
	}
}

int	main(void)
{
	cin >> m >> n >> h;
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= m; ++k)
			{
				cin >> toma[i][j][k];
				if (toma[i][j][k] == 1)
					q.push(make_pair(make_pair(i, j), k));
			}
		}
	}
	bfs();
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= m; ++k)
			{
				if (toma[i][j][k] == 0)
				{
					cout << -1;
					return 0;
				}
				if (dst < toma[i][j][k])
					dst = toma[i][j][k];
			}
		}
	}
	cout << dst - 1;
	return 0;
}
