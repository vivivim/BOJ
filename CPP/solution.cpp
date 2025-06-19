#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int n, tmp, dst, s1, s2;
vector<int> v;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
	cin >> tmp;
	v.push_back(tmp);
    }

    vector<int>::iterator start = v.begin();
    vector<int>::iterator end = v.end() - 1;
    s1 = *start;
    s2 = *end;
    dst = abs(*start + *end);
    while (start < end) {
	tmp = *start + *end;
	if (abs(tmp) < dst) {
	    dst = abs(tmp);
	    s1 = *start;
	    s2 = *end;
	}
	if (tmp < 0)
	    ++start;
	else
	    --end;
    }
    cout << s1 << ' ' << s2;
    return 0;
}
