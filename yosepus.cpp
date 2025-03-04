#include <iostream>
#include <queue>
using namespace std;

int	main(void)
{
	int	n, k;
	cin >> n >> k;

	queue<int>	q;
	queue<int>	dst;
	int			num = 1;

	for (int i = 1; i <= n; i++)
		q.push(i);
	while (!q.empty())
	{
		while (num < k)
		{
			q.push(q.front());
			q.pop();
			num++;
		}
		dst.push(q.front());
		q.pop();
		num = 1;
	}
	cout << "<";
	while (!dst.empty())
	{
		cout << dst.front();
		dst.pop();
		if (!dst.empty())
			cout << ", ";
		else
			cout << ">";
	}
	return (0);
}
