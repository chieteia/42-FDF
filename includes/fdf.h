#ifndef FDF_H
# define FDF_H

# include "structher.h"
# include "libft.h"
# include "get_next_line.h"
# include "error_msg.h"

t_admin	*init_master();

void	terminate(char *s);

void	read_map(const int fd, t_admin *master, t_list **map_data);

void	free_str_array(char ***array);
char	**parsed_by_char(char *line, char c);

#endif
