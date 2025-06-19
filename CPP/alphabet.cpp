#include <iostream>

using namespace	std;

int	r, c, dst;
char	board[20][20];
char	alpha[26];
int	dx[4] = {-1, 1, 0, 0};
int	dy[4] = {0, 0, -1, 1};

void	dfs(int i, int j, int ct)
{
	int	x, y;

	if (dst < ct)
		dst = ct;
	for (int k = 0; k < 4; k++)
	{
		x = i + dx[k];
		y = j + dy[k];
		if (x >= 0 && x < r && y >= 0 && y < c)
		{
			if (!alpha[board[x][y] - 'A'])
			{
				alpha[board[x][y] - 'A'] = 1;
				dfs(x, y, ct+1);
				alpha[board[x][y] - 'A'] = 0;
			}
		}
	}
}

int	main(void)
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		scanf("%s", board[i]);
	}
	int i = 0, j = 0, ct = 1;
	alpha[board[0][0] - 'A'] = 1;
	dfs(i, j, ct);
	cout << dst;
	return (0);
}
