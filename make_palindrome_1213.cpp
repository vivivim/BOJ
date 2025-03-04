#include <iostream>
using namespace std;

int alpha[26];
int odd;

int main(void)
{
    string  s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i)
    {
	++alpha[s[i] - 'A'];
    }
    for (int i = 0; i < 26; ++i)
    {
	if (alpha[i] % 2)
	    ++odd;
    }
    if (odd > 1 || (!s.size()%2 && odd))
	cout << "I'm Sorry Hansoo";
    else
    {
	char	dst[s.size()];
	for (int i = 0; i <= s.size()/2; ++i)
	{
	    for (int j = 0; j < 26; ++j)
	    {
		if (alpha[j] > 1)
		{
		    dst[i] = j + 'A';
		    dst[s.size() - (i+1)] = j + 'A';
		    alpha[j] -= 2;
		    break;
		}
		else if (alpha[j] == 1 && i == s.size()/2)
		{
		    dst[i] = j + 'A';
		    --alpha[j];
		    break;
		}
	    }
	}
	for (int i = 0; i < s.size(); ++i)
    	    cout << dst[i];
    }

    return 0;
}
