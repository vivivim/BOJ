#include <stack>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int	main(void)
{
	char	*input = (char *)malloc(101);
	char	*str;
	memset(input, 0, 101);
	scanf("%[^\n]s", input);
	getchar();
	for (int i = 0; *input != '.'; i++)
	{
		str = input;
		stack<char>	left;
		while (*str != '.')
		{
			if (*str == '(' || *str == '[')
				left.push(*str);
			if (*str == ')')
			{
				if (!left.empty() && left.top() == '(')
					left.pop();
				else
					break ;
			}
			if (*str == ']')
			{
				if (!left.empty() && left.top() == '[')
					left.pop();
				else
					break ;
			}
			str++;
		}
		if (*str != '.' || !left.empty())
			printf("no\n");
		else
			printf("yes\n");
		memset(input, 0, 101);
		scanf("%[^\n]s", input);
		getchar();
	}
	return (0);
}
