
#include "libft.h"

static void	my_own_putchar(char n, int fd);

void	my_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			my_putnbr_fd((n = -n), fd);
		}
		else if (n > 9)
		{
			my_putnbr_fd((n / 10), fd);
			my_putnbr_fd((n % 10), fd);
		}
		else
			my_own_putchar((n + '0'), fd);
	}
}

static void	my_own_putchar(char n, int fd)
{
	write(fd, &n, 1);
}
/*
#include <limits.h>
#include <stdio.h>
int		main()
{
	my_putnbr_fd(6, 1);
}*/
