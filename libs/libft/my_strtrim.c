/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:18:39 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/02/17 00:18:43 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long unsigned int	my_own_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

static int	cut_str(char const *set, char str)
{
	int		i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == str)
			return (1);
	}
	return (0);
}

static char	*cpy_str(char *s, char const *s1, int ini, int end)
{
	int	i;

	i = 0;
	while (ini <= end)
	{
		s[i] = s1[ini];
		ini++;
		i++;
	}
	s[i] = '\0';
	return (s);
}

static int	count_start(char const *s1, char const *set)
{
	int	ini;

	ini = 0;
	while (s1[ini])
	{
		if (cut_str(set, s1[ini]) == 1)
			ini++;
		else
			break ;
	}
	return (ini);
}

char	*my_strtrim(char const *s1, char const *set)
{
	int		ini;
	int		end;
	char	*s;

	if (!s1 || !set)
		return (NULL);
	end = my_own_strlen((char *)s1);
	ini = count_start(s1, set);
	while (end >= ini)
	{
		if (cut_str(set, s1[end - 1]) == 1)
			end--;
		else
			break ;
	}
	s = (char *)malloc((end - ini + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s = cpy_str(s, s1, ini, (end - 1));
	return (s);
}
/*
#include <stdio.h>
int	main()
{
	const char      str[] = "-+-+-+a part-+of it.-+++-+";
//	const char      str[] = "  \t    \n   \n\n\n\n    \t\t\t\n\t";
	const char      set[] = "";
	char    *ret;

	ret = my_strtrim(str, set);
	printf("Retorno: %s \n", ret);
    free(ret);
    return (0);
}*/
