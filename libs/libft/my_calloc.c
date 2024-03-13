/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:15:41 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:15:45 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*my_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*str;				

	i = 0;
	if (nmemb == 0 || size == 0)
		return (my_strdup(" "));
	if (size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	str = (char *)malloc(nmemb * size);
	if (!str)
		return (NULL);
	while (i < (nmemb * size))
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
/*
#include <limits.h>
#include <stdio.h>

int	main()
{
	int	n;
	int	*my_str;
	int	*or_str;

	n = 5;
	my_str = my_calloc(UINT_MAX, UINT_MAX);
	or_str = calloc(n, 4);

	if (!my_str)
		return (123);
	printf("Minha própria função calloc(): ");
	while (n > 0)
		printf("%i", my_str[n--]);
	printf("\n");
	//printf("Função calloc() original: %i\n", or_str[n]);
	free(my_str);
	free(or_str);
	return (0);
}*/
