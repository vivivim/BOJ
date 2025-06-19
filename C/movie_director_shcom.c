#include <stdio.h>
#include <stdlib.h>

int	is_endnum(char *str)
{
	int	ct = 0;

	while (*str)
	{
		if (*str == '6')
		{
			ct++;
			if (ct == 3)
				return (1);
		}
		else
			ct = 0;
		str++;
	}
	return (0);
}
static int	ct_digit(int n)
{
	int	ct;

	ct = 0;
	if (n == 0)
		ct = 1;
	while (n != 0)
	{
		ct++;
		n /= 10;
	}
	return (ct);
}

static char	*ft_putnbr(int n, char *dst, int *i)
{
	long	l;

	l = n;
	if (n < 0)
		l *= -1;
	if (l >= 10)
	{
		ft_putnbr(l / 10, dst, i);
		ft_putnbr(l % 10, dst, i);
	}
	if (l >= 0 && l <= 9)
		dst[(*i)++] = l + 48;
	dst[*i] = '\0';
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		digit;
	int		i;

	i = 0;
	digit = ct_digit(n);
	if (n < 0)
		dst = (char *)malloc(sizeof(char) * (digit + 2));
	else
		dst = (char *)malloc(sizeof(char) * (digit + 1));
	if (!dst)
		return (0);
	if (n < 0)
		dst[i++] = '-';
	dst = ft_putnbr(n, dst, &i);
	return (dst);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	i = 666;
	char	*strnum;
	strnum = malloc(20);
	while (n)
	{
		strnum = ft_itoa(i++);
		if (is_endnum(strnum))
			n--;
	}
	int	ans = atoi(strnum);
	printf("%d", ans);
	return (0);
}
