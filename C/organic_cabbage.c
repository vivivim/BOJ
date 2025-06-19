#include <stdio.h>

int	field[50][50];
int warm[1000000];

void	finding(int m, int n, int i, int j)
{
	field[i][j] = 0;
	if (i+1 < m && field[i+1][j] == 1)
		finding(m, n, i+1, j);
	if (i-1 >= 0 && field[i-1][j] == 1)
		finding(m, n, i-1, j);
	if (j+1 < n && field[i][j+1] == 1)
		finding(m, n, i, j+1);
	if (j-1 >= 0 && field[i][j-1] == 1)
		finding(m, n, i, j-1);
}

int	main(void)
{
	int	ncase;
	scanf("%d", &ncase);
	
	for (int c = 0; c < ncase ; c++)
	{
    	int	m, n, k;
    	scanf("%d %d %d", &m, &n, &k);
	
	    int	h, r;
	    for (int i = 0; i < k; i++)
	   {
	    	scanf("%d %d", &h, &r);
	    	field[h][r] = 1;
  	    }
	
	    int	warma = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (field[i][j])
			 	{
					 warma++;
					 finding(m, n, i, j);
			 	}
  	 		}
		}
        warm[c] = warma;
	}
    for (int i = 0; i < ncase ; i++)
        printf("%d\n", warm[i]);
	return (0);
}
