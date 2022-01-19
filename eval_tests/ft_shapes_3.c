/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:00 by mrantil           #+#    #+#             */
/*   Updated: 2022/01/19 10:37:10 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_errorfd(void)
{
	ft_putstr("error\n");
	return (1);
}

int	ft_errormain(char *copy_of_file)
{
	ft_putstr("error\n");
	ft_strdel(&copy_of_file);
	return (1);
}

int	*ft_small_map(char **tetrominos, int i, int x, int add)
{
	static int	square[4];

	if (i == 2)
		add = -2;
	if (i == 3)
		add = -1;
	square[0] = 0;
	square[1] = 1;
	square[2] = 5 + add;
	square[3] = 6 + add;
	i = 0;
	while (tetrominos[x][i] == '.' || tetrominos[x][i] == '\n')
		i++;
	if (tetrominos[x][i] == '2' && tetrominos[x][i + 1] == '2'
		&& tetrominos[x][i + 5] == '2' && tetrominos[x][i + 6] == '2')
		return (square);
	else
		return (ft_i(tetrominos, i, x, add));
}

int	*ft_t_2(char **tetrominos, int i, int x, int add)
{
	static int	vertical_t_left[4];
	static int	vertical_t_right[4];

	vertical_t_left[0] = 1;
	vertical_t_left[1] = 5 + add;
	vertical_t_left[2] = 6 + add;
	vertical_t_left[3] = 11 + add * 2;
	vertical_t_right[0] = 0;
	vertical_t_right[1] = 5 + add;
	vertical_t_right[2] = 6 + add;
	vertical_t_right[3] = 10 + add * 2;
	if (tetrominos[x][i] == '1' && tetrominos[x][i + 4] == '1'
		&& tetrominos[x][i + 5] == '3' && tetrominos[x][i + 10] == '1')
		return (vertical_t_left);
	else if (tetrominos[x][i] == '1' && tetrominos[x][i + 5] == '3'
		&& tetrominos[x][i + 6] == '1' && tetrominos[x][i + 10] == '1')
		return (vertical_t_right);
	else
		return (NULL);
}