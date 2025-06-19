#include <iostream>
using namespace std;

int	m, n;
int	stick[1000000];

int	main(void)
{
	cin >> m >> n;
	int	max = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> stick[i];
		if (stick[i] > max)
			max = stick[i];
	}

	int	left = 1, right = max, mid = 0;
	int	dst = 0, ct = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;
		for (int i = 0; i < n; ++i)
			ct += stick[i] / mid;
		if (ct >= m)
		{
			left = mid + 1;
			dst = mid;
		}
		else
			right = mid - 1;
		ct = 0;
	}

	cout << dst;

	return 0;
}
