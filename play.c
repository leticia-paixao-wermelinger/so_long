
#include "so_long.h"

void	move_player(t_st_list *list, int y, int x, int key_code)
{
	int			prev_y;
	int			prev_x;

	prev_y = list->or_map->y;
	prev_x = list->or_map->x;
	if (check_move(list, list->or_map, y, x) != 1)
		return ;
	list->or_map->y = y;
	list->or_map->x = x;
	list->or_map->map[y][x] = 'P';
	list->or_map->map[prev_y][prev_x] = '0';
	print_moves(key_code);
}

int	check_move(t_st_list *list, t_map *or_map, int y, int x)
{
	if (or_map->map[y][x] == 'E')
	{
		if (or_map->num_c != or_map->check_c)
			return (0);
		else
		{
			my_printf("You reached your destination! Congratulations!\n");
			clear_all(list);
		}
	}
	if (or_map->map[y][x] == 'C')
		or_map->check_c++;
	if (or_map->map[y][x] == '1')
		return (0);
	return (1);
}

void	print_moves(int key_code)
{
	static int	count = 0;

	count++;
	if (key_code == ARROW_UP || key_code == W)
		my_printf("Move %i, with a movement up\n", count);
	if (key_code == ARROW_DOWN || key_code == S)
		my_printf("Move %i, with a movement down\n", count);
	if (key_code == ARROW_RIGHT || key_code == D)
		my_printf("Move %i, with a movement right\n", count);
	if (key_code == ARROW_LEFT || key_code == A)
		my_printf("Move %i, with a movement left\n", count);
}
