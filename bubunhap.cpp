#include <iostream>
using namespace std;
int	n, s, arr[100000];
int hap, dst;
int start, fin;

int	main(void)
{
	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	hap += arr[start];
	while (start <= fin && fin < n)
	{
		if (hap >= s)
		{
			if (!dst || dst > fin-start+1)
				dst = fin-start+1;
			hap -= arr[start++];
		}
		else
		{
			hap += arr[++fin];
		}
	}
	cout << dst;
	return 0;
}
