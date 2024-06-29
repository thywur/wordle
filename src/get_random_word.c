/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_random_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:16:17 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/29 12:10:38 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"
#include <time.h>
#include <stdlib.h>

int	get_random_word(t_vector *words)
{
	int	rand_val;

	srand(time(NULL));
	rand_val = rand() % (words->len - 1);
	return (rand_val);
}
