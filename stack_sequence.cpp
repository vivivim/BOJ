#include <iostream>
#include <stack>
using namespace std;

int	main(void)
{
	int	n;
	cin >> n;

	int	seq[n];
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	int	i = 0, j = 1;
	stack<int>	s;
	while (i < n)
	{
		if (s.empty() || seq[i] > s.top())
		{
			s.push(j);
			cout << "+\n";
			j++;
		}
		else if (seq[i] <= s.top())
		{
			s.pop();
			cout << "-\n";
			i++;
		}//뽑은 숫자 기억하고 그것만 건너뛰어야 함  무조건 쁠쁠 x
	}
	return (0);
}
