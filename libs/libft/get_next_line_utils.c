/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:53:19 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/03/03 12:47:46 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;
	char	*st;

	if (!s)
		return (0);
	i = 0;
	ch = (char)c;
	st = (char *)s;
	while (st[i] != '\n' && st[i])
	{
		if (st[i] == ch)
			return (&st[i]);
		i++;
	}
	if (c == '\n')
		return (&st[i]);
	if (c == '\0')
		return (&st[i]);
	return (NULL);
}

int	gnl_my_strchr(const char *s, int c)
{
	int		i;
	char	ch;
	char	*st;

	i = 0;
	ch = (char)c;
	st = (char *)s;
	while (st[i] != '\n' && st[i])
	{
		if (st[i] == ch)
			return (i);
		i++;
	}
	return (i);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*string;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	string = (char *)my_calloc((gnl_ft_strlen(s1) \
			+ gnl_ft_strlen(s2) + 1), sizeof(char));
	if (!string)
		return (NULL);
	string = gnl_my_join(s1, s2, string);
	free(s1);
	return (string);
}

char	*gnl_my_join(char *s1, char *s2, char *string)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

char	*gnl_ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*substr;

	i = 0;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr || !s)
		return (NULL);
	while ((size_t)i < len)
	{
		if (start >= gnl_ft_strlen(s))
			substr[i++] = '\0';
		else
			substr[i++] = s[start++];
	}
	substr[i] = '\0';
	return (substr);
}
