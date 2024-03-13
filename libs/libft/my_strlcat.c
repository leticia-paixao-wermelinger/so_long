/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:18:08 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:18:11 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static long unsigned int	my_own_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

size_t	my_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long int	id;
	unsigned long int	is;

	id = 0;
	is = 0;
	while (id < size && dst[id])
		id++;
	while (src[is] != '\0' && id + is + 1 < size)
	{
		dst[id + is] = src[is];
		is++;
	}
	if (id != size)
		dst[id + is] = '\0';
	return (id + my_own_strlen(src));
}
/*
#include <bsd/string.h>
int	main()
{
	unsigned long int	st;
	char				dst1[200] = "Continue a nadar, continue a nadar, nadar, nadar...";
	char				src1[] = "Pra achar a solução... Nadar!";
	unsigned int		n = 10;
	
	st = my_strlcat(dst1, src1, n);
	printf("\n Minha my_strlcat(): %s\n", dst1);
	printf("Meu retorno: %lu \n\n", st);

	char    str3[200] = "Continue a nadar, continue a nadar, nadar, nadar...";
	char    str4[] = "Pra achar a solução... Nadar!";

	st = strlcat(str3, str4, n);
	printf("strlcat() original: %s\n", str3);
	printf("Retorno original: %lu \n\n", st);
}*/
