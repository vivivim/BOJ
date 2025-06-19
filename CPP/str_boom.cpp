#include <iostream>
#include <stack>
#include <unistd.h>
#include <string.h>
using namespace	std;

int	main(void)
{
	char	*str = (char *)malloc(1000001);
	scanf("%s", str);
	char	*boom = (char *)malloc(37);
	scanf("%s", boom);
	int	bl = strlen(boom);

	stack<char>	st;
	stack<char>	gr;
	while (*str)
	{
		if (*str != boom[bl-1])
			st.push(*str);
		else
		{
			gr.push(*str);
			for (int i = 0; i < bl-1; i++)
			{
				if (!st.empty() && st.top() == boom[bl-(i+2)])
				{
					gr.push(st.top());
					st.pop();
				}
				else
				{
					while (!gr.empty())
					{
						st.push(gr.top());
						gr.pop();
					}
					break;
				}
			}
			while (!gr.empty())
				gr.pop();
		}
		str++;
	}
	while (!st.empty())
	{
		gr.push(st.top());
		st.pop();
	}
	if (gr.empty())
		cout << "FRULA" << endl;
	while (!gr.empty())
	{
		cout << gr.top();
		gr.pop();
	}
	return (0);
}
