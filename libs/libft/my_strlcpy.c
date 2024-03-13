/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:18:12 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:18:15 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

size_t	my_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	count;
	unsigned int	size_src;

	count = 0;
	size_src = 0;
	while (src[size_src])
		size_src++;
	if (size > 0)
	{
		while (src[count] && count < (size - 1))
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	return (size_src);
}
/*
#include <bsd/string.h>
int	main()
{
	unsigned int	number;
	unsigned int	my_returned;
	unsigned int	or_returned;
	char	src1[] = "String testeee 01";
	char    dest1[8];
	char	src2[] = "String testeee 02";
	char	dest2[8];

	printf("dest1 add: %p\n", &dest1);
	printf("dest2 add: %p\n", &dest2);
	printf("src1 add: %p\n", &src1);
    printf("src2 add: %p\n", &src2);

	number = 20;
	printf("\nString original p/ minha: %s\n", src1);
	my_returned = my_strlcpy(dest1, src1, number);
	printf("String destino depois da minha strlcpy(): %s\n", dest1);
	printf("Retorno da minha strlcpy(): %i\n\n", my_returned);

	printf("String original p/ função original:%s\n", src2);
	or_returned = strlcpy(dest2, src2, number);
	printf("String destino depois da strlcpy() original: %s\n", dest2);
	printf("Retorno da strlcpy() original: %i\n\n", or_returned);

	printf("src1: %s\n", src1);
	printf("src2: %s\n", src2);
	return (0);
}*/
