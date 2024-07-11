#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int	t, n, k, d[1001], x, y, w;
int	degree[1001], dp[1001];
vector<vector<int> >	v;
queue<int>	q;

void	input()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> d[i];
	v.assign(n+1, vector<int>(0, 0));
	for (int i = 0; i < k; ++i)
	{
		cin >> x >> y;
		++degree[y];
		v[x].push_back(y);
	}
	cin >> w;
}

void	topology(int cur)
{
	int	next;
	for (size_t i = 0; i < v[cur].size(); ++i)
	{
		next = v[cur][i];
		dp[next] = max(dp[next], dp[cur]+d[next]);
		if (--degree[next] == 0)
			q.push(next);
	}
}

int	main(void)
{
	cin >> t;
	while (t--)
	{
		input();
		for (int i = 1; i <= n; ++i)
		{
			if (!degree[i])
			{
				q.push(i);
				dp[i] = d[i];
			}
		}
		int	cur;
		for (int i = 1; i <= n; ++i)
		{
			cur = q.front();
			q.pop();
			topology(cur);
		}
		cout << dp[w] << '\n';
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}
