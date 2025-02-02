/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 05:34:16 by lespenel          #+#    #+#             */
/*   Updated: 2024/06/30 11:55:01 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H

# define BHYEL "\e[1;93m"
# define BHGRN "\e[1;92m"
# define BHGRY "\e[1;90m"
# define RESET "\033[0m"
# define GREY 0
# define GREEN 1
# define YELLOW 2
# define WORDS_PATH "./words.txt"

# include <vector.h>

int		parse_words(t_vector *words);
int		get_random_word(t_vector *words);
int		game_loop(t_vector *words);
char	*get_input(t_vector *words, int *guesses);
int		print_yellow(char c);
int		print_green(char c);
int		print_gray(char c);

#endif
