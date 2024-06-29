/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 05:34:16 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/29 12:47:54 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H

# define BHYEL "\e[1;93m"
# define BHGRN "\e[1;92m"
# define BHGRY "\e[1;90m"
# define RESET "\033[0m"
# define WORDS_PATH "./words.txt"

# include <vector.h>

int	parse_words(t_vector *words);
int	get_random_word(t_vector *words);
int	game_loop(t_vector *words);
int	print_yellow(char c);
int	print_green(char c);
int	print_gray(char c);

#endif
