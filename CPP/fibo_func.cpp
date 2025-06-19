#include <iostream>
using namespace std;

int	main(void)
{
	int	t;
	cin >> t;
	int	n, zero[41], one[41];
	zero[0] = 1;
	zero[1] = 0;
	one[0] = 0;
	one[1] = 1;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 2; j <= n; j++)
		{
			zero[j] = zero[j-1] + zero[j-2];
			one[j] = one[j-1] + one[j-2];
		}
		cout << zero[n] << ' ' << one[n] << '\n';
	}
	return (0);
}
