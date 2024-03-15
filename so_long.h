/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:06:18 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/03/14 20:31:20 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_SIZE 91

# include "libs/libft/libft.h"
# include "libs/minilibx/mlx.h"
# include <fcntl.h>

enum e_error_messages {
	NO_ERROR = 1,
	MAP_ERROR = -1,
	MAP_FAILED_OPEN = -2,
	FILE_EXTENSION_ERROR = -3,
	WRONG_PEC = -4,
	SQUARE_MAP = -5,
	CLOSED_MAP = -6,
	PLAYABLE_MAP = -7,
	WRONG_CHARACTER = -8
};

enum e_key_codes {
	ESC = 65307,
	ARROW_UP = 65362,
	W = 119,
	ARROW_DOWN = 65364,
	S = 115,
	ARROW_RIGHT = 65363,
	D = 100,
	ARROW_LEFT = 65361,
	A = 97
};

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		x;
	int		y;
	int		num_c;
	int		check_c;
	int		check_e;
}	t_map;

typedef struct s_window
{
	void	*mlx;
	int		width;
	int		height;
	void	*mlx_win;
}	t_window;

typedef struct s_img
{
	t_window	*window;
	int			width;
	int			height;
	char		*name_player;
	char		*name_collectable;
	char		*name_exit;
	char		*name_wall;
	char		*name_space;
	void		*mlx_player;
	void		*mlx_collectable;
	void		*mlx_exit;
	void		*mlx_wall;
	void		*mlx_space;
}	t_img;

typedef struct s_st_list
{
	t_map		*or_map;
	t_window	*window;
	t_img		*img;
}	t_st_list;

t_map		*open_map(char *str, int error);
t_map		*declare_or_map(int fd);
int			print_error(int e);
int			verify_extension(char *str);
int			verify_errors(t_map *or_map);
char		**read_map(int fd);
int			check_clear_line(char *map);
int			verify_map_pec(char **map);
int			check_pec(char **map, char c);
int			check_c(char **map, char c);
int			verify_map_items(char **map);
int			map_is_square(char **map);
int			map_is_closed(char **map);
int			check_vertical_walls(char **map);
int			check_horizontal_walls(char **map);
int			count_cs(char **map);
char		*find_p(char **map);
int			map_is_playable(t_map *or_map);
int			find_position(char **map, char c);
t_map		*declare_cp_map(t_map *or_map);
char		**copy_vect(char **map);
char		**copy_vect_2(char **map, char **map2, int i);
int			find_size(t_map *or_map, char c);
void		search_map_path(t_map *cp_map, int y, int x);
t_window	*declare_window(t_map *or_map);
void		set_hooks(t_st_list *list);
int			key(int key_code, t_st_list *list);
t_img		*declare_img(t_window *window);
t_st_list	*declare_list(t_map *or_map, t_window *window, t_img *img);
int			print_imgs(t_st_list *list);
void		print_sprite(char c, t_st_list *list, int i, int j);
void		move_player(t_st_list *list, int y, int x, int key_code);
int			check_move(t_st_list *list, t_map *or_map, int y, int x);
void		print_moves(int key);
int			finish(t_st_list *list);
void		clear_all(t_st_list *list);
void		clear_or_map(t_map *or_map);
void		clear_cp_map(t_map *cp_map);
void		clear_window(t_window *window);
void		clear_img(t_img *img, t_window *window);
#endif
