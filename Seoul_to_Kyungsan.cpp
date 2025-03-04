#include <iostream>
#include <algorithm>

using namespace std;

int	dp[101][100001], N, K, tt[2][101], geld[2][101];

int	fun(int n, int k)
{
	if (k > K)
		return (-2147483648);
	if (n == N)
		return (0);
	if (!dp[n][k])
	{
		int	one = fun(n+1, k+tt[0][n])+geld[0][n];
		int	two = fun(n+1, k+tt[1][n])+geld[1][n];
		dp[n][k] = max(one, two);
	}
	return (dp[n][k]);

}

int	main(void)
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> tt[0][i] >> geld[0][i] >> tt[1][i] >> geld[1][i];

	cout << fun(0, 0) << endl;
	return (0);
}
