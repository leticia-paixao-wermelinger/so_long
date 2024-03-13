/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:16:09 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:16:17 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
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

	a = my_isdigit(argv[1][0]);
	original = isdigit(argv[1][0]);
	printf("Minha função: %i \n", a);
	if (a == 0)
		printf("O caractere digitado não é um dígito (de 0 a 9) \n");
	else
		printf("O caractere digitado é um dígito (de 0 a 9) \n");
	printf("Função original: %i \n", original);
	return (0);
}*/
