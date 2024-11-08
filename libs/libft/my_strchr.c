
#include "libft.h"  

char	*my_strchr(const char *s, int c)
{
	int		i;
	char	ch;
	char	*st;

	i = 0;
	ch = (char)c;
	st = (char *)s;
	while (st[i])
	{
		if (st[i] == ch)
			return (&st[i]);
		i++;
	}
	if (c == '\0')
		return (&st[i]);
	return (NULL);
}
/*
#include <string.h>

int	main()
{
	const char	str[] = "";
	char	c = '\0';
	char	*returned;
	char	*or_returned;
	int	i = 0;

	returned = my_strchr(str, c);
	or_returned = strchr(str, c);
	printf("O endereço inicial do ponteiro é %p. \n", &str);
	printf("O endereço retornado na minha função é %p. \n", &returned);
	printf("O endereço retornado na função original é %p. \n", &or_returned);
	printf("Caracter com a minha função: %c \n", returned[i]);
	printf("Caracter com a função original: %c \n", or_returned[i]);
}*/
