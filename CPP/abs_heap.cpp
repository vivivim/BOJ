#include <iostream>
#include <queue>
#include <cmath>
using namespace	std;

struct	cmp
{
	bool	operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int	main(void)
{
	int	n, tmp;
	cin >> n;

	priority_queue< int, vector<int>, cmp>	pq;
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
