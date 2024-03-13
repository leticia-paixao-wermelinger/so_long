/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:18:45 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:18:49 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	my_own_strlen(char const *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*my_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*substr;

	i = 0;
	substr = (char *)malloc((len * sizeof(char)) + 1);
	if (!substr || !s)
		return (NULL);
	while (len > 0)
	{
		if (start >= my_own_strlen(s))
			substr[i++] = '\0';
		else
			substr[i++] = s[start++];
		len--;
	}
	substr[i] = '\0';
	return (substr);
}
/*
#include <stdio.h>
int	main()
{
	char const	str[] = "Don't panic!";
	char	*st;
	unsigned int	s = 15;
	unsigned long int	l = 5;

	st = my_substr(str, s, l);
	printf("%s \n", st);
	free(st);
	return (0);
}*/
