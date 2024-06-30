/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 03:40:06 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/30 06:12:22 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "wordle.h"
#include <unistd.h>

int	main(void)
{
	t_vector	words;

	init_vector(&words, sizeof(char *));
	if (parse_words(&words) == -1
		|| game_loop(&words) == -1)
	{
		clear_str_vector(&words);
		return (1);
	}
	clear_str_vector(&words);
	return (0);
}
