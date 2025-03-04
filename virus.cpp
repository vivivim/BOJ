#include <iostream>
#include <queue>
using namespace std;

int	com, line, net[101][101];
int infected[101];
queue<pair<int, int> >	q;
int	i, j;
int	ct;

void	bfs()
{
	while(!q.empty())
	{
		int	x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int a = 1; a <= com; ++a)
		{
			if (net[x][a] == 1 && !infected[a])
			{
				infected[a] = 1;
				++ct;
				q.push(make_pair(x, a));
			}
		}
	}
}

int	main(void)
{
	cin >> com >> line;
	for (int a = 0; a < line; ++a)
	{
		cin >> i >> j;
		net[i][j] = 1;
		net[j][i] = 1;
		if (i == 1)
		{
			infected[j] = 1;
			q.push(make_pair(i, j));
			++ct;
		}
	}
	infected[1] = 1;
	bfs();
	cout << ct;
	return 0;
}
