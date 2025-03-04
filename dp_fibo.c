#include <stdio.h>

int	rc_count, dp_count;

int	rc_fibo(int n)
{
	if (n == 0 || n == 1)
		return (1);
	else
	{
		rc_count++;
		return (rc_fibo(n-1) + rc_fibo(n-2));
	}
}

int	dp_fibo(int fibo[], int n)
{
	for (int i = 2; i < n; i++)
	{
		fibo[i] = fibo[i-1] + fibo[i-2];
		dp_count++;
	}
	return (fibo[n-1]);
}

int	 main(void)
{
	int	n;
	scanf("%d", &n);
	
	int	fibo[n];
	fibo[0] = 1;
	fibo[1] = 1;
	rc_fibo(n-1);
	dp_fibo(fibo, n);
	printf("%d %d", rc_count+1, dp_count);
	return (0);
}
