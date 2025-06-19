#include <iostream>
using namespace std;

int	main(void)
{
	int	num;
	cin >> num;

	int	dp[1000001] = {0, };

	for (int i = 2; i <= num; i++)
	{
		dp[i] = dp[i-1] + 1;
		if (!(i%3))
			dp[i] = dp[i] < dp[i/3]+1 ? dp[i] : dp[i/3]+1;
		if (!(i%2))
			dp[i] = dp[i] < dp[i/2]+1 ? dp[i] : dp[i/2]+1;
	}
	cout << dp[num] << '\n';
	int	i = num;
	while (i > 0)
	{
		cout << i << ' ';
		if (i%3 == 0 && dp[i] == dp[i/3]+1)
			i /= 3;
		else if (i%2 == 0 && dp[i] == dp[i/2]+1)
			i /=2;
		else
			--i;
	}

	return (0);
}
