#include <stdio.h>

int	main(void)
{
	int	a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a+b+c != 180)
		printf("Error");
	else
	{
		if (a == b && b == c)
			printf("Equilateral");
		else if (a == b || b == c || a == c)
			printf("Isosceles");
		else
			printf("Scalene");
	}
	return (0);
}
