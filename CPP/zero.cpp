#include <iostream>
#include <stack>

using namespace	std;

int	main(void)
{
	int	n, tmp;
	cin >> n;
	stack<int>	num;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (!tmp)
			num.pop();
		else
			num.push(tmp);
	}
	tmp = 0;
	while (!num.empty())
	{
		tmp += num.top();
		num.pop();
	}
	cout << tmp;
	return (0);
}
