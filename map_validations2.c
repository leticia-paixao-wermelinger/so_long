
#include "so_long.h"

int	map_is_closed(char **map)
{
	if (check_vertical_walls(map) == CLOSED_MAP)
		return (CLOSED_MAP);
	if (check_horizontal_walls(map) == CLOSED_MAP)
		return (CLOSED_MAP);
	return (NO_ERROR);
}

int	check_vertical_walls(char **map)
{
	int	i;
	int	j;
	int	start;
	int	end;

	i = 0;
	j = 0;
	start = 0;
	while (map[i][j])
		j++;
	end = j - 1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((j == start || j == end) && map[i][j] != '1')
				return (CLOSED_MAP);
			j++;
		}
		i++;
	}
	return (NO_ERROR);
}

int	check_horizontal_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1')
				return (CLOSED_MAP);
			j++;
		}
		i++;
	}
	j = 0;
	i--;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (CLOSED_MAP);
		j++;
	}
	return (NO_ERROR);
}

int	count_cs(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map && map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

int	find_position(char **map, char c)
{
	int		i;
	int		j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (c == 'x')
					return (j);
				if (c == 'y')
					return (i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
