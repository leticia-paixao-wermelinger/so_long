/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:41:09 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/03/13 14:43:49 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_is_playable(t_map *or_map)
{
	t_map	*cp_map;

	cp_map = declare_cp_map(or_map);
	search_map_path(cp_map, cp_map->y, cp_map->x);
	if (cp_map->check_e != 1)
		return (PLAYABLE_MAP);
	if (cp_map->check_c != cp_map->num_c)
		return (PLAYABLE_MAP);
	clear_cp_map(cp_map);
	return (NO_ERROR);
}

void	search_map_path(t_map *cp_map, int y, int x)
{
	if (cp_map->map[y][x] == 'C')
		cp_map->check_c++;
	if (cp_map->map[y][x] == 'E')
	{
		cp_map->check_e = 1;
		cp_map->map[y][x] = '1';
		return ;
	}
	cp_map->map[y][x] = '1';
	if (cp_map->map[y + 1][x] != '1')
		search_map_path(cp_map, (y + 1), (x));
	if (cp_map->map[y - 1][x] != '1')
		search_map_path(cp_map, (y - 1), (x));
	if (cp_map->map[y][x + 1] != '1')
		search_map_path(cp_map, (y), (x + 1));
	if (cp_map->map[y][x - 1] != '1')
		search_map_path(cp_map, (y), (x - 1));
}
