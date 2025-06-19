#include <iostream>
#include <stack>

using namespace	std;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	n, cmd, x;
	cin >> n;
	stack<int>	num;
	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == 1)
		{
			cin >> x;
			num.push(x);
		}
		if (cmd == 2)
		{
			if (num.empty())
				cout << "-1\n";
			else
			{
				cout << num.top() << '\n';
				num.pop();
			}
		}
		if (cmd == 3)
			cout << num.size() << '\n';
		if (cmd == 4)
		{
			if (num.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		if (cmd == 5)
		{
			if (!num.empty())
				cout << num.top() << '\n';
			else
				cout << -1 << '\n';
		}
	}
}
