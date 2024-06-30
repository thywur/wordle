/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 05:26:04 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/30 07:07:45 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii.h"
#include "get_next_line.h"
#include "ft_string.h"
#include "wordle.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	check_empty_file(size_t len);
static int	check_wrong_word(char *word);
static int	is_alpha_loop(char *str);
static void	str_lower(char *str);

int	parse_words(t_vector *words)
{
	int		fd;
	char	*word;

	fd = open(WORDS_PATH, O_RDONLY);
	if (fd == -1)
		return (-1);
	word = get_next_line(fd);
	while (word)
	{
		if (check_wrong_word(word) == -1
			|| add_vector(words, &word))
		{
			free(word);
			return (-1);
		}
		word = get_next_line(fd);
	}
	return (check_empty_file(words->len));
}

static int	check_wrong_word(char *word)
{
	if (ft_strlen(word) != 6)
	{
		if (ft_strlen(word) == 5 && is_alpha_loop(word))
			return (0);
		write(2, "error: invalid word in words.txt\n", 34);
		return (-1);
	}
	if (word[5] != '\n' || is_alpha_loop(word) == 0)
	{
		write(2, "error: invalid word in words.txt\n", 34);
		return (-1);
	}
	str_lower(word);
	return (0);
}

static int	check_empty_file(size_t len)
{
	if (len == 0)
	{
		write(2, "error: words.txt is empty\n", 28);
		return (-1);
	}
	return (0);
}

static int	is_alpha_loop(char *str)
{
	size_t			i;
	const size_t	len = 5;

	i = 0;
	while (i < len && str[i])
	{
		if (ft_isalpha(str[i]) == 0)
			return (0);
		++i;
	}
	return (1);
}

static void	str_lower(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		str[len] = ft_tolower(str[len]);
		++len;
	}
}
