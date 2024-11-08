
#include "libft.h"

char	*my_strrchr(const char *s, int c)
{
	int		i;
	char	ch;
	char	*st;

	i = 0;
	ch = (char)c;
	st = (char *)s;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (st[i] == ch)
			return (&st[i]);
		i--;
	}
	return (NULL);
}
/*
#include <string.h>
int	main()
{
	const char	str[] = "Abacaxi";
	char	c = 'a';
	char	*returned;
	char	*or_returned;
	int	i = 0;

	returned = my_strrchr(str, c);
	or_returned = strrchr(str, c);
	printf("O endereço inicial do ponteiro é %p. \n", &str);
	printf("O endereço retornado na minha função é %p. \n", &returned);
	printf("O endereço retornado na função original é %p. \n", &or_returned);
	printf("Caracter com a minha função: %c \n", returned[i]);
	printf("Caracter com a função original: %c \n", or_returned[i]);
}*/
