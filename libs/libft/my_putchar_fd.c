
#include "libft.h"

void	my_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
