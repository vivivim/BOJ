#include <iostream>
using namespace std;

int n, m, num[10000], dst;

int init_cal() {
    int tmp = 0;
    for (int i = 0; i < n; ++i)
	tmp += num[i];
    return tmp;
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
	cin >> num[i];

    int start = 0;
    int end = 0;
    int hap = num[0];
    while (start < n && end < n) {
	if (hap < m) {
	    ++end;
	    if (end < n)    
    		hap += num[end];
	} else {
	    if (hap == m)
    		++dst;
	    hap -= num[start];
	    ++start;
	    if (start > end) {
		hap = num[start];
		++end;
	    }
	}
    }
    cout << dst;
    return 0;
}
