#include <iostream>
#include <queue>
using namespace std;

int n;
char map[26][26], visited[26][26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int> >	q;
priority_queue<int, vector<int>, greater<int> >	dst;
int tmp;
int	ct;

void	bfs()
{
	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if (visited[ny][nx] || map[ny][nx] == '0') continue;
			++tmp;
			visited[ny][nx] = '1';
			q.push(make_pair(ny, nx));
		}
	}
}

int	main(void)
{
	cin >> n;
	for (int i = 1; i <=n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cin >> map[i][j];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <=n; ++j)
		{
			if (visited[i][j] == '1') continue;
			visited[i][j] = '1';
			if (map[i][j] == '1')
			{
				q.push(make_pair(i, j));
				++ct;
				bfs();
				dst.push(tmp+1);
				tmp = 0;
			}
		}
	}
	cout << ct;
	while (!dst.empty())
	{
		cout << '\n' << dst.top();
		dst.pop();
	}
	return 0;
}
