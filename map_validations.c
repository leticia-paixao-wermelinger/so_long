
#include "so_long.h"

int	verify_map_pec(char **map)
{
	if (check_pec(map, 'P') == WRONG_PEC)
		return (WRONG_PEC);
	if (check_pec(map, 'E') == WRONG_PEC)
		return (WRONG_PEC);
	if (check_c(map, 'C') == WRONG_PEC)
		return (WRONG_PEC);
	return (NO_ERROR);
}

int	verify_map_items(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if ((c != '1' && c != '0' && c != 'E' && c != 'P'
					&& c != 'C') || c == ' ')
				return (WRONG_CHARACTER);
			j++;
		}
		i++;
	}
	return (NO_ERROR);
}

int	check_pec(char **map, char c)
{
	int	i;
	int	j;
	int	checker;

	i = 0;
	checker = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				if (checker == 0)
					checker = 1;
				else
					return (WRONG_PEC);
			}
			j++;
		}
		i++;
	}
	if (checker == 0)
		return (WRONG_PEC);
	return (NO_ERROR);
}

int	check_c(char **map, char c)
{
	int	i;
	int	j;
	int	checker;

	i = 0;
	checker = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				if (checker == 0)
					checker = 1;
			}
			j++;
		}
		i++;
	}
	if (checker == 0)
		return (WRONG_PEC);
	else
		return (NO_ERROR);
}

int	map_is_square(char **map)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = my_strlen(map[i]);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
		}
		if (width != j)
		{
			return (SQUARE_MAP);
		}
		i++;
	}
	return (NO_ERROR);
}
