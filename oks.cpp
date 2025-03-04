#include <stack>
#include <stdio.h>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    int tmp = -1;
	stack<int> s;
    stack<int> dst;
    for (int i = n-1; i >= 0; i--)
    {
		while (!s.empty() && s.top() <= num[i])
			s.pop();
		if (s.empty())
			dst.push(-1);
		else
			dst.push(s.top());
    	s.push(num[i]);
	}
    for (int i = 0; i < n; i++)
    {
        printf("%d ", dst.top());
        dst.pop();
    }
    return (0);
}
