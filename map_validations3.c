/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:06:56 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/03/14 20:32:02 by lpaixao-         ###   ########.fr       */
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

int	check_clear_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			return (MAP_ERROR);
		}
		i++;
	}
	return (NO_ERROR);
}

int	verify_errors(t_map *or_map)
{
	int	error;

	error = NO_ERROR;
	if (verify_map_pec(or_map->map) == WRONG_PEC)
		error = print_error(WRONG_PEC);
	else if (verify_map_items(or_map->map) == WRONG_CHARACTER)
		error = print_error(WRONG_CHARACTER);
	else if (map_is_square(or_map->map) == SQUARE_MAP)
		error = print_error(SQUARE_MAP);
	else if (map_is_closed(or_map->map) == CLOSED_MAP)
		error = print_error(CLOSED_MAP);
	else if (map_is_playable(or_map) == PLAYABLE_MAP)
		error = print_error(PLAYABLE_MAP);
	return (error);
}
