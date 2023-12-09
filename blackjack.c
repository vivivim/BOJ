#include <stdio.h>

int    main()
{
    int    ct, num;
    scanf("%d %d", &ct, &num);
    
    int    card[ct];
    int    i = 0;
    while (i < ct)
        scanf("%d", &card[i++]);
    
    int    comb = (ct * (ct - 1) * (ct - 2))/6;
    int    dst[comb];
    int    j, k, l, max;
    i = 0;
	j = 0;
	max = 0;
	while (j + 2 < ct)
    {
        k = j + 1;
        while (k + 1 < ct)
        {
            l = k + 1;
            while (l < ct)
            {
                dst[i] = card[j] + card[k] + card[l];
                if (dst[i] == num)
				{
					printf("%d", num);
					return 0;
				}
				else if (dst[i] < num && dst[i] > max)
					max = dst[i];
				l++;
				i++;
            }
            k++;
        }
        j++;
    }
	printf("%d", max);
	return (0);
}
