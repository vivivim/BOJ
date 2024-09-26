#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int	dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visit[101][101];
char grid[101][101];
int	yes, no;
queue<pair<int, int> >	q;

void	bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visit[nx][ny])
				continue;
			if (grid[nx][ny] != grid[x][y])
				continue;
			visit[nx][ny] = true;
			q.push(make_pair(nx, ny));
		}
	}
}

int	main(void)
{
	int	n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cin >> grid[i][j];
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (!visit[i][j])
			{
				q.push(make_pair(i, j));
				bfs();
				++no;
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (grid[i][j] == 'R')
				grid[i][j] = 'G';
		}
	}
	memset(visit, false, sizeof(visit));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (!visit[i][j])
			{
				q.push(make_pair(i, j));
				bfs();
				++yes;
			}
		}
	}
	cout << no << ' ' << yes;

	return 0;
}
