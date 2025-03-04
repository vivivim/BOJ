#include <iostream>

using namespace	std;

int	main(void)
{
	string	jinho;
	int	n, ct = 0;
	cin >> jinho >> n;

	string	friends[n];
	for (int i = 0; i < n; i++)
	{
		cin >> friends[i];
		if (jinho == friends[i])
			ct++;
	}
	cout << ct;
	return (0);
}
