#include <iostream>
#include <queue>
using namespace std;

int	n, m;
char board[11][11];
bool visit[11][11][11][11];
int	dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct bead
{
	int Rx, Ry;
	int Bx, By;
	int Ct;
};
queue<bead>	q;

void	move(int& x, int& y, int& d, int i)
{
	while (board[y+dy[i]][x+dx[i]] != '#' && board[y][x] != 'O')
	{
		x += dx[i];
		y += dy[i];
		++d;
	}
}

void	bfs()
{
	while(!q.empty())
	{
		int rx = q.front().Rx;
		int ry = q.front().Ry;
		int bx = q.front().Bx;
		int by = q.front().By;
		int ct = q.front().Ct;
		q.pop();
		if (ct >= 10) break ;

		for (int i = 0; i < 4; ++i)
		{
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int dr = 0, db = 0, nct = ct+1;
			move(nrx, nry, dr, i); move(nbx, nby, db, i);
			if (board[nby][nbx] == 'O') continue;
			if (board[nry][nrx] == 'O')
			{
				cout << 1;
				return ;	
			}
			if (nrx == nbx && nry == nby)
			{
				if (dr > db)
				{
					nrx -= dx[i];
					nry -= dy[i];
				}
				else
				{
					nbx -= dx[i];
					nby -= dy[i];
				}
			}
			if (visit[nry][nrx][nby][nbx]) continue;
			visit[nry][nrx][nby][nbx] = true;
			bead	next;
			next.Rx = nrx; next.Ry = nry;
			next.Bx = nbx; next.By = nby;
			next.Ct = nct;
			q.push(next);
		}
	}
	cout << 0;
}

int	main(void)
{
	cin >> n >> m;
	bead	first;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 'R')
			{
				first.Ry = i;
				first.Rx = j;
			}
			if (board[i][j] == 'B')
			{
				first.By = i;
				first.Bx = j;
			}
		}

	}
	first.Ct = 0;
	q.push(first);
	visit[first.Ry][first.Rx][first.By][first.Bx] = true;
	bfs();
	return 0;
}
