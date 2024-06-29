/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:32:57 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/27 03:16:57 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "mem.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = ft_calloc(sizeof(t_list), 1);
	if (element == NULL)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}
