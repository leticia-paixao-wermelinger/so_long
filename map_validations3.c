/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:06:56 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/03/09 18:44:22 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_size(t_map *or_map, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	str = or_map->map;
	while (str && str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		i++;
	}
	if (c == 'y')
		return (i);
	if (c == 'x')
		return (j);
	return (0);
}

int	verify_extension(char *str)
{
	const char	*map_ext = ".ber";
	int			i;
	int			j;

	i = 0;
	j = 3;
	while (str[i])
		i++;
	i--;
	while (j >= 0)
	{
		if (str[i] != map_ext[j])
			return (FILE_EXTENSION_ERROR);
		j--;
		i--;
	}
	if (i < 0)
		return (FILE_EXTENSION_ERROR);
	return (NO_ERROR);
}
