#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int	how_mosq(int i, int n, vector<int> te, vector<int> tx)
{
	int	ct = 0;

	for (int j = 0; j < n; j++)
	{
		if (i >= te[j] && i < tx[j])
			ct++;
	}

	return (ct);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int	n;
	cin >> n;
	vector<int>	v;
	vector<pair<int, int> >	input;
	int e, x;
	for (int i = 0; i < n; i++)
	{
		cin >> e >> x;
		input.push_back({e, x});
		v.push_back(e);
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	vector<int>	rev(v.size()), sum(v.size());

	for (auto& i : input)
	{
		int	val1 = lower_bound(v.begin(), v.end(), i.first) - v.begin();
		int val2 = lower_bound(v.begin(), v.end(), i.second) - v.begin();
		rev[val1] = i.first;
		rev[val2] = i.second;
		sum[val1]++;
		sum[val2]--;
	}

	for (int i = 1; i < sum.size(); i++)
		sum[i] += sum[i-1];

	int	res = 0;
	for (auto& i: sum)
		res = max(res, i);
	cout << res << '\n';

	int	em, xm;
	bool	flag = false;
	for (int i = 0; i < sum.size(); i++)
	{
		if (!flag && sum[i] == res)
		{
			flag = true;
			em = rev[i];
		}
		if (flag && sum[i] != res)
		{
			xm = rev[i];
			break ;
		}
	}
	cout << em << ' ' << xm;
	return (0);
}
