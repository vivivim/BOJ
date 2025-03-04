#include <stdio.h>

int	bfs(int maze[][101], int n, int m)
{
	int	dx[4] = {-1, 1, 0, 0};
	int	dy[4] = {0, 0, -1, 1};
	int	front = 0, rear = 0;
	int	q[10000][2] = {0, };
	int	x, y, nx, ny;

	q[front][0] = 0;
	q[front][1] = 0;
	rear++;

	while (front < rear)
	{
		x = q[front][0];
		y = q[front][1];
		front++;

		for(int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (maze[nx][ny] != 1)
				continue;
			maze[nx][ny] = maze[x][y] + 1;
			q[rear][0] = nx;
			q[rear][1] = ny;
			rear++;
		}
	}
	return (maze[n-1][m-1]);
}

int	main(void)
{
	int	n, m;
	scanf("%d %d", &n, &m);

	int	maze[101][101] = { 0,};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%1d", &maze[i][j]);
	}

	printf("%d", bfs(maze, n, m));
	return (0);
}
