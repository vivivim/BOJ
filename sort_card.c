#include <stdio.h>

int	smallest(int *deck, int n)
{
	int dst = 2147483647, temp = 0, idx = 2147483647;

	for (int i = 0; i < n; i++)
	{
		temp = deck[i];
		if (temp < dst)
		{
			dst = temp;
			idx = i;
		}
	}
	return (idx);
}

int	sum(int grdy[], int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += grdy[i];
	return (sum);
}

int	main(void)
{
	int	 n;
	scanf("%d", &n);

	int	deck[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &deck[i]);

	if (n == 1)
	{
		printf("%d", deck[0]);
		return (0);
	}
	int	grdy[n-1];
	for (int i = 0; i < n-2; i++)
		grdy[i] = 0;
	int idx, love;
	for (int i = 0; i < n-1; i++)
	{
		if (i == 0)
		{
			idx = smallest(deck, n);
			grdy[i] += deck[idx];
			deck[idx] = 2147483647;
			idx = smallest(deck, n);
			grdy[i] += deck[idx];
			deck[idx] = 2147483647;
		}
		else
		{
			idx = smallest(deck, n);
			if (idx == 2147483647)
			{
				grdy[i] = grdy[i-1] + grdy[i-2];
			}
			else
			{
				love = deck[idx];
				deck[idx] = 2147483647;
				int	jdx;
				jdx = smallest(deck, n);
				if (jdx < 2147483647)
				{
					if (deck[jdx] < grdy[i-1])
					{
						grdy[i] = deck[jdx] + love;
						deck[jdx] = 2147483647;
					}
					else
					{
						grdy[i] = grdy[i-1] + love;
					}
				}
				else
					grdy[i] = grdy[i-1] + love;
			}
		}
	}
	printf("%d", sum(grdy, n-1));
	return (0);
}
