/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:18:55 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:18:58 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
/*
int	main(int argc, char *argv[])
{
	#include <stdio.h>
	#include <ctype.h>

	char	ca;
	char	co;
	char	carg;

	if (argc != 2)
	{
		printf("Favor digitar apenas uma letra minúscula \n");
		return (0);
	}
	int	i = 0;
	while (argv[1][i])
		i++;
	if (i > 1)
	{
		printf("Favor digitar apenas uma letra minúscula \n");
		return (0);
	}
	int	a;
	int	original;

	a = my_toupper(argv[1][0]);
	ca = (char)a;
	carg = (char)argv[1][0];
	original = toupper(argv[1][0]);
	co = (char)original;
	printf("O caractere digitado foi %i (ou seja, %c) e, \
	com a minha toupper, ele ficou %i (ou seja, %c) \n", argv[1][0], carg, a, ca);
	printf("O caractere digitado foi %i (ou seja, %c) e, \
	com a minha toupper, ele ficou %i (ou seja, %c) \n", argv[1][0], carg, a, co);
	return (0);
}*/
