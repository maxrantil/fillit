/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:37:45 by llonnrot          #+#    #+#             */
/*   Updated: 2022/01/19 13:56:29 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include <fcntl.h>
# include "libft/libft.h"

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
	ssize_t		readret;
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

int		ft_verify_pieces(char **tetrominos);
int		ft_verify_pieces_two(char **tetrominos);
void	ft_map_generator(char **tetrominos);
int		ft_place_to_map(int x, int i, char *map, char **tetrominos);
int		*ft_what_shape(char **tetrominos, char *map, int x);
char	*ft_clear_last(char *map, int c);
int		*ft_t_2(char **tetrominos, int i, int x, int add);
int		*ft_l_2(char **tetrominos, int i, int x, int add);
int		*ft_small_map(char **tetrominos, int i, int x, int add);
int		*ft_i(char **tetrominos, int i, int x, int add);
int		ft_side_total_six(char *tm);
int		ft_side_total_eight(char *tm);
int		ft_errormain(char *copy_of_file);
int		ft_errorfd(void);
int		ft_no_dots(char *copy_of_file);
void	ft_free_read(t_r_var pni);

#endif
