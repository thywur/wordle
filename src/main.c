/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 03:40:06 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/29 12:47:45 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "wordle.h"
#include <unistd.h>

int	main(void)
{
	t_vector	words;

	if (parse_words(&words) == -1
		|| game_loop(&words) == -1)
	{
		clear_str_vector(&words);
		return (-1);
	}
	clear_str_vector(&words);
	return (0);
}

/*
void print_vec(t_vector *vector)
{
	size_t i;

	i = 0;
	char **s;
	while (i < vector->len)
	{
		s = at_vector(vector, i);
		printf("%s", *s);
		++i;
	}
}*/
