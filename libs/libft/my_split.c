/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:17:49 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/03/03 12:04:31 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	if (!s)
		return (0);
	if (s[0] == c)
		count = 0;
	else if (c == '\0')
	{
		count = 1;
		return (count);
	}
	else
		count = 1;
	while (s[i])
	{
		if ((s[i] == c) && (s[i + 1] != '\0') && (s[i + 1] != c))
			count++;
		i++;
	}
	return (count);
}

static char	*new_str(char const *s, int start, int end, char **vect)
{
	int		j;
	char	*str;

	j = 0;
	if (!s)
		return (0);
	str = (char *)my_calloc((end - start + 2), sizeof(char));
	if (!str)
	{
		my_clean_vect(vect);
		return (NULL);
	}
	while (start <= end)
	{
		str[j] = s[start];
		start++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

static int	verification(char const *s, char c, char **vect)
{
	int	j;

	j = 0;
	if (!vect || !s)
		return (0);
	if (s[0] == '\0')
	{
		vect[j] = NULL;
		return (1);
	}
	if (c == '\0')
	{
		vect[j] = new_str(s, 0, my_strlen(s), vect);
		vect[j + 1] = NULL;
		return (1);
	}
	return (2);
}

static char	**make_vect(char const *s, char c, char **vect, int count)
{
	size_t	i;
	int		j;
	int		start;

	j = 0;
	i = 0;
	start = 0;
	while (j < count)
	{
		if (s[i] != c && i >= 1 && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			vect[j++] = new_str(s, start, i, vect);
		if ((i - 1) == my_strlen(s))
			break ;
		i++;
	}
	vect[j] = NULL;
	return (vect);
}

char	**my_split(char const *s, char c)
{
	int		count;
	char	**vect;

	count = count_words(s, c);
	vect = (char **)my_calloc((count + 1), sizeof(char *));
	if (verification(s, c, vect) == 0)
		return (NULL);
	if (verification(s, c, vect) == 1)
		return (vect);
	return (make_vect(s, c, vect, count));
}

/*
#include <stdio.h>

int	main()
{
	int	j = 0;
	int i = 0;
//	char *str = "    Leticia    Paixao  Wermelinger ";
//	char *str = "(null)";
//	char *str = "lorem ipsum dolor sit amet,  \
//consectetur adipiscing elit. Sed non risus.  \
//Suspendisse"; // Teste 02 do war machine
	char *str = "lorem ipsum dolor sit amet,  \
consectetur adipiscing elit. Sed non risus.  \
Suspendisse lectus tortor, dignissim sit amet,  \
adipiscing nec, ultricies sed, dolor. Cras elementum  \
ultricies diam. Maecenas ligula massa, varius a, \
semper congue, euismod non, mi.";
	char sep = 'z';
	char	**vect;

	
	vect = ft_split(str, sep);
	while (vect[i])
		i++;
	while (j <= i)
	{
		printf("|%s|\n", vect[j]);
		j++;
	}
//	printf("\n");
	j = 0;
	while (vect[j])
	{
		free(vect[j]);
		j++;
	}
	free(vect);
	return (0);
}*/
