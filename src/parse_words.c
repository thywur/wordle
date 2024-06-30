/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 05:26:04 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/30 06:19:24 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_string.h"
#include "wordle.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	check_empty_file(size_t len);

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
		if (ft_strlen(word) != 6)
		{
			free(word);
			write(2, "error: invalid word in words.txt\n", 35);
			return (-1);
		}
		if (add_vector(words, &word))
		{
			free(word);
			return (-1);
		}
		word = get_next_line(fd);
	}
	return (check_empty_file(words->len));
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
