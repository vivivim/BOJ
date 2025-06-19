#include <stdio.h>
#include <stdlib.h>

void	pork_star(int n, char **board, int i, int j)
{
	if ((i/n)%3 == 1 && (j/n)%3 == 1)
		board[i][j] = ' ';
	else
	{
		if (!(n/3))
			board[i][j] = '*';
		else
			pork_star(n/3, board, i, j);
	}
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	char	*board[n];
	for (int i = 0; i < n; i++)
		board[i] = (char *)malloc(n+1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			pork_star(n, board, i, j);
		printf("%s\n", board[i]);
	}
	for (int i = 0; i < n; i++)
		free(board[i]);
	return (0);
}
