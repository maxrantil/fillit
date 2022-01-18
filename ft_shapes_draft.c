/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes_draft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:46:46 by mrantil           #+#    #+#             */
/*   Updated: 2022/01/18 16:46:50 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*ft_l_1(char **tetrominos, int i, int x, int add)
{
	static int	l_1r_2d[4];
	static int	l_1l_2u[4];

	l_1r_2d[0] = 0;
	l_1r_2d[1] = 1;
	l_1r_2d[2] = 5 + add;
	l_1r_2d[3] = 10 + add + add;
	l_1l_2u[0] = 1;
	l_1l_2u[1] = 6 + add;
	l_1l_2u[2] = 10 + add + add;
	l_1l_2u[3] = 11 + add + add;
	if (tetrominos[x][i] == '2' && tetrominos[x][i + 1] == '1'
		&& tetrominos[x][i + 5] == '2' && tetrominos[x][i + 10] == '1')
		return (l_1r_2d);
	else if (tetrominos[x][i] == '1' && tetrominos[x][i + 5] == '2'
		&& tetrominos[x][i + 9] == '1' && tetrominos[x][i + 10] == '2')
		return (l_1l_2u);
	else
		return (ft_l_2(tetrominos, i, x, add));
}

int	*ft_z_2(char **tetrominos, int i, int x, int add)
{
	static int	z_horizontal_left[4];
	static int	z_horizontal_right[4];

	z_horizontal_left[0] = 0;
	z_horizontal_left[1] = 1;
	z_horizontal_left[2] = 6 + add;
	z_horizontal_left[3] = 7 + add;
	z_horizontal_right[0] = 1;
	z_horizontal_right[1] = 2;
	z_horizontal_right[2] = 5 + add;
	z_horizontal_right[3] = 6 + add;
	if (tetrominos[x][i] == '1' && tetrominos[x][i + 1] == '2'
		&& tetrominos[x][i + 6] == '2' && tetrominos[x][i + 7] == '1')
		return (z_horizontal_left);
	else if (tetrominos[x][i] == '2' && tetrominos[x][i + 1] == '1'
		&& tetrominos[x][i + 4] == '1' && tetrominos[x][i + 5] == '2')
		return (z_horizontal_right);
	else
		return (ft_l_1(tetrominos, i, x, add));
}

int	*ft_z_1(char **tetrominos, int i, int x, int add)
{
	static int	z_vertical_left[4];
	static int	z_vertical_right[4];

	z_vertical_left[0] = 0;
	z_vertical_left[1] = 5 + add;
	z_vertical_left[2] = 6 + add;
	z_vertical_left[3] = 11 + add + add;
	z_vertical_right[0] = 1;
	z_vertical_right[1] = 5 + add;
	z_vertical_right[2] = 6 + add;
	z_vertical_right[3] = 10 + add + add;
	if (tetrominos[x][i] == '1' && tetrominos[x][i + 5] == '2'
		&& tetrominos[x][i + 6] == '2' && tetrominos[x][i + 11] == '1')
		return (z_vertical_left);
	else if (tetrominos[x][i] == '1' && tetrominos[x][i + 4] == '2'
		&& tetrominos[x][i + 5] == '2' && tetrominos[x][i + 9] == '1')
		return (z_vertical_right);
	else
		return (ft_z_2(tetrominos, i, x, add));
}

int	*ft_i(char **tetrominos, int i, int x, int add)
{
	static int	vertical_i[4];
	static int	horizontal_i[4];

	vertical_i[0] = 0;
	vertical_i[1] = 5 + add;
	vertical_i[2] = 10 + add + add;
	vertical_i[3] = 15 + add + (add * 2);
	horizontal_i[0] = 0;
	horizontal_i[1] = 1;
	horizontal_i[2] = 2;
	horizontal_i[3] = 3;
	if (tetrominos[x][i] == '1' && tetrominos[x][i + 5] == '2'
		&& tetrominos[x][i + 10] == '2' && tetrominos[x][i + 15] == '1')
		return (vertical_i);
	else if (tetrominos[x][i] == '1' && tetrominos[x][i + 1] == '2'
		&& tetrominos[x][i + 2] == '2' && tetrominos[x][i + 3] == '1')
		return (horizontal_i);
	else
		return (ft_z_1(tetrominos, i, x, add));
}

int	*ft_what_shape(char **tetrominos, char *map, int x)
{
	int			i;
	int			add;
	static int	square[4];

	i = 0;
	add = 0;
	while (map[i] != '\n')
		i++;
	if (i < 4)
		return (ft_small_square(tetrominos, i, x, add));
	if (i > 4)
		add = i - 4;
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
