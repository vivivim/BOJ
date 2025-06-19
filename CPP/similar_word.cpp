#include <iostream>
#include <vector>
using namespace std;

int	n, dst;
std::string	word, tmp;
vector<std::string>	check;
vector<int>	alpha(26);
vector<int> tlpha(26);

bool	is_sames()
{
	for (int i = 0; i < 26; ++i)
	{
		if (alpha[i] != tlpha[i])
			return false;
	}
	return true;
}

bool	is_similar()
{
	bool	one = false;
	for (int i = 0; i < 26; ++i)
	{
		if (alpha[i] != tlpha[i] && !one)
		{
			if (alpha[i] + 1 == tlpha[i] || alpha[i]-1 == tlpha[i])
				one = true;
		}
		else if (alpha[i] != tlpha[i])
			return false;
	}
	return true;
}

int	main(void)
{
	cin >> n >> word;
	for (int i = 0; i < n-1; ++i)
	{
		cin >> tmp;
		check.push_back(tmp);
	}
	for (int i = 0; i < word.size(); ++i)
		alpha[word[i]-'A'] += 1;
	
	while (!check.empty())
	{
		tmp = check.back();
		check.pop_back();
		for (int i = 0; i < tmp.size(); ++i)
			tlpha[tmp[i]-'A'] += 1;
		if (is_sames())
			++dst;
		else if (is_similar())
			++dst;
		for (int i = 0; i < 26; ++i)
			tlpha[i] = 0;
	}
	cout << dst;
	return 0;
}
