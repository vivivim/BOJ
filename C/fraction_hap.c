#include <stdio.h>

int	get_gcd(int a, int b)
{
	if (!(a%b))
		return (b);
	else
		return (get_gcd(b, a%b));
}

int	get_lcm(int a, int b)
{
	int	gcd, lcm;

	gcd = get_gcd(a, b);
	if (gcd == 1)
		lcm = a * b;
	else
		lcm = gcd * (a/gcd) * (b/gcd);
	return (lcm);
}

int	main(void)
{
	int	mutter1, mutter2, tochter1, tochter2;

	scanf("%d %d %d %d", &tochter1, &mutter1, &tochter2, &mutter2);

	int	lcm = get_lcm(mutter1, mutter2);
	int	dst_tochter, gcd;
	
	if (mutter1 * mutter2 == lcm)
		dst_tochter = tochter1 * mutter2 + tochter2 * mutter1;
	else
		dst_tochter = (tochter1 * (lcm/mutter1)) + (tochter2 * (lcm/mutter2));
	gcd = get_gcd(dst_tochter, lcm);
	while (gcd != 1)
	{
		lcm /= gcd;
		dst_tochter /= gcd;
		gcd = get_gcd(dst_tochter, lcm);
	}
	printf("%d %d", dst_tochter, lcm);
	return (0);
}
