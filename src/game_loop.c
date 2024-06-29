/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:06:31 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/29 06:53:15 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "wordle.h"
#include "ft_string.h"
#include "ascii.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	is_input_valid(char *input);
static int	is_in_dictionary(t_vector *words, char *str);

int	game_loop(t_vector *words)
{
	char	*input;

	write(1, "input :", 7);
	input = get_next_line(STDIN_FILENO);
	while (is_input_valid(input) == 0
		&& is_in_dictionary(words, input) == 0)
	{
		free(input);
		printf("this input is not in the dictionary\n");
		write(1, "input :", 7);
		input = get_next_line(STDIN_FILENO);
	}
	return (0);
}

static int	is_in_dictionary(t_vector *words, char *str)
{
	size_t	i;
	char	**s;

	i = 0;
	while (i < words->len)
	{
		s = at_vector(words, i);
		if (ft_strcmp(*s, str) == 0)
			return (1);
		++i;
	}
	return (0);
}

static int	is_input_valid(char *input)
{
	int	i;

	i = 0;
	if (ft_strlen(input) != 5)
		return (0);
	while (input[i])
	{
		if (ft_isalpha(input[i]) == 0)
			return (0);
		ft_tolower(input[i]);
		++i;
	}
	return (1);
}
