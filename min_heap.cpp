#include <iostream>
#include <queue>
using namespace std;

int	main(void)
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int	n, tmp;
	priority_queue< int, vector<int>, greater<int> >	pq;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (!tmp)
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(tmp);
	}
	return (0);
}
