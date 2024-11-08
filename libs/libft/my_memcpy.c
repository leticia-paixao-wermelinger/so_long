
#include "libft.h"

void	*my_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	str = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		str[i] = str2[i];
		i++;
	}
	return (str);
}
/*
int	main()
{
	#include <stdio.h>

//	char	str[] = "original";
//	char	str2[] = "1234";

	char	*ret;

//	printf("\nBefore memset(): %s\n", str);

//	ret = my_memcpy(str, str2, sizeof(str2));
	ret = my_memcpy(((void*)0), ((void*)0), 3);
	printf("After my memset(): %s \n", ret);

//	ret = memcpy(str, str2, sizeof(str2));
	ret = memcpy(((void*)0), ((void*)0), 3);
	printf("After the original memset(): %s \n\n", ret);

	return (0);
}*/
