/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:55:29 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/06/23 14:44:04 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	get_split_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	in_delim;
	unsigned int	count;

	i = 0;
	in_delim = 1;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (in_delim)
				count++;
			in_delim = 0;
		}
		else
		{
			in_delim = 1;
		}
		i++;
	}
	return (count);
}

static char	*get_next_split(char **str_iter, char c)
{
	unsigned int	str_len;
	char			*split;

	str_len = 0;
	while (**str_iter == c && c != '\0')
		*str_iter += 1;
	while ((*str_iter)[str_len] && (*str_iter)[str_len] != c)
		str_len++;
	split = ft_substr(*str_iter, 0, str_len);
	(*str_iter) += str_len;
	if (!split)
		return (NULL);
	return (split);
}

static void	cleanup(char **splits)
{
	unsigned int	i;

	i = 0;
	while (splits[i])
	{
		free(splits[i++]);
	}
	free(splits);
}

char	**ft_split(char const *s, char c)
{
	char			*str_iter;
	char			**splits;
	unsigned int	i;
	unsigned int	count;

	if (!s)
		return (NULL);
	i = 0;
	count = get_split_count(s, c);
	str_iter = (char *)s;
	splits = ft_calloc(count + 1, sizeof(void *));
	if (!splits)
		return (NULL);
	while (i < count)
	{
		splits[i] = get_next_split(&str_iter, c);
		if (!splits[i])
		{
			cleanup(splits);
			return (NULL);
		}
		i++;
	}
	return (splits);
}
