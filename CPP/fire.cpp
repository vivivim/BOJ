#include <iostream>
#include <queue>
using namespace std;

int	dx[4] = { 1, -1, 0, 0 };
int	dy[4] = { 0, 0, 1, -1 };
int	r, c;
char miro[1001][1001];
int	dst;
queue<pair<int, int> >	J, f;

void	fire()
{
	int	size = f.size();
	while (size--)
	{
		int x = f.front().second;
		int y = f.front().first;
		f.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			if (nx < 1 || nx > c || ny < 1 || ny > r) continue;
			if (miro[ny][nx] == '#') continue;
			miro[ny][nx] = '#';
			f.push(make_pair(ny, nx));
		}
	}
}

bool	escape()
{
	int size = J.size();
	if (!size)
	{
		cout << "IMPOSSIBLE";
		exit(0);
	}
	while (size--)
	{
		int x = J.front().second;
		int y = J.front().first;
		J.pop();
		if (x == 1 || x == c || y == 1 || y == r) return true;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			if (nx < 1 || nx > c || ny < 1 || ny > r) continue;
			if (miro[ny][nx] == '#') continue;
			miro[ny][nx] = '#';
			J.push(make_pair(ny, nx));
		}
	}
	return false;
}

int	main(void)
{
	cin >> r >> c;
	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= c; ++j)
		{
			cin >> miro[i][j];
			if (miro[i][j] == 'J')
			{
				J.push(make_pair(i, j));
				miro[i][j] = '#';
			}
			else if (miro[i][j] == 'F')
			{
				f.push(make_pair(i, j));
				miro[i][j] = '#';
			}
		}
	}
	do {
		fire();
		++dst;
	} while (!escape());
	cout << dst;
	return 0;
}
