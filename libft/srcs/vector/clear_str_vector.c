/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_str_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:48:00 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/29 06:48:45 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

void	clear_str_vector(t_vector *vector)
{
	size_t	i;
	char	**s;

	i = 0;
	while (i < vector->len)
	{
		s = at_vector(vector, i);
		free(*s);
		++i;
	}
	clear_vector(vector);
}
