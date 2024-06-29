/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:46:05 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/29 06:46:45 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"
#include <stdio.h>

int	print_yellow(char *str)
{
	if (printf(BHYEL) == -1
		|| printf("%s\n", str) == -1
		|| printf(RESET) == -1)
		return (-1);
	return (0);
}

int	print_green(char *str)
{
	if (printf(BHGRN) == -1
		|| printf("%s\n", str) == -1
		|| printf(RESET) == -1)
		return (-1);
	return (0);
}
