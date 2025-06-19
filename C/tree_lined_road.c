#include <stdio.h>
#include <stdlib.h>

int	max(int arr[], int n)
{
	int	tmp = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (tmp < arr[i])
			tmp = arr[i];
	}
	return (tmp);
}

int	min(int arr[], int n)
{
	int tmp = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (tmp > arr[i])
			tmp = arr[i];
	}
	return (tmp);
}

int	gcd(int a, int b)
{
	if (!(a % b))
		return (b);
	else
		return (gcd(b, a%b));
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	*tree, sub[n-1], min;
	tree = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &tree[i]);
	for (int i = 0; i < n-1; i++)
		sub[i] = tree[i+1] - tree[i];
	int	first = tree[0], last = tree[n-1];
	min = sub[0];
	for (int i = 1; i < n-1; i++)
		min = gcd(min, sub[i]);
	if (tree[n-1] % 2)
		printf("%d", (((tree[n-1]-tree[0])/min) - n + 1));
	else
		printf("%d", (((tree[n-1]-tree[0])/min) - n + 1));
	free(tree);
	return (0);
}
