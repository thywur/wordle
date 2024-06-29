/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 01:00:11 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/27 02:33:30 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "mem.h"
#include <stdlib.h>

static int		ft_cut(char const *s, char c, char **strs);
static int		ft_count(char const *s, char c);
static void		free_strs(char **strs);

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	count;

	if (s == NULL)
		return (NULL);
	count = ft_count(s, c);
	strs = ft_calloc(count + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	if (ft_cut(s, c, strs) == 0)
		return (NULL);
	return (strs);
}

static int	ft_cut(char const *s, char c, char **strs)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (*s)
	{
		i = 0;
		while (s[i] != c && s[i])
			i++;
		if (i != 0)
		{
			strs[count] = malloc(sizeof(char) * (i + 1));
			if (!strs[count])
			{
				free_strs(strs);
				return (0);
			}
			ft_strlcpy(strs[count], s, i + 1);
			count++;
			s += i;
		}
		else
			s++;
	}
	return (1);
}

static void	free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static int	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (*s)
	{
		i = 0;
		while (s[i] != c && s[i])
			i++;
		if (i != 0)
		{
			s += i;
			count++;
		}
		else
			s++;
	}
	return (count);
}
