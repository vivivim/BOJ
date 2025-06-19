#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int	main(void)
{
	int	n;
	cin >> n;

	int	seq[n];
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	int	i = 0, j = 1;
	stack<int>	s;
	queue<char>	q;
	while (i < n)
	{
		if (s.empty() || seq[i] > s.top())
		{
			s.push(j);
			q.push('+');
			j++;
		}
		else if (seq[i] == s.top())
		{
			s.pop();
			q.push('-');
			i++;
		}
		else if (seq[i] < s.top())
		{
			cout << "NO\n";
			return (0);
		}
	}
	while (!q.empty())
	{
		cout << q.front() << '\n';
		q.pop();
	}
	return (0);
}
