#include <iostream>
#include <vector>
#include <algorithm>
using namespace	std;

vector<pair<int, pair<int, int> > >	v;
int	route[10001];
int	n, e, a, b, c, ans;

int	find_route(int d)
{
	if (!route[d])
		return d;
	return route[d] = find_route(route[d]);
}

void	add(int e, int f)
{
	e = find_route(e);
	f = find_route(f);
	if (e == f)
		return ;
	route[f] = e;
}

int	main(void)
{
	cin >> n >> e;
	for (int i = 0; i < e; ++i)
	{
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(v.begin(), v.end());
	vector<pair<int, pair<int, int> > >::iterator	it = v.begin();
	for (; it != v.end(); ++it)
	{
		a = find_route(it->second.first);
		b = find_route(it->second.second);
		if (a != b)
		{
			ans += it->first;
			add (a, b);
		}
	}
	cout << ans;
	return 0;
}
