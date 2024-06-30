/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_random_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:16:17 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/30 06:22:22 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <time.h>
#include <stdlib.h>

int	get_random_word(t_vector *words)
{
	int	rand_val;

	srand(time(NULL));
	rand_val = rand() % (words->len);
	return (rand_val);
}
