#include <stdio.h>

int	ft_check(int idx, int board[])
{
	int	i = 0;

	while (i < idx)
	{
		if (board[i] == board[idx]
				|| board[i] + (idx - i) == board[idx]
				|| board[i] - (idx - i) == board[idx])
			return (0);
		i++;
	}
	return (1);
}
 
void	dfs(int idx, int dth, int board[], int n, int *ct)
{
	while (dth < n)
	{
		board[idx] = dth;
		if (ft_check(idx, board))
		{
			if (idx == n-1)
				(*ct)++;
			else
				dfs(idx+1, 0, board, n, ct);
		}
		dth++;
	}
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	board[n], ct;
	dfs(0, 0, board, n, &ct);
	printf("%d", ct);
	return (0);
}
