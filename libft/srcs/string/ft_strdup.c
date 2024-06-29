/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:57:48 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/27 01:51:00 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "mem.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t		len;
	char		*copy;

	len = ft_strlen(s);
	copy = malloc(sizeof (char) * (len + 1));
	if (copy == 0)
		return (0);
	ft_memcpy(copy, s, len + 1);
	return (copy);
}
