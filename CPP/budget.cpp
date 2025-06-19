#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int n, tmp, m;
vector<int> req;

int cal(int mid) {
    vector<int>::iterator it = req.begin();
    int dst = 0;
    while (it != req.end()) {
	if (*it <= mid)
	    dst += *it;
	else
	    dst += mid;
	++it;
    }
    return dst;
}

int binary_search(int start, int end) {
    int mid = 0, dst = 0, tmp = 0;
    while (start <= end) {
	mid = (start+end)/2;
	tmp = cal(mid);
	if (tmp < m) {
	    dst = mid;
	    start = mid+1;
	}
	else if (tmp > m)
	    end = mid-1;
	else {
	    dst = mid;
	    break;
	}
    }
    return dst;

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
	cin >>tmp;
	req.push_back(tmp);
    }
    sort(req.begin(), req.end());
    cin >> m;
    if (accumulate(req.begin(), req.end(), 0) <= m)
	cout << *max_element(req.begin(), req.end());
    else {
	cout << binary_search(1, *(req.end()-1));
    }
    return 0;
}
