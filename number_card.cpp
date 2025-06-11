#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, tmp;
vector<int> v;
queue<int> q;

int binary_search(int start, int end) {
    int mid = (start + end)/2;
    while (start <= end && mid < v.size()) {
	if (v[mid] == tmp)
	    return 1;
	else if (tmp > v[mid])
	    start = mid + 1;
	else
	    end = mid - 1;
	mid = (start + end)/2;
    }
    return 0;

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
	cin >> tmp;
	v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    cin >> m;
    for (int i = 0; i < m; ++i) {
	cin >> tmp;
	q.push(tmp);
    }

    while (!q.empty()) {
	tmp = q.front();
	q.pop();
	if (binary_search(0, v.size()))
	    cout << 1;
	else
	    cout << 0;
	cout << " ";
    }
    return 0;
}
