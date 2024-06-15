#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int	main(void)
{
	int	tmp;
	std::vector<int>	num;
	std::vector<int>	dst;
	while (std::cin >> tmp)
	{
		num.push_back(tmp);
	}
	if (num.size() == 1)
	{
		std::cout << num[0] << std::endl;
		return 0;
	}
	
	std::vector<int>::iterator	minIt = min_element(num.begin(), num.end());
	std::vector<int>::iterator	idx = minIt;
	std::vector<int>::iterator	usedMax = num.begin();
	for (int i = 1; ;++i)
	{
		dst.push_back(*idx);
		if (idx == num.begin() + 1)
			break ;
		if (usedMax < idx)
			usedMax = idx;
		if (minIt == num.end() - 1)
			--idx;
		else
			idx += i * pow(-1, i-1);
	}
	std::vector<int>::iterator	last = num.end() - 1;
	if (usedMax == num.begin())
		dst.push_back(*usedMax);
	else if (usedMax == num.begin() + 1 || usedMax == num.end() - 1)
		dst.push_back(num[0]);
	else if (usedMax != num.begin())
	{
		for (; last > usedMax; --last)
			dst.push_back(*last);
		dst.push_back(num[0]);
	}

	std::vector<int>::iterator	it = dst.begin();
	for (; it != dst.end(); ++it)
		std::cout << *it << '\n';
	return 0;
}
