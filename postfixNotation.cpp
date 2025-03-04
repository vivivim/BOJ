#include <iostream>
#include <stack>
#include <vector>
#include <ctype.h>

std::vector<char>	dst;

bool	isPM(char c)
{
	if (c == '+' || c == '-')
		return 1;
	return 0;
}

bool	isMD(char c)
{
	if (c == '*' || c == '/')
		return 1;
	return 0;
}

int	main(void)
{
	std::string	input;
	std::cin >> input;

	std::stack<char>	op;
	for (int i = 0; i < input.size(); ++i)
	{
		if (isalpha(input[i]))
			dst.push_back(input[i]);
		else if (input[i] == '(')
			op.push(input[i]);
		else if (input[i] == ')')
		{
			while (!op.empty() && op.top() != '(')
			{
				dst.push_back(op.top());
				op.pop();
			}
			if (!op.empty())
				op.pop();
		}
		else if (isMD(input[i]))
		{
			while (!op.empty() && isMD(op.top()))
			{
				dst.push_back(op.top());
				op.pop();
			}
			op.push(input[i]);
		}
		else if (isPM(input[i]))
		{
			while (!op.empty() && op.top() != '(')
			{
				dst.push_back(op.top());
				op.pop();
			}
			op.push(input[i]);
		}
	}
	while (!op.empty())
	{
		dst.push_back(op.top());
		op.pop();
	}
	std::vector<char>::iterator	it = dst.begin();
	for (; it != dst.end(); ++it)
		std::cout << *it;
	std::cout << std::endl;
	return 0;
}
