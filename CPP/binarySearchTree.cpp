#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int	arr[10001];

void	letsGoTree(int start, int end)
{
	if (start >= end)
		return ;
	int	i;
	for (i = start+1; i < end; ++i)
	{
		if (arr[start] < arr[i])
			break ;
	}
	letsGoTree(start+1, i);
	letsGoTree(i, end);
	std::cout << arr[start] << '\n';
}

int	main(void)
{
	int	i;
	for (i = 0; std::cin >> arr[i]; ++i)	;
	letsGoTree(0, i);
	return 0;
}
