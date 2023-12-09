#include <stdio.h>

int	ft_check(int board[9][9], int i, int j)
{
	for (int a = 0; a < 9; a++)
	{
		if (a == j)
			;
		else if (board[i][a] == board[i][j])
			return (0);
	}
	for (int a = 0; a < 9; a++)
	{
		if (a == i)
			;
		else if (board[a][j] == board[i][j])
			return (0);
	}
	int	a, b;
	a = (i/3)*3;
	while (a < ((i/3)*3)+3)
	{
		b = (j/3)*3;
		while (b < ((j/3)*3)+3)
		{
			if (a == i && b == j)
				;
			else if (board[i][j] == board[a][b])
				return (0);
		b++;
		}
		a++;
	}
	return (1);
}

int	back_in_the_time(int board[9][9], int ix, int iy)
{
	int	i = 0, j = 0, ans = 1, brk;
	while (ans <= 9)
	{
		board[ix][iy] = ans;
		brk = 0;
		if (ft_check(board, ix, iy))
		{
			for (i = 0; i < 9; i++)
			{
				for (j = 0; j < 9; j++)
				{
					if (!board[i][j])
						brk = back_in_the_time(board, i, j);
					if (brk == -1)
						break ;
				}
				if (brk == -1)
					break ;
			}
		}
		if (i == 9 && j == 9)
			break;
		ans++;
	}
	if (ans == 10)
	{
		board[ix][iy] = 0;
		return (-1);
	}
	else
		return (1);
}

int	main(void)
{
	int	board[9][9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			scanf("%d", &board[i][j]);
	}
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (!board[i][j])
			{
				back_in_the_time(board, i, j);
				break;
			}
			
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j == 8)
				printf("%d\n", board[i][j]);
			else
				printf("%d ", board[i][j]);
		}
	}
	return (0);
}
