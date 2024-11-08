
#include "libft.h"

void	*my_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
/*
int	main()
{
	#include <stdio.h>

	char	str[] = "original"; //dest
	char	str2[] = "123456789"; //src

	char	*ret;

	printf("\nBefore memmove(): %s\n", str);

	ret = my_memmove(str, str2, 8);

	printf("After my memmove(): %s \n", ret);

	ret = memmove(str, str2, 8);
	printf("After the original memmove(): %s \n\n", ret);

	return (0);
}*/
