
#include "libft.h"

static long unsigned int	my_own_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*my_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	string = (char *)malloc((my_own_strlen(s1) + \
			my_own_strlen(s2) + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	string[i] = '\0';
	return (string);
}
/*
#include <stdio.h>
int	main()
{
	char	str1[] = "Quero almoçar";
	char	str2[] = " uma lasanha.";
	char	*ret;

	ret = my_strjoin(str1, str2);
	printf("%s\n", ret);
	free(ret);
	return (0);
}*/
