#include <iostream>

using namespace std;

int	n, num[2001], m, s, e;
bool	dp[2001][2001] = {false, };

int	main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> num[i];
	cin >> m;
	for (int i = 1; i <= n; ++i)
	{
		dp[i][i] = true;
		if (num[i] == num[i-1])
		{
			dp[i-1][i] = true;
			dp[i][i-1] = true;
		}
	}
	for (int i = n; i >= 1; --i)
	{
		for (int j = i+1; j <= n; ++j)
		{
			if (num[i] == num[j] && dp[i+1][j-1])
				dp[i][j] = true;
		}
	}
	while (m--)
	{
		cin >> s >> e;

		if (s == e)
			cout << '1';
		else if (num[s] == num[e] && dp[s+1][e-1])
			cout << '1';
		else
			cout << '0';
		cout << '\n';
	}
	return 0;
}
