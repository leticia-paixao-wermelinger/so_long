/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:20:32 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/03/13 14:14:39 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_hooks(t_st_list *list)
{
	mlx_key_hook(list->window->mlx_win, key, list);
	mlx_hook(list->window->mlx_win, 17, 0, finish, list);
}

int	key(int key_code, t_st_list *list)
{
	if (key_code == ESC)
		clear_all(list);
	if (key_code == ARROW_UP || key_code == W)
		move_player(list, list->or_map->y - 1, list->or_map->x, key_code);
	if (key_code == ARROW_DOWN || key_code == S)
		move_player(list, list->or_map->y + 1, list->or_map->x, key_code);
	if (key_code == ARROW_RIGHT || key_code == D)
		move_player(list, list->or_map->y, list->or_map->x + 1, key_code);
	if (key_code == ARROW_LEFT || key_code == A)
		move_player(list, list->or_map->y, list->or_map->x - 1, key_code);
	return (0);
}

int	finish(t_st_list *list)
{
	clear_all(list);
	return (0);
}
