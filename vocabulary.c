#include <stdio.h>
#include <string.h>

int	count_over_m_word(char **word, int m)
{
	int	j = 0, ct = 0, tmp = 0;

	for (int i = 0; i < n; i++)
	{
		j = 0;
		while (word[i][j])
			tmp++;
		if (tmp >= m)
			ct++;
	}
	return (ct);
}

char	**check_multi(char **word)
{

int	main(void)
{
	int	m, n;
	scanf("%d %d", &n, &m);

	char	word[n][10];
	for (int i = 0; i < n; i++)
		scanf("%s", word[i]);

	for (int i = 0; i < n; i++)
	{
		if ((int)strlen(word[i]) < m)
			n = delete_word();
	}
	check_multi(word);



		int	ct;
	ct = count_over_m_word(word);

	char	voca[ct][10];
