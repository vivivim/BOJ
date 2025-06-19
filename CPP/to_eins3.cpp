#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	int	num;
	cin >> num;

	vector<int>	v(100000001);

	for (int i = 2; i <= num; i++)
	{
		v[i] = v[i-1] + 1;
		if (!(i%3))
			v[i] = v[i] < v[i/3]+1 ? v[i] : v[i/3]+1;
		if (!(i%2))
			v[i] = v[i] < v[i/2]+1 ? v[i] : v[i/2]+1;
	}
	cout << v[num] << '\n';
	cout << v[0] << ' ' << v[100000000];
	return (0);
}

