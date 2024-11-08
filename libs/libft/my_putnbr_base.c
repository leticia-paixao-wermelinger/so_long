
#include "libft.h"

static void	my_own_putchar(char n);

int	my_putnbr_base(unsigned long int n, int max_base, char c)
{
	int		size;

	size = 1;
	if (n >= (unsigned long int)max_base)
		size += my_putnbr_base(n / max_base, max_base, c);
	if (c == 'X')
		my_own_putchar("0123456789ABCDEF"[n % max_base]);
	else
		my_own_putchar("0123456789abcdef"[n % max_base]);
	return (size);
}

static void	my_own_putchar(char n)
{
	write(1, &n, 1);
}
