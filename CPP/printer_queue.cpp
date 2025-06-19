#include <iostream>
#include <queue>
using namespace std;

int	is_max(queue<int> q)
{
	int	s = q.size() - 1;
	int	f = q.front();
	for (int i = 0; i < s; i++)
	{
		q.pop();
		if (f < q.front())
			return (0);
	}
	return (1);
}

int	main(void)
{
	int	ct = 0;
	queue<int>	q;
	
	int	t, n, m, tmp;
	cin >> t;

	for (int j = 0; j < t; j++)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			q.push(tmp);
		}

		while (!q.empty())
		{
			if (is_max(q))
			{
				q.pop();
				ct++;
				if (m)
					m--;
				else
					break ;
			}
			else
			{
				q.push(q.front());
				q.pop();
				if (m)
					m--;
				else
					m = q.size()-1;
			}
		}
		cout << ct << '\n';
		ct = 0;
		while (!q.empty())
			q.pop();
	}
	return (0);
}
