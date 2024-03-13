/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_clean_vect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:51:32 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/03/10 14:57:51 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	my_clean_vect(char **vect)
{
	int	i;

	i = 0;
	while (vect[i])
		i++;
	while (i >= 0)
	{
		free(vect[i]);
		vect[i] = NULL;
		i--;
	}
	free(vect);
	vect = NULL;
}
