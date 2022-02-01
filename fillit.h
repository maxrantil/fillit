/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:37:45 by llonnrot          #+#    #+#             */
/*   Updated: 2022/02/01 14:34:51 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_struct
{
	int			x;
	int			y;
	int			count;
	int			i;
	size_t		t;
	size_t		len;
	char		letter;
}				t_struct;

//error handling
int		error_main(char *copy_of_file);
int		error_fd(void);
int		no_dots(char *copy_of_file);

//read, verify file, malloc & set
int		read_file(int count, int fd, char **copy_of_file);
char	**malloc_tm(int count, char *tm_buf);

//verify blocks
int		verify_pieces(char	**tetrominos);
int		verify_pieces_one(int y, int x, char **tetrominos);
int		verify_pieces_two(int x, int y, int sides_total, char **tm);

//generate map
void	map_generator(int i, int x, int y, char **tetrominos);

int		ft_place_to_map(int x, int i, char *map, char **tetrominos);
int		*ft_what_shape(char **tetrominos, char *map, int x);
int		*ft_t_2(char **tetrominos, int i, int x, int add);
int		*ft_l_2(char **tetrominos, int i, int x, int add);
int		*ft_small_map(char **tetrominos, int i, int x, int add);
int		*ft_i(char **tetrominos, int i, int x, int add);
int		ft_side_total_six(char *tm);
int		ft_side_total_eight(char *tm);



#endif
