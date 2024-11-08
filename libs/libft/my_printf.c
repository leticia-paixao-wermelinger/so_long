
#include "libft.h"

static int	check_ptr(unsigned long int ptr)
{
	if (ptr == 0)
		return (my_putstr("(nil)"));
	return (my_putstr("0x") + my_putnbr_base(ptr, 16, 'p'));
}

static int	type_verification(va_list *args, char c)
{
	if (c == 'c')
		return (my_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (my_putstr(va_arg(*args, char *)));
	else if (c == 'p')
		return (check_ptr(va_arg(*args, unsigned long int)));
	else if (c == 'd' || c == 'i')
		return (my_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (my_putnbr_base(va_arg(*args, unsigned int), 10, 'c'));
	else if (c == 'x')
		return (my_putnbr_base(va_arg(*args, unsigned int), 16, c));
	else if (c == 'X')
		return (my_putnbr_base(va_arg(*args, unsigned int), 16, c));
	else if (c == '%')
		return (my_putchar('%'));
	return (0);
}

int	my_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += write(1, &str[i], 1);
		else if (str[i] == '%' && str[i + 1] == ' ' && str[i + 2] == '%')
		{
			count += write(1, &str[i + 2], 1);
			i = i + 2;
		}
		else
			count += type_verification(&args, str[i++ + 1]);
		i++;
	}
	va_end(args);
	return (count);
}
