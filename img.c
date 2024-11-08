
#include "so_long.h"

int	print_imgs(t_st_list *list)
{
	int	i;
	int	j;

	i = 0;
	while (list->or_map->map[i])
	{
		j = 0;
		while (list->or_map->map[i][j])
		{
			print_sprite(list->or_map->map[i][j], list, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	print_sprite(char c, t_st_list *list, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(list->window->mlx, list->window->mlx_win,
			list->img->mlx_wall, j * IMG_SIZE, i * IMG_SIZE);
	else if (c == '0')
		mlx_put_image_to_window(list->window->mlx, list->window->mlx_win,
			list->img->mlx_space, j * IMG_SIZE, i * IMG_SIZE);
	else if (c == 'P')
		mlx_put_image_to_window(list->window->mlx, list->window->mlx_win,
			list->img->mlx_player, j * IMG_SIZE, i * IMG_SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(list->window->mlx, list->window->mlx_win,
			list->img->mlx_collectable, j * IMG_SIZE, i * IMG_SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(list->window->mlx, list->window->mlx_win,
			list->img->mlx_exit, j * IMG_SIZE, i * IMG_SIZE);
}
