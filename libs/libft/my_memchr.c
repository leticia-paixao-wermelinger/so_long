/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:16:29 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:16:33 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*my_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned int	ch;
	unsigned char	*st;

	st = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (n > 0)
	{
		if (st[i] == ch)
			return (&st[i]);
		i++;
		n--;
	}
	return (NULL);
}
/*
#include <string.h>

int	main()
{
	const char	str[] = {0, 1, 2 ,3 ,4 ,5};
	char	c = 'x';
	void	*returned;
	char	*or_returned;
	int	n = 8;

	returned = my_memchr(str, 2 + 256, 3);
	or_returned = (char *)memchr(str, 2 + 256, 3);
	printf("O endereço inicial do ponteiro é %p. \n", &str);
	printf("O endereço retornado na minha função é %p. \n", &returned);
	printf("O endereço retornado na função original é %p. \n", &or_returned);
	printf("Caracter com a minha função: %c \n", *((char *)returned));
	printf("Caracter com a função original: %c \n", *or_returned);
}*/
