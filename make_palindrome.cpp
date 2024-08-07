#include <iostream>
using namespace std;

string	s;
int	here;

bool	is_palindrome(int from, int to)
{
	int middle = (from+to)/2;
	for (int i = from; i <= middle; ++i)
	{
		if (s[i] != s[to+from-i])
			return false;
	}
	return true;
}

int	main(void)
{
	cin >> s;
	int end = s.size() - 1;
	for (int i = 0; i < s.size(); ++i)
	{
		if (is_palindrome(end-i, end))
			here = end-i;
	}
	cout << s.size() + here;
	return 0;
}
