/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_random_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:16:17 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/29 06:20:14 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"
#include <time.h>

int	get_random_word(t_vector *words)
{
	int	rand_val;

	srand(time(NULL));
	rand_val = rand() % words->len;
	return (rand_val);
}
