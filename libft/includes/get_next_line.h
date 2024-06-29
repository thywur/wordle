/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:46:04 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/29 06:25:27 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_buff
{
	char	buff[BUFFER_SIZE];
	size_t	start;
	size_t	end;
}	t_buff;

char	*get_next_line(int fd);
char	*ft_strn2join_free_s1(char *s1, char *s2, size_t n1, size_t n2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strn_chr(const char *s, int c, size_t n);

#endif
