#include <iostream>
#include <deque>
using namespace std;

int	main(void)
{
	int	n;
	cin >> n;
	int	num[n];
	deque<int> d;
	deque<int> dst;
	int	tmp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		d.push_back(i+1);
	}
	while (!d.empty())
	{
		tmp = d.front();
		dst.push_back(tmp);
		d.pop_front();
		while (num[tmp-1] != 1 && num[tmp-1])
		{
			if (num[tmp-1] < 0)
			{
				d.push_front(d.back());
				d.pop_back();
				num[tmp-1]++;
			}
			else if (num[tmp-1] > 1)
			{
				d.push_back(d.front());
				d.pop_front();
				num[tmp-1]--;
			}
		}
	}
	while (!dst.empty())
	{
		cout << dst.front() << ' ';
		dst.pop_front();
	}
	return (0);
}
