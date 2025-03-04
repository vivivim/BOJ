#include <stdio.h>
#include <string.h>

int	 main(void)
{
	char	s[100];
	scanf("%s", s);

	int	i = 0, ct = 0;
	while (s[i])
	{
		if (!strncmp(&s[i], "c=", 2) || !strncmp(&s[i], "c-", 2) || !strncmp(&s[i], "d-", 2) || !strncmp(&s[i], "lj", 2) || !strncmp(&s[i], "nj", 2) || !strncmp(&s[i], "s=", 2) || !strncmp(&s[i], "z=", 2))
		{
			ct++;
			i += 2;
		}
		else if (!strncmp(&s[i], "dz=", 3))
		{
			ct++;
			i += 3;
		}
		else
		{
			ct++;
			i++;
		}
	}
	printf("%d", ct);
	return (0);
}
