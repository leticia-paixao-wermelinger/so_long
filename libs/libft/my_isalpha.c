/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:15:59 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:16:02 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_isalpha(int c)
{
	if ((c >= 65 && c <= 122) && (!(c >= 91 && c <= 96)))
		return (1024);
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

	a = my_isalpha(argv[1][0]);
	original = isalpha(argv[1][0]);
	printf("Minha função: %i \n", a);
	if (a == 0)
		printf("O caractere digitado não é um alfabeto \n");
	else
		printf("O caractere digitado é um alfabeto \n");
	printf("Função original: %i \n", original);
	return (0);
}*/
