
#include "libft.h"

static long unsigned int	my_own_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*my_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*st;

	if (!s)
		return (NULL);
	i = 0;
	st = (char *)malloc((my_own_strlen((char *)s) + 1) * sizeof(char));
	if (!st)
		return (NULL);
	while (s[i])
	{
		st[i] = f(i, s[i]);
		i++;
	}
	st[i] = '\0';
	return (st);
}
/*
#include <stdio.h>
char	my_function(unsigned int i, char alpha)
{
	(void)i;
	if (alpha >= 97 && alpha <= 122)
		alpha = alpha - 32;
	return (alpha);
}

int	main(void)
{
	char const	str[] ="Teste 123 Go.";
	char		*s;

	s = my_strmapi(str, my_function);
	printf("%s \n", s);
	free(s);
	return (0);
}*/
