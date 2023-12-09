#include <stdio.h>
#include <stdlib.h>

static int	count_word(char const *s, char c)
{
	int	ct;

	ct = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			ct++;
		while (*s && *s != c)
			s++;
	}
	return (ct);
}

static int	len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*put_word(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = len_word(s, c);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	while (i < len)
		word[i++] = *s++;
	word[i] = 0;
	return (word);
}

static char	**ft_free(char **dst, int i)
{
	while (i--)
		free(dst[i]);
	free(dst);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		i;

	dst = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!dst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			dst[i] = put_word(s, c);
			if (!dst[i])
				return (ft_free(dst, i));
		}
		while (*s && *s != c)
			s++;
		if (*s || *(s - 1) != c)
			i++;
	}
	dst[i] = 0;
	return (dst);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);
	char	*info = malloc(6);
	int		team[n], min[n], sec[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d %s", &team[i], info);
		char	**time = ft_split(info, ':');
		min[i] = atoi(time[0]);
		sec[i] = atoi(time[1]);
		free(time[0]);
		free(time[1]);
		free(time);
	}

	int	score[2] = {0, }, wmin[2] = {0, }, wsec[2] = {0, };
	for (int i = 0; i < n; i++)
	{
		if (score[0] > score[1])
		{
			wmin[0] += min[i] - min[i-1];
			wsec[0] += sec[i] - sec[i-1];
		}
		else if (score[1] > score[0])
		{
			wmin[1] += min[i] - min[i-1];
			wsec[1] += sec[i] - sec[i-1];
		}
		score[team[i]-1]++;
	}
	if (score[0] > score[1])
	{
		wmin[0] += 48 - min[n-1];
		wsec[0] += 0 - sec[n-1];
	}
	else if (score[1] > score[0])
	{
		wmin[1] += 48 - min[n-1];
		wsec[1] += 0 - sec[n-1];
	}
	for (int i = 0; i < 2; i++)
	{
		while (wsec[i] > 59)
		{
			wmin[i]++;
			wsec[i] -= 60;
		}
		while (wsec[i] < 0)
		{
			wmin[i]--;
			wsec[i] += 60;
		}
	}
	char	pone[6], ptwo[6];
	if (wmin[0] < 10)
	{
		pone[0] = '0';
		pone[1] = wmin[0] + '0';
	}
	else
	{
		pone[0] = wmin[0] / 10 + '0';
		pone[1] = wmin[0] % 10 + '0';
	}
	if (wmin[1] < 10)
	{
		ptwo[0] = '0';
		ptwo[1] = wmin[1] + '0';
	}
	else
	{
		ptwo[0] = wmin[1] / 10 + '0';
		ptwo[1] = wmin[1] % 10 + '0';
	}
	pone[2] = ':';
	ptwo[2] = ':';
	if (wsec[0] < 10)
	{
		pone[3] = '0';
		pone[4] = wsec[0] + '0';
	}
	else
	{
		pone[3] = wsec[0] / 10 + '0';
		pone[4] = wsec[0] % 10 + '0';
	}
	if (wsec[1] < 10)
	{
		ptwo[3] = '0';
		ptwo[4] = wsec[1] + '0';
	}
	else
	{
		ptwo[3] = wsec[1] / 10 + '0';
		ptwo[4] = wsec[1] % 10 + '0';
	}
	pone[5] = 0;
	ptwo[5] = 0;
	printf("%s\n%s", pone, ptwo);
	return (0);
}
