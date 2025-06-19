#include <stdio.h>

int	get_gcd(int a, int b)
{
	if (!(a%b))
		return (b);
	else
		return (get_gcd(b, a%b));
}

int	main(void)
{
	int	t, a, b, gcd, lcm;
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d %d", &a, &b);
		gcd = get_gcd(a, b);
		if (gcd == 1)
			lcm = a * b;
		else
			lcm = gcd * (a/gcd) * (b/gcd);
		printf("%d\n", lcm);
	}
	return (0);
}
