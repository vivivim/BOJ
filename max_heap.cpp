#include <iostream>
#include <queue>
using  namespace std;

int	main(void)
{
	int	n, tmp;
	cin >> n;

	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (!tmp)
		{
			if (pq.empty())
				cout << 0;
			else
			{
				cout << pq.top();
				pq.pop();
			}
		}
		else
			pq.push(tmp);
	}
	return (0);
}
