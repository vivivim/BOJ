#include <iostream>
using namespace std;

int	n;
int	num[10];
int	dst[10];

int	main(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (num[i] == 0 && dst[j] == 0)
			{
				dst[j] = i+1;
				break ;
			}
			else if (dst[j] == 0)
				--num[i];
		}
	}

	for (int i = 0; i < n; ++i)
		cout << dst[i] << ' ';
	return 0;
}
