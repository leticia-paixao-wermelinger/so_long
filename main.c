
#include "so_long.h"

int	main(int ac, char *av[])
{
	t_map		*or_map;
	t_window	*window;
	t_img		*img;
	t_st_list	*list;

	if (ac != 2)
		return (my_printf("Please, insert the map path\n"));
	my_bzero(&or_map, sizeof(t_map));
	my_bzero(&window, sizeof(t_window));
	my_bzero(&img, sizeof(t_img));
	my_bzero(&list, sizeof(t_st_list));
	or_map = open_map(av[1], NO_ERROR);
	window = declare_window(or_map);
	img = declare_img(window);
	list = declare_list(or_map, window, img);
	print_imgs(list);
	set_hooks(list);
	mlx_loop_hook(window->mlx, &print_imgs, list);
	mlx_loop(window->mlx);
	return (0);
}
