#include <iostream>
#include <unistd.h>
using namespace std;

int	main(void)
{
	int	n, m;
	char *str = (char *)malloc(1000001);

	cin >> n >> m >> str;
	int i = 0, ct = 0, tmp;
	while (str[i])
	{
		if (str[i] == 'I' && str[i+1] == 'O')
		{
			tmp = i+1;
			while(tmp < m && str[tmp] == 'O' && str[tmp+1] == 'I')
				tmp += 2;
			--tmp;
			if (!i)
				i++;
			if ((tmp - i*n) > 0)
			{
				ct += (tmp - i*n) / 2;
				i = tmp + 1;
			}
		}
		else
			i++;
	}
	cout << ct;
	return (0);
}
