#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int	n, m, a, b;
queue<int>	q;
queue<int>	dst;
vector<pair<int, int> >	cmpr;
int	degree[100001];

void	insert(int cur)
{
	vector<pair<int, int> >::iterator	it;
	for (it = cmpr.begin(); it != cmpr.end(); ++it)
	{
		if (it->first == cur && --degree[it->second] == 0)
			q.push(it->second);
	}
}

int	main(void)
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		cmpr.push_back(make_pair(a, b));
		++degree[b];
	}
	for (int i = 1; i <= n; ++i)
	{
		if (degree[i] == 0)
			q.push(i);
	}
	for (int i = 1; i <= n; ++i)
	{
		int	cur = q.front();
		q.pop();
		dst.push(cur);
		insert(cur); 
	}
	while (!dst.empty())
	{
		cout << dst.front() << ' ';
		dst.pop();
	}
	return 0;
}
