#include "libft.h"

static size_t	get_length(const char *s, size_t index, char c)
{
	size_t	len;

	len = 0;
	while (s[index + len] && s[index + len] != c)
		len++;
	return (len);
}

static char	**all_free(char **res)
{
	int	i;

	i = -1;
	while (res[++i])
		safe_free((void **)&res[i]);
	free(res);
	return (NULL);
}

//count the number of words
static size_t	count_word(const char *s, char c)
{
	size_t	word_counter;

	word_counter = 0;
	while (*s)
	{
		if (*s != c)
			word_counter++;
		while (*s != c && *s)
			s++;
		while (*s == c)
			s++;
	}
	return (word_counter);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	word_len;
	size_t	res_index;
	size_t	s_index;

	res_index = 0;
	s_index = 0;
	if (!s)
		return (NULL);
	if (!(ft_malloc((void **)&res, sizeof(*res), count_word(s, c) + 1)))
		return (NULL);
	while (s_index < ft_strlen(s))
	{
		if (s[s_index] != c)
		{
			word_len = get_length(s, s_index, c);
			res[res_index++] = ft_substr(s, s_index, word_len);
			if (!res)
				return (all_free(res));
			s_index += word_len;
		}
		s_index++;
	}
	res[res_index] = NULL;
	return (res);
}
