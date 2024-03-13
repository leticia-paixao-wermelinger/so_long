/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:16:23 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:16:27 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_length(int nb);
static char	*smallest_int(char *s);
static void	dec_nb(char *s, int n, int size);

char	*my_itoa(int n)
{
	char	*str;
	int		length;

	length = nb_length(n);
	if (n == -2147483648)
		length = 11;
	str = (char *)malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[length] = '\0';
	if (n == -2147483648)
		return (smallest_int(str));
	if (n == 0)
		str[0] = '0';
	else
	{
		dec_nb(str, n, length);
	}
	return (str);
}

static int	nb_length(int nb)
{
	int	size;

	size = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		size += 1;
		nb *= -1;
	}
	while (nb > 9)
	{
		if (nb % 10 != 0)
			nb = nb - (nb % 10);
		else
		{
			nb = nb / 10;
			size += 1;
		}
	}
	return (size);
}

static char	*smallest_int(char *s)
{
	s[0] = '-';
	s[1] = '2';
	s[2] = '1';
	s[3] = '4';
	s[4] = '7';
	s[5] = '4';
	s[6] = '8';
	s[7] = '3';
	s[8] = '6';
	s[9] = '4';
	s[10] = '8';
	s[11] = '\0';
	return (s);
}

static void	dec_nb(char *s, int n, int size)
{
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		s[size - 1] = (n % 10) + '0';
		size--;
		n = n / 10;
	}
}
/*
#include <stdio.h>

int	main()
{
	#include <limits.h>
	
	int		n;
	char	*s;

	n = -2147483648;
	s = my_itoa(n);
	printf("%i \n", INT_MIN);
	printf("%s \n", s);
	free(s);
}*/
