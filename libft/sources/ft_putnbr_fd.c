#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n / 10)
		ft_putnbr_fd(n / 10, fd);
	else
		write(fd, "-", n < 0);
	write(fd, &"0123456789"[ft_abs(n % 10)], 1);
}
