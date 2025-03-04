#include <iostream>
#include <math.h>

using namespace	std;

int	main(void)
{
	int	k;
	cin >> k;
	
	int	size = (int)(pow(2., (double)k) - 1), tmp, p;
	int	num[size];
	for (int i = 0; i < size; i++)
		cin >> num[i];
	for (int i = 0; i < k; i++)
	{
		tmp = size/2;
		p = (int)pow(2., i);
		for (int j = 0; j < p; j++)
		{
			cout << num[tmp] << " ";
			tmp /= 2;
			tmp += (int)(pow(2., (double)k-1-j));
		}
		size /= 2;
		cout << "\n";
	}
	return (0);
}
