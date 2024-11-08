
#include "libft.h" 

static char	*my_own_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*my_strdup(const char *s)
{
	char	*dest;

	dest = (char *)malloc((my_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	my_own_strcpy(dest, s);
	return (dest);
}
/*
#include <stdio.h>

int	main()
{
	#include <string.h>

	const char	str[] = "Abacaxi";
	char	*dest2;

	dest2 = my_strdup(str);
	printf("Minha pŕopria função strdup(): %s\n", dest2);
	free(dest2);

	dest2 = strdup(str);
	printf("Função strdup() original: %s\n", dest2);
	free(dest2);

	return (0);
}*/
