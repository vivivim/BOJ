#include <iostream>
#include <queue>
using namespace std;

int	m, n;
int	toma[1001][1001];
int	dst;
int	dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
queue<pair<int, int> >	q;

void	bfs()
{
	while (!q.empty())
	{
		pair<int, int>	cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			pair<int, int>	next = make_pair(cur.first+dy[i], cur.second+dx[i]);
			if (next.first < 1 || next.first > n || next.second < 1 || next.second > m)
				continue;
			if (toma[next.first][next.second] == 0)
			{
				toma[next.first][next.second] = toma[cur.first][cur.second] + 1;
				q.push(next);
			}
		}
	}
}

int	main(void)
{
	cin >> m >> n;
	for (int j = 1; j <= n; ++j)
	{
		for (int k = 1; k <= m; ++k)
		{
			cin >> toma[j][k];
			if (toma[j][k] == 1)
				q.push(make_pair(j, k));
		}
	}
	
	bfs();

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (toma[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			if (toma[i][j] > dst)
				dst = toma[i][j];
		}
	}
	cout << dst - 1;
	return 0;
}
