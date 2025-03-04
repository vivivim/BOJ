#include <stdio.h>

long long	get_gcd(long a, long b)
{
	if (!(a%b))
		return (b);
	else
		return (get_gcd(b, a%b));
}

int	main(void)
{
	long long	a, b, gcd, lcm;
    
	scanf("%lld %lld", &a, &b);
	gcd = get_gcd(a, b);
	if (gcd == 1)
		lcm = a * b;
	else
		lcm = gcd * (a/gcd) * (b/gcd);
	printf("%lld\n", lcm);
	return (0);
}
