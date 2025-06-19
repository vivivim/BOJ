#include <stdio.h>

int	max(int	hap[], int n)
{
	int	max = hap[0];

	for (int i = 0; i < n; i++)
	{
		if (max < hap[i])
			max = hap[i];
	}
	return (max);
}

int	main(void)
{
	int	n, k;
	scanf("%d %d", &n, &k);

	int	seq[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &seq[i]);

	int	hap[n-k+1];
	for (int i = 0; i < n-k+1; i++)
	{
		hap[i] = 0;
		if (i == 0)
		{
			for (int j = 0; j < k; j++)
				hap[i] += seq[j];
		}
		else
			hap[i] = hap[i-1] - seq[i-1] + seq[k+i-1];
	}
	printf("%d", max(hap, n-k+1));
}
