#include <iostream>

long long	cal(int a, int b, int c)
{
	if (!b)
		return 0;
	if (b == 1)
		return a % c;
	
	long long	k = cal(a, b/2, c) % c;
	if (b%2 == 0)
		return k * k %c;
	return k * k % c * a % c;
}

int	main(void)
{
	int	a, b, c;
	std::cin >> a >> b >> c;
	std::cout << cal(a, b, c);
	return 0;
}
