#include "libft.h"

int	ft_isdigit_base(char c, int base)
{
	const char	*digits = "0123456789ABCDEF";
	int			index;

	index = 0;
	while (index < base)
	{
		if (digits[index] == ft_toupper(c))
			return (index);
		index++;
	}
	return (-1);
}
