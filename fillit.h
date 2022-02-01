/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:37:45 by llonnrot          #+#    #+#             */
/*   Updated: 2022/02/01 17:48:44 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_struct
{
	size_t		len;
	char		letter;
}				t_struct;

typedef struct s_char_ptr
{
	char		*map;
	char		**tm;
}				t_char_ptr;

//error handling
int		error_main(char *copy_of_file);
int		error_fd(void);
int		no_dots(char *copy_of_file);

//read, verify file, malloc & set
int		read_file(int count, int fd, char **copy_of_file);
char	**malloc_tm(int i, int count, char *tm_buf);

//verify blocks
int		verify_pieces(char	**tetrominos);
int		verify_pieces_one(int y, int x, char **tetrominos);
int		verify_pieces_two(int x, int y, int sides_total, char **tm);
int		side_total_six(char *tm);
int		side_total_eight(char *tm);

//generate map & place to map
void	map_generator(int i, int x, int y, char **tm);
int		place_to_map(int i, int x, t_char_ptr ptr, int *ret);
int		*what_shape(t_char_ptr ptr, int x);
int		*tm_l_1(char **tetrominos, int i, int x, int add);
int		*tm_t_2(char **tetrominos, int i, int x, int add);

#endif
