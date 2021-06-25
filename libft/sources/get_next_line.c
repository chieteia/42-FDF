#include "get_next_line.h"

static int	make_line_and_set_stock(char **line, char **buff, char **stock)
{
	char	*tmp;
	size_t	len;

	len = 0;
	tmp = *stock;
	while (*tmp && *tmp != '\n')
	{
		len++;
		tmp++;
	}
	*line = ft_substr(*stock, 0, len);
	if (*tmp == '\n')
		tmp++;
	tmp = ft_substr(tmp, 0, ft_strlen(tmp));
	safe_free((void **)stock);
	*stock = tmp;
	if (!line || !stock)
	{
		safe_free((void **)buff);
		safe_free((void **)stock);
		return (FAILED);
	}
	return (OK);
}

static int	make_buff(int fd, ssize_t *read_len, char **buff, char **stock)
{
	*read_len = read(fd, *buff, BUFFER_SIZE);
	if (*read_len == -1)
	{
		safe_free((void **)buff);
		safe_free((void **)stock);
		return (FAILED);
	}
	(*buff)[*read_len] = '\0';
	return (OK);
}

static int	make_stock(char **buff, char **stock)
{
	*stock = ft_strjoin(*stock, *buff);
	if (*stock == NULL)
	{
		safe_free((void **)buff);
		safe_free((void **)stock);
		return (FAILED);
	}
	return (OK);
}

int	get_next_line(int fd, char **line)
{
	static char	*stock;
	char		*buff;
	ssize_t		read_len;

	read_len = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!ft_malloc((void **)&buff, sizeof(char), BUFFER_SIZE + 1))
		return (-1);
	while ((read_len > 0) && !ft_strchr(stock, '\n'))
	{
		if (make_buff(fd, &read_len, &buff, &stock) == FAILED)
			return (-1);
		if (make_stock(&buff, &stock) == FAILED)
			return (-1);
	}
	if (make_line_and_set_stock(line, &buff, &stock) == FAILED)
		return (-1);
	if (read_len == 0)
		safe_free((void **)&stock);
	safe_free((void **)&buff);
	return (!!read_len);
}
