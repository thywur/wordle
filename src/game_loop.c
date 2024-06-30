/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:06:31 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/30 11:59:29 by lespenel         ###   ########.fr       */
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
	while (ft_strncmp(input, *to_find, 5) != 0)
	{
		check_letters(*to_find, input);
		free(input);
		input = get_input(words, &guesses);
		if (input == NULL)
			return (-1);
		if (guesses == 0 && ft_strcmp(input, *to_find) != 0)
		{
			check_letters(*to_find, input);
			printf(RESET"You lost! The word was "BHGRN"%s"RESET, *to_find);
			break;
		}
	}
	if (ft_strncmp(input, *to_find, 5) == 0)
		dprintf(1, BHGRN "%s" RESET "You won!\n", *to_find);
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

static void get_correct_letter(char *to_find, char *input, int *color, int *ascii)
{
	size_t	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] == input[i])
		{
			ascii[(int)to_find[i]] += 1;
			color[i] = GREEN;
		}
		++i;
	}
}

static void	get_yellow_letter(char *to_find, int *color, char letter, int *ascii, int pos)
{
	size_t		i;
	const int	count_to_find = times_letter_is_in_word(to_find, letter);

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] == letter && color[i] != GREEN)
		{
			ascii[(int)to_find[i]] += 1;
			if (ascii[(int)to_find[i]] <= count_to_find)
				color[pos] = YELLOW;
		}
		i++;
	}
}

static void	check_letters(char *to_find, char *input)
{
	size_t	i;
	int		ascii[256] = {(GREY)};
	int		color[5] = {(GREY)};

	i = 0;
	get_correct_letter(to_find, input, color, ascii);
	while (input[i])
	{
		if (color[i] != GREEN)
			get_yellow_letter(to_find, color, input[i], ascii, i);
		i++;
	}
	i = 0;
	while (input[i])
	{
		if (color[i] == GREY)
			print_gray(input[i]);
		if (color[i] == GREEN)
			print_green(input[i]);
		if (color[i] == YELLOW)
			print_yellow(input[i]);
		++i;
	}
}
