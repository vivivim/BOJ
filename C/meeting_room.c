#include <stdio.h>
#include <stdlib.h>

int	*merge(int a[], int p, int q, int r, int n)
{
	int i = p, j = q+1, t = 0;
	int	tmp[n];

	while (i <= q && j <= r)
	{
		if (a[i] <= a[j])
			tmp[t++] = a[i++];
		else
			tmp[t++] = a[j++];
	}
	while (i <= q)
	{
		tmp[t++] = a[i++];
	}
	while (j <= r)
	{
		tmp[t++] = a[j++];
	}
	i = p;
	t = 0;
	while (i <= r)
		a[i++] = tmp[t++];
	return (a);
}

int	*merge_sort(int *a, int p, int r, int n)
{
	int	q;

	if (p < r)
	{
		q = (p + r) / 2;
		merge_sort(a, p, q, n);
		merge_sort(a, q+1, r, n);
		a = merge(a, p, q, r, n);
	}
	return (a);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	sch[n][2];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &sch[i][0], &sch[i][1]);

	int	new_sch[n][2], *end_time;
	end_time = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		end_time[i] = sch[i][1];
	end_time = merge_sort(end_time, 0, n-1, n);

	for (int i = 0; i < n; i++)
		new_sch[i][1] = end_time[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (sch[j][1] != -1 && sch[j][1] == end_time[i])
			{
				printf("%d %d %d\n", end_time[i], sch[j][0], sch[j][1]);
				new_sch[i][0] = sch[j][0];
			//	sch[j][1] = -1;
				end_time[i] = -1;
			}
			if (end_time[i] == -1)
				break;
		}		
	}

	int	be4 = new_sch[0][1], ct = 1;
	for (int i = 1; i < n; i++)
	{
		if (new_sch[i][0] >= be4)
		{
			be4 = new_sch[i][1];
			ct++;
		}
	}
	printf("%d", ct);
	return (0);
}
