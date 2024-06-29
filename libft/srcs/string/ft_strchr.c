/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 03:21:18 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/29 06:35:50 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strn_chr(const char *s, int c)
{
	int		i;
	char	cc;

	cc = c;
	i = 0;
	while (s[i] != cc && s[i])
		i++;
	if (s[i] == cc)
		return ((char *)s + i);
	else
		return (0);
}
