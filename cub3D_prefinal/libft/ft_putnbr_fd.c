#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	power;
	int	save;

	power = 1;
	save = n;
	if (n < 0)
	{
		power = -1;
		ft_putchar_fd('-', fd);
	}
	while (n <= -10 || n >= 10)
	{
		n = n / 10;
		power = power * 10;
	}
	while (power != 0)
	{
		ft_putchar_fd((save / power) + '0', fd);
		save = save - (save / power) * power;
		power = power / 10;
	}
}
