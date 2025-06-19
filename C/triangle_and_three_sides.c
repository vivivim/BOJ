#include <stdio.h>

int	is_triangle(int a, int b, int c)
{
	if (a >= b && a >= c)
	{
		if (a >= b+c)
			return (0);
	}
	else if (b >= a && b >= c)
	{
		if (b >= a+c)
			return (0);
	}
	else if (c >= a && c >= b)
	{
		if (c >= a+b)
			return (0);
	}
	return (1);
}

int	main(void)
{
	int	a, b, c;
	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (!a && !b && !c)
			break;
		if (!is_triangle(a, b, c))
			printf("Invalid\n");
		else
		{
			if (a == b && b == c)
				printf("Equilateral\n");
			else if (a == b || b == c || c == a)
				printf("Isosceles\n");
			else
				printf("Scalene\n");
		}
	}
	return (0);
}
