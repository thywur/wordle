/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strn2join_free_s1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:14:27 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/27 03:15:55 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include <stdlib.h>

char	*ft_strn2join_free_s1(char *s1, char *s2, size_t n1, size_t n2)
{
	char	*str;
	size_t	l_s1;

	l_s1 = 0;
	if (s1)
		l_s1 = n2;
	str = malloc(sizeof(char) * (l_s1 + n1 + 1));
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(str, s1, l_s1);
	ft_memcpy(str + l_s1, s2, n1);
	str[l_s1 + n1] = '\0';
	if (s1 != NULL)
		free(s1);
	return (str);
}
