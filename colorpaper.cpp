#include <iostream>
using namespace std;

int	n, blue, white, paper[128][128];

void	is_samee(int x, int y, int size)
{
	int	color = paper[x][y];
	for (int i = x; i < x+size; i++)
	{
		for (int j = y; j < y+size; j++)
		{
			if (!color && paper[i][j] == 1)
				color = 2;
			else if (color && !paper[i][j])
				color = 2;
			if (color == 2)
			{
				is_samee(x, y, size/2);
				is_samee(x, y+size/2, size/2);
				is_samee(x+size/2, y, size/2);
				is_samee(x+size/2, y+size/2, size/2);
				return ;
			}
		}
	}
	if (!color)
		white++;
	else
		blue++;
}

int	main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	}
	
	is_samee(0, 0, n);
	cout << white << endl;
	cout << blue << endl;
	return (0);
}
