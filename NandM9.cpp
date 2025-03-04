#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>	nums;
std::vector<int>	seq;
bool				used[9];
int	b4;

void	letsGoNandM(int n, int m)
{
	if (seq.size() == m)
	{
		std::vector<int>::iterator	it = seq.begin();
		for (; it != seq.end(); ++it)
			std::cout << *it << ' ';
		std::cout << std::endl;
		b4 = seq.back();
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (b4 == nums[i])
				;
			else if (!used[i])
			{
				seq.push_back(nums[i]);
				used[i] = true;
				b4 = 0;
				letsGoNandM(n, m);
				b4 = seq.back();
				seq.pop_back();
				used[i] = false;
			}
		}
	}
}

int	main(void)
{
	int n, m, tmp;
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		std::cin >>tmp;
		nums.push_back(tmp);
	}
	sort(nums.begin(), nums.end());
	letsGoNandM(n, m);
	return 0;
}
