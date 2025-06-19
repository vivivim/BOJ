#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	queue<int> q;

	q.push(4); // q[4]
	q.push(3); // q[4, 3]
	q.push(19);// q[4, 3, 19]

	printf("q top : %d\n", q.front());
	printf("q back : %d\n", q.back());
	q.pop();
	printf("q pop\n");
	printf("q top : %d\n", q.front());

	stack<char> s;

	s.push('y');
	s.push('b');
	s.push('o');
	printf("s top: %c\n", s.top());
	s.pop();
	printf("s pop\ns top: %c\n", s.top());
	return (0);
}
