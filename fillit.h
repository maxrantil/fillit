/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:37:45 by llonnrot          #+#    #+#             */
/*   Updated: 2022/01/18 13:19:51 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"
//#include <stdio.h> // take away later

typedef struct s_index0
{
	int			x;
	int			y;
	size_t		i;
	size_t		len;
}				t_ints0;

typedef struct s_read
{
	char		*buffer;
	char		*temp2;
	char		*temp3;
	int			readret;
	int			count;
}				t_r_var;

typedef struct s_sides
{
	int			sides;
	int			side_total;
}				t_ints;

typedef struct s_index
{
	int			x;
	int			y;
	int			i;
}				t_ints3;

typedef struct s_ll
{
	int			len;
	char		letter;
}				t_ints4;

int		ft_read_file(int fd, char **copy_of_file);
int		ft_verify_file(char *copy_of_file, char	**tetrominos);
char	**ft_malloc_tetrominos(int count);
void	ft_divide_pieces(char *pieces, char **tetrominos);
int		ft_verify_pieces(char **tetrominos);
int		ft_verify_pieces_two(char **tetrominos);
void	ft_convert_pieces(char **tetrominos);
void	ft_map_generator(char **tetrominos);
int		ft_place_to_map(int x, int i, char *map, char **tetrominos);
int		*ft_what_shape(char **tetrominos, char *map, int x);
size_t	ft_count_c(char *s, int c);
char	*ft_clear_last(char *map, int c);
size_t	ft_get_nl(char *map, int a);
char	*ft_enlarge_map(char *map);
int		*ft_t_2(char **tetrominos, int i, int x, int add);
int		*ft_l_2(char **tetrominos, int i, int x, int add);
int		*ft_small_square(char **tetrominos, int i, int x, int add);
int		*ft_i(char **tetrominos, int i, int x, int add);
int		ft_side_total_six(char *tm);
int		ft_side_total_eight(char *tm);

#endif
