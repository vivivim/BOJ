#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <sstream>

std::priority_queue<int, std::vector<int>, std::greater<int> >	minQ;
std::priority_queue<int, std::vector<int>, std::less<int> >	maxQ;
std::map<int, int>	ct;

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int	t, k, num;
	std::cin >> t;
	std::string	str, cmd, numS;
	while (t--)
	{
		std::cin >> k;
		for (int i = 0; i < k; ++i)
		{
			std::cin >> cmd >> num;
			if (cmd == "D")
			{
				if (!ct.empty() && num == 1)
				{
					if (ct[maxQ.top()] == 1)
						ct.erase(maxQ.top());
					else
						--ct[maxQ.top()];
					while (!minQ.empty() && ct.find(minQ.top()) == ct.end())
						minQ.pop();
					while (!maxQ.empty() && ct.find(maxQ.top()) == ct.end())
						maxQ.pop();
				}
				if (!ct.empty() && num == -1)
				{
					if (ct[minQ.top()] == 1)
						ct.erase(minQ.top());
					else
						--ct[minQ.top()];
					while (!maxQ.empty() && ct.find(maxQ.top()) == ct.end())
						maxQ.pop();
					while (!minQ.empty() && ct.find(minQ.top()) == ct.end())
						minQ.pop();
				}
			}
			if (cmd == "I")
			{
				minQ.push(num);
				maxQ.push(num);
				if (ct.find(num) == ct.end())
					ct[num] = 1;
				else
					++ct[num];
			}
		}
		while (!minQ.empty() && ct.find(minQ.top()) == ct.end())
			minQ.pop();
		while (!maxQ.empty() && ct.find(maxQ.top()) == ct.end())
			maxQ.pop();
		if (ct.empty())
			std::cout << "EMPTY\n";
		else
			std::cout << maxQ.top() << ' ' << minQ.top() << '\n';
		while (!maxQ.empty())
			maxQ.pop();
		while (!minQ.empty())
			minQ.pop();
		ct.clear();
	}
	return 0;
}
