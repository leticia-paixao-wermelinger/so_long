/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:16:48 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:16:52 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*my_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		str[i] = c;
		i++;
		n--;
	}
	return (str);
}
/*
int	main()
{
	#include <stdio.h>

	char str[] = "The memset() function fills the first n...";
	char	*ret;

	printf("\nBefore memset(): %s\n\n", str);

	ret = my_memset(str + 13, '.', 8*sizeof(char));

	printf("After my memset(): %s e %s \n\n", ret, str);

//	char str[] = "The memset() function fills the first n...";

	ret = memset(str + 13, '.', 8*sizeof(char));
	printf("After the original memset(): %s e %s \n\n", ret, str);

	return (0);
}*/
