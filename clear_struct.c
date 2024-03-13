/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:49:56 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/03/13 14:10:59 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_all(t_st_list *list)
{
	clear_or_map(list->or_map);
	clear_img(list->img, list->window);
	clear_window(list->window);
	free(list);
	list = NULL;
	exit(0);
}

void	clear_or_map(t_map *or_map)
{
	my_clean_vect(or_map->map);
	free(or_map);
	or_map = NULL;
}

void	clear_cp_map(t_map *cp_map)
{
	my_clean_vect(cp_map->map);
	free(cp_map);
	cp_map = NULL;
}

void	clear_window(t_window *window)
{
	mlx_destroy_window(window->mlx, window->mlx_win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	free(window);
	window = NULL;
}

void	clear_img(t_img	*img, t_window *window)
{
	mlx_destroy_image(window->mlx, img->mlx_player);
	mlx_destroy_image(window->mlx, img->mlx_collectable);
	mlx_destroy_image(window->mlx, img->mlx_exit);
	mlx_destroy_image(window->mlx, img->mlx_wall);
	mlx_destroy_image(window->mlx, img->mlx_space);
	free(img);
	img = NULL;
}
