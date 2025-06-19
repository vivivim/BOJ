#include <iostream>
#include <stack>
using namespace	std;

int	main(void)
{
	int	n, tmp;
	int	num[1000001] = {0, };
	stack<int>	st;
	stack<int>	dst;

	cin >> n;
	int	nim[n];
	for (int i = 0; i < n; i++)
	{
		cin >> nim[i];
		num[nim[i]]++;
	}
	for (int i = n-1; i >= 0; i--)
	{
		while (!st.empty() && num[st.top()] <= num[nim[i]])
			st.pop();
		if (st.empty())
			dst.push(-1);
		else
			dst.push(st.top());
		st.push(nim[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << dst.top() << ' ';
		dst.pop();
	}
	return(0);
}
