/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:06:31 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/29 15:22:13 by alermolo         ###   ########.fr       */
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
static void	check_letters(char *to_find, char *input);

int	game_loop(t_vector *words)
{
	char	*input;
	char	**to_find;
	int		guesses = 0;

	to_find = at_vector(words, get_random_word(words));

	write(1, "input : ", 8);
	input = get_next_line(STDIN_FILENO);
	while (is_input_valid(input) == 0
			&& is_in_dictionary(words, input) == 0)
	{
		free(input);
		printf("this input is not in the dictionary\n");
		dprintf(1, RESET "input : ");
		input = get_next_line(STDIN_FILENO);
	}
	while (ft_strcmp(input, *to_find) != 0)
	{
		check_letters(*to_find, input);
		dprintf(1, RESET "input : ");
		free(input);
		input = get_next_line(STDIN_FILENO);
		while (is_input_valid(input) == 0
			&& is_in_dictionary(words, input) == 0)
		{
			free(input);
			printf("this input is not in the dictionary\n");
			dprintf(1, RESET "input : ");
			input = get_next_line(STDIN_FILENO);
		}
		guesses++;
		if (guesses == 6)
			dprintf(1, RESET "You lost! The word was %s\n", *to_find);
	}
	if (ft_strcmp(input, *to_find) == 0)
		dprintf(1, RESET "You won!\n");
	free(input);
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
	size_t	i = 0;
	int		count_to_find = times_letter_is_in_word(to_find, letter);
	int		count_input = times_letter_is_in_word(input, letter);

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
	size_t	i = 0;

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
