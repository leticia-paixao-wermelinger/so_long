/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:17:46 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/03/14 20:36:32 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*open_map(char *str, int error)
{
	int		fd;
	t_map	*or_map;

	if (verify_extension(str) == FILE_EXTENSION_ERROR)
	{
		error = print_error(FILE_EXTENSION_ERROR);
		exit(0);
	}
	fd = open(str, O_RDWR);
	if (fd < 0)
		error = print_error(MAP_FAILED_OPEN);
	or_map = declare_or_map(fd);
	error = verify_errors(or_map);
	if (error != NO_ERROR)
	{
		clear_or_map(or_map);
		exit(0);
	}
	return (or_map);
}

char	**read_map(int fd)
{
	char	*line;
	char	*map;
	char	**vect;
	int		count;

	count = 1;
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		map = gnl_ft_strjoin(map, line);
		if (line)
		{
			free(line);
			line = NULL;
		}
		count++;
		line = get_next_line(fd);
	}
	free(line);
	if (check_clear_line(map) == MAP_ERROR)
		return (NULL);
	vect = my_split(map, '\n');
	free(map);
	return (vect);
}

char	**copy_vect(char **map)
{
	char	**map2;
	int		i;

	i = 0;
	while (map[i])
		i++;
	map2 = (char **)calloc((i + 1), sizeof(char *));
	if (!map2)
		return (NULL);
	map2[i] = NULL;
	i = 0;
	while (map[i])
	{
		map2 = copy_vect_2(map, map2, i);
		i++;
	}
	return (map2);
}

char	**copy_vect_2(char **map, char **map2, int i)
{
	static int	j = 0;

	while (map[i][j])
		j++;
	map2[i] = my_calloc(j + 1, sizeof(char));
	if (!map2[i])
	{
		my_clean_vect(map2);
		return (NULL);
	}
	j = 0;
	while (map[i][j])
	{
		map2[i][j] = map[i][j];
		j++;
	}
	map2[i][j] = '\0';
	return (map2);
}

int	print_error(int e)
{
	my_printf("Error\n");
	if (e == -1)
		my_printf("Map error\n");
	else if (e == -2)
		my_printf("Please, insert a valid map.\n");
	else if (e == -3)
		my_printf("The map must have a .ber extension!\n");
	else if (e == -4)
		my_printf("The map must have 1 P, 1 E and at least 1 C!\n");
	else if (e == -5)
		my_printf("The map must be a rectangle!\n");
	else if (e == -6)
		my_printf("The map must be closed by walls (1)!\n");
	else if (e == -7)
		my_printf("The map must be playable!\n");
	else if (e == -8)
		my_printf("The map must only have the following characters:\
 '1', '0', 'E', 'P', 'C'!\n");
	return (e);
}
