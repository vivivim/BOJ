#include <stdio.h>

int    recur(int n)
{
	if (n < 2)
		return (1);
    return (recur(n-1) * n);
}
int    main(void)
{
    int    n;
    scanf("%d", &n);
    
    printf("%d", recur(n));
}
