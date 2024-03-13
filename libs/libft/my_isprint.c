/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:16:19 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:16:22 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}
/*
int	main()
{
	#include <stdio.h>
	#include <ctype.h>

	int	a;
	int	original;
	char	teste = '\n';

	a = my_isprint(teste);
	original = isprint(teste);
	printf("Minha função: %i \n", a);
	if (a == 0)
		printf("O caractere digitado não é printável \n");
	else
		printf("O caractere digitado é printável \n");
	printf("Função original: %i \n", original);
	return (0);
}*/
