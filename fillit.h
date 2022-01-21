/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:37:45 by llonnrot          #+#    #+#             */
/*   Updated: 2022/01/21 16:04:26 by mrantil          ###   ########.fr       */
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
	int			sides;
	int			side_total;
	int			i;
	int			read_ret;
	size_t		t;
	size_t		len;
	ssize_t		readret;
	char		*tm_buf;
	char		letter;
}				t_struct;

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

#endif
