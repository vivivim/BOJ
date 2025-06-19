#include <iostream>
#include <queue>
using namespace std;

int	main(void)
{
	int	n, tmp;
	cin >> n;

	priority_queue< int, vector<int>, greater<int> >	pq;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		pq.push(tmp);
	}

	int	ct = 0;
	while (pq.size() != 1)
	{
		tmp = pq.top();
		pq.pop();
		tmp += pq.top();
		pq.pop();
		pq.push(tmp);
		ct += tmp;
	}
	cout << ct;
	return (0);
}
