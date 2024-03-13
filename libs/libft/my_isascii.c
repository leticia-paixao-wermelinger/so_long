/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:16:04 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:16:07 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	#include <stdio.h>
	#include <ctype.h>

	if (argc != 2)
	{
		printf("Favor digitar apenas um argumento \n");
		return (0);
	}
	int	i = 0;
	while (argv[1][i])
		i++;
	if (i > 1)
	{
		printf("Favor digitar apenas um caractere \n");
		return (0);
	}
	int	a;
	int	original;

	a = my_isascii(argv[1][0]);
	original = isascii(argv[1][0]);
	printf("Minha função: %i \n", a);
	if (a == 0)
		printf("O caractere digitado não faz parte da tabela ascii \n");
	else
		printf("O caractere digitado faz parte da tabela ascii \n");
	printf("Função original: %i \n", original);
	return (0);
}*/
