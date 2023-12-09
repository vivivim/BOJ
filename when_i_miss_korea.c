#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	is_start(char *file, char *ptrn)
{
	while (*ptrn != '*' && *file)
	{
		if (*ptrn != *file)
			return (0);
		ptrn++;
		file++;
	}
	if (*file)
		return (1);
	else
		return (0);
}

int	is_end(char *file, char *ptrn)
{
	while (*ptrn)
		ptrn++;
	while (*file)
		file++;
	while (*(--ptrn) != '*' && *(--file))
	{
		if (*ptrn != *file)
			return (0);
	}
	if (*file)
		return (1);
	else
		return (0);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	char	*ptrn = malloc(101);
	scanf("%s", ptrn);
	char	*files[n];
	for (int i = 0; i < n; i++)
	{
		files[i] = malloc(101);
		scanf("%s", files[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (is_start(files[i], ptrn))
		{
			if (is_end(files[i], ptrn))
			{
				if (strlen(ptrn) - 1 > strlen(files[i]))
					printf("NE\n");
				else
					printf("DA\n");
			}
			else
				printf("NE\n");
		}
		else
			printf("NE\n");
	}
	return (0);
}
