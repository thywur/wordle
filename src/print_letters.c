/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:46:05 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/29 12:56:03 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"
#include <stdio.h>

int	print_yellow(char c)
{
	if (printf(BHYEL) == -1
		|| printf("%c", c) == -1
		|| printf(RESET) == -1)
		return (-1);
	return (0);
}

int	print_green(char c)
{
	if (printf(BHGRN) == -1
		|| printf("%c", c) == -1
		|| printf(RESET) == -1)
		return (-1);
	return (0);
}

int	print_gray(char c)
{
	if (printf(BHGRY) == -1
		|| printf("%c", c) == -1
		|| printf(RESET) == -1)
		return (-1);
	return (0);
}
