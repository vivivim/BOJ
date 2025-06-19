#include <stdio.h>
#include <stdlib.h>

int	ct;

int	*merge(int a[], int p, int q, int r, int n, int k)
{
	int i = p, j = q+1, t = 0;
	int	tmp[n];

	while (i <= q && j <= r)
	{
		if (a[i] <= a[j])
			tmp[t++] = a[i++];
		else
			tmp[t++] = a[j++];
		if (++ct == k)
			printf("%d\n", tmp[t-1]);
	}
	while (i <= q)
	{
		tmp[t++] = a[i++];
		if (++ct == k)
			printf("%d\n", tmp[t-1]);
	}
	while (j <= r)
	{
		tmp[t++] = a[j++];
		if (++ct == k)
			printf("%d\n", tmp[t-1]);
	}
	i = p;
	t = 0;
	while (i <= r)
		a[i++] = tmp[t++];
	return (a);
}

int	*merge_sort(int *a, int p, int r, int n, int k)
{
	int	q;

	if (p < r)
	{
		q = (p + r) / 2;
		merge_sort(a, p, q, n, k);
		merge_sort(a, q+1, r, n, k);
		a = merge(a, p, q, r, n, k);
	}
	return (a);
}

int	main(void)
{
	int	n, k;
	scanf("%d %d", &n, &k);

	int	*a;
	a = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	a = merge_sort(a, 0, n-1, n, k);
	if (ct < k)
		printf("-1");
	return (0);
}
