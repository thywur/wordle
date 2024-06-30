/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 04:34:42 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/30 06:31:06 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii.h"
#include "ft_string.h"
#include "wordle.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	is_input_valid(char *input);
static int	is_in_dictionary(t_vector *words, char *str);

char	*get_input(t_vector *words, int *guesses)
{
	char	*input;

	if (dprintf(1, RESET "you got %d guesses left\n", *guesses) == -1
		|| dprintf(1, "input : ") == -1)
		return (NULL);
	input = get_next_line(STDIN_FILENO);
	while (input && is_input_valid(input) == 0
		&& is_in_dictionary(words, input) == 0)
	{
		free(input);
		if (dprintf(1, RESET "you got %d guesses left\n", *guesses) == -1
			|| printf("this word is not in the dictionary\n") == -1
			|| dprintf(1, "input : ") == -1)
			return (NULL);
		input = get_next_line(STDIN_FILENO);
	}
	(*guesses)--;
	return (input);
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
	if (ft_strlen(input) != 6)
		return (0);
	while (input[i])
	{
		if (ft_isalpha(input[i]) == 0)
			return (0);
		input[i] = ft_tolower(input[i]);
		++i;
	}
	return (1);
}
