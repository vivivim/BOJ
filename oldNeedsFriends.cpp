#include <iostream>
#include <queue>
using namespace std;

int	n, m, visited[601][601];
int	dx[4] = { -1, 0, 1, 0 };
int dy[4] = {0, -1, 0, 1 };
int	x, y, dst;
char campus[601][601];

void	bfs()
{
	queue<pair<int, int> >	q;
	q.push(make_pair(y, x));
	visited[y][x] = 1;

	while (!q.empty())
	{
		pair<int, int>	cur = q.front();
		q.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			pair<int, int>	next = make_pair(cur.first+dy[i], cur.second+dx[i]);
			if (next.first < 1 || next.first > n || next.second < 1 || next.second > m)
				continue;
			if (campus[next.first][next.second] == 'X')
				continue;
			if (visited[next.first][next.second] == 1)
				continue;
			if (campus[next.first][next.second] == 'P')
				++dst;
			q.push(next);
			visited[next.first][next.second] = 1;
		}
	}
}

int	main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> campus[i][j];
			if (campus[i][j] == 'I')
			{
				y = i;
				x = j;
			}
		}
	}

	bfs();
	if (!dst)
		cout << "TT";
	else
		cout << dst;

	return 0;
}
