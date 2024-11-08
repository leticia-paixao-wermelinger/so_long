
#include "libft.h"

static char	*read_line(char *str, int fd, int ret_r)
{
	char		*file;

	file = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!file)
		return (NULL);
	while (ret_r > 0)
	{
		ret_r = read(fd, file, BUFFER_SIZE);
		if (ret_r < 0)
		{
			free(file);
			return (NULL);
		}
		if (ret_r == 0)
			break ;
		file[ret_r] = '\0';
		str = gnl_ft_strjoin(str, file);
		if (*gnl_ft_strchr(file, '\n') == '\n'
			|| gnl_my_strchr(file, '\0') < BUFFER_SIZE)
			break ;
	}
	free(file);
	return (str);
}

static char	*cut_line(char *str, char **extra)
{
	char	*temp;
	char	*nl_pos;
	int		nl_index;

	nl_pos = gnl_ft_strchr(str, '\n');
	temp = str;
	if (!str)
		return (NULL);
	if (*nl_pos == '\n' && *(nl_pos + sizeof(char)) != '\0')
	{
		nl_index = gnl_my_strchr(str, '\n');
		*extra = gnl_ft_substr(str, nl_index + 1, \
				(gnl_ft_strlen(str) - nl_index));
		str = gnl_ft_substr(temp, 0, nl_index + 1);
		free(temp);
	}
	return (str);
}

long unsigned int	gnl_ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*get_next_line(int fd)
{
	static char	*extra;
	char		*str;

	str = extra;
	extra = NULL;
	if (str && gnl_ft_strchr(str, '\n')[0] == '\n')
	{
		str = cut_line(str, &extra);
		return (str);
	}
	str = read_line(str, fd, 1);
	str = cut_line(str, &extra);
	return (str);
}
