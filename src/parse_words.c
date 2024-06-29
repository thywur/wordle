/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 05:26:04 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/29 06:04:00 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "wordle.h"
#include <fcntl.h>

int	parse_words(t_vector *words)
{
	int		fd;
	char	*word;

	fd = open(WORDS_PATH, O_RDONLY);
	if (fd == -1)
		return (-1);
	init_vector(words, sizeof(char *));
	word = get_next_line(fd);
	while (word)
	{
		if (add_vector(words, &word))
			return (-1);
		word = get_next_line(fd);
	}
	return (0);
}
