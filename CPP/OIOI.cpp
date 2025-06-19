#include <iostream>
#include <unistd.h>
using namespace std;

int	main(void)
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int	n, m;
	char *str = (char *)malloc(1000001);

	cin >> n >> m >> str;
	int i = 0, ct = 0, tmp;
	int	oi = 0;
	while (str[i])
	{
		if (str[i] == 'I' && str[i+1] == 'O')
		{
			i++;
			while (i < m && str[i] == 'O' && str[i+1] == 'I')
			{
				i += 2;
				oi++;
			}
			if (oi >= n)
				ct += oi - n + 1;
			oi = 0;
			
		}
		else
			i++;
	}
	cout << ct;
	return (0);
}
