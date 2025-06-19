#include <iostream>
#include <deque>
using namespace std;

int	main(void)
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int	n;
	cin >> n;

	int	a[n], b[n], m;
	deque<int>	d;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		if (!a[i])
			d.push_back(b[i]);
	}
	cin >> m;
	int	c[m];
	for (int i = 0; i < m; i++)
	{
		cin >> c[i];
		d.push_front(c[i]);
		cout << d.back() << ' ';
		d.pop_back();
	}
	return (0);
}
