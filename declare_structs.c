
#include "so_long.h"

t_map	*declare_or_map(int fd)
{
	t_map	*or_map;

	or_map = my_calloc(1, sizeof(t_map));
	or_map->map = read_map(fd);
	if (or_map->map == NULL)
	{
		print_error(MAP_ERROR);
		free(or_map);
		exit(0);
	}
	or_map->width = find_size(or_map, 'x');
	or_map->height = find_size(or_map, 'y');
	if (check_pec(or_map->map, 'P') == NO_ERROR)
	{
		or_map->x = find_position(or_map->map, 'x');
		or_map->y = find_position(or_map->map, 'y');
	}
	or_map->num_c = count_cs(or_map->map);
	close(fd);
	return (or_map);
}

t_map	*declare_cp_map(t_map *or_map)
{
	t_map	*cp_map;

	cp_map = my_calloc(1, sizeof(t_map));
	cp_map->map = copy_vect(or_map->map);
	cp_map->width = or_map->width;
	cp_map->height = or_map->height;
	cp_map->x = or_map->x;
	cp_map->y = or_map->y;
	cp_map->num_c = or_map->num_c;
	cp_map->check_c = 0;
	cp_map->check_e = 0;
	return (cp_map);
}

t_window	*declare_window(t_map *or_map)
{
	t_window	*window;

	window = my_calloc(1, sizeof(t_window));
	window->mlx = mlx_init();
	if (!window->mlx)
	{
		free(window);
		return (NULL);
	}
	window->width = IMG_SIZE * or_map->width;
	window->height = IMG_SIZE * or_map->height;
	window->mlx_win = mlx_new_window(window->mlx,
			window->width, window->height, "so_long");
	return (window);
}

t_img	*declare_img(t_window *window)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->window = window;
	img->width = IMG_SIZE;
	img->height = IMG_SIZE;
	img->name_player = "assets/player.xpm";
	img->name_collectable = "assets/collectable.xpm";
	img->name_exit = "assets/exit.xpm";
	img->name_wall = "assets/wall.xpm";
	img->name_space = "assets/space.xpm";
	img->mlx_player = mlx_xpm_file_to_image(img->window->mlx,
			img->name_player, &img->width, &img->height);
	img->mlx_collectable = mlx_xpm_file_to_image(img->window->mlx,
			img->name_collectable, &img->width, &img->height);
	img->mlx_exit = mlx_xpm_file_to_image(img->window->mlx,
			img->name_exit, &img->width, &img->height);
	img->mlx_wall = mlx_xpm_file_to_image(img->window->mlx,
			img->name_wall, &img->width, &img->height);
	img->mlx_space = mlx_xpm_file_to_image(img->window->mlx,
			img->name_space, &img->width, &img->height);
	return (img);
}

t_st_list	*declare_list(t_map *or_map, t_window *window, t_img *img)
{
	t_st_list	*list;

	list = malloc(sizeof(t_st_list));
	list->or_map = or_map;
	list->window = window;
	list->img = img;
	return (list);
}
