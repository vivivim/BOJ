#include <iostream>
#include <queue>
using namespace std;

int n, k, t;
int dst = 2147483647;
queue<pair<int, int> >	q;
bool visited[100001];

void	bfs(int n) {
    while (!q.empty()) {
	int loc = q.front().first;
	int dep = q.front().second;
	q.pop();

	if (loc == k && dst > dep)
	    dst = dep;
	if ((loc-1) >= 0 && !visited[loc-1]) {
	    visited[loc-1] = true;
	    q.push(make_pair(loc-1, dep+1));
	}
	if ((loc+1) <= 100000 && !visited[loc+1]) {
	    visited[loc+1] = true;
	    q.push(make_pair(loc+1, dep+1));
	}
	if ((loc*2) <= 100000 && !visited[loc*2]) {
	    visited[loc*2] = true;
	    q.push(make_pair(loc*2, dep+1));
	}
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    q.push(make_pair(n, 0));
    visited[n] = true;
    bfs(n);

    cout << dst;
    return 0;
}
