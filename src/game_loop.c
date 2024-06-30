/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:06:31 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/30 06:25:45 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "wordle.h"
#include "ft_string.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void	check_letters(char *to_find, char *input);

int	game_loop(t_vector *words)
{
	char	*input;
	char	**to_find;
	int		guesses = 6;

	to_find = at_vector(words, get_random_word(words));
	input = get_input(words, &guesses);
	if (input == NULL)
		return (-1);
	while (ft_strcmp(input, *to_find) != 0)
	{
		check_letters(*to_find, input);
		free(input);
		input = get_input(words, &guesses);
		if (input == NULL)
			return (-1);
		if (guesses == 0 && ft_strcmp(input, *to_find) != 0)
		{
			dprintf(1, RESET "You lost! The word was %s", *to_find);
			break;
		}
	}
	if (ft_strcmp(input, *to_find) == 0)
		dprintf(1, RESET "You won!\n");
	free(input);
	return (0);
}

static int	times_letter_is_in_word(char *word, char letter)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (word[i])
	{
		if (word[i] == letter)
			count++;
		i++;
	}
	return (count);
}

static int	correct_position(char *to_find, char *input, char letter, int pos)
{
	if (to_find[pos] == letter && input[pos] == letter)
		return (1);
	return (0);
}

static int	letter_is_in_word(char *to_find, char *input, char letter, size_t pos)
{
	size_t		i;
	const int	count_to_find = times_letter_is_in_word(to_find, letter);
	const int	count_input = times_letter_is_in_word(input, letter);

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] == letter)
		{
			if (count_input > count_to_find)
				return (correct_position(to_find, input, letter, pos));
			return (1);
		}
		i++;
	}
	return (0);
}

static void	check_letters(char *to_find, char *input)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if (letter_is_in_word(to_find, input, input[i], i))
		{
			if (correct_position(to_find, input, input[i], i))
				print_green(input[i]);
			else
				print_yellow(input[i]);
		}
		else
			print_gray(input[i]);
		i++;
	}
}
