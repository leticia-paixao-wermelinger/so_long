/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:18:01 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:18:04 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	my_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
void	my_function(unsigned int i, char *alpha)
{
	if (alpha[i] >= 97 && alpha[i] <= 122)
		alpha[i] = alpha[i] - 32; 
}

int	main(void)
{
	char	str[] ="Teste 123 Go.";

	my_striteri(str, my_function);
	printf("%s \n", str);
	return (0);
}*/
