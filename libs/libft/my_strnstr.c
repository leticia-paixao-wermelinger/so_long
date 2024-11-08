
#include "libft.h"

char	*my_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	si;

	i = 0;
	si = 0;
	if (little[si] == '\0')
		return ((char *)big);
	while (big[i] && len > 0)
	{
		while ((little[si] == big[i + si] && big[i + si]) && ((len - si) > 0))
			si++;
		if (little[si] == '\0')
			return ((char *)big + i);
		i++;
		len--;
		si = 0;
	}
	return (0);
}
/*
#include <bsd/string.h>
int	main()
{
	int		n = 4;
	char	str_original[] = "DON'T PANIC!"; // big
	char	substring[] = "PANIC"; // little
	char	*ptr;
	char	*ptr_or;

	ptr = my_strnstr(str_original, substring, n);
	ptr_or = strnstr(str_original, substring, n);
	printf("Minha função strnstr(): %s \n", ptr);
	printf("Função strnstr() original: %s \n", ptr_or);
}*/
