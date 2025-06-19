#include <stdio.h>

int    main(void)
{
    int    min, max;
    scanf("%d %d", &min, &max);
    
    int    j;
    for (int i = min; i <= max; i++)
    {
		j = 2;
        while (j * j <= i)
        {
            if (i % j == 0)
                break;
			j++;
        }
		if (i == 1)
			;
		else if (j * j > i)
			printf("%d\n", i);
    }
    return (0);
}
