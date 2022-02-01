/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:46:46 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/01 17:52:35 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	*tm_z_2(char **tetrominos, int i, int x, int add)
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
		return (tm_l_1(tetrominos, i, x, add));
}

static int	*tm_z_1(char **tetrominos, int i, int x, int add)
{
	static int	z_vertical_left[4];
	static int	z_vertical_right[4];

	z_vertical_left[0] = 0;
	z_vertical_left[1] = 5 + add;
	z_vertical_left[2] = 6 + add;
	z_vertical_left[3] = 11 + add * 2;
	z_vertical_right[0] = 1;
	z_vertical_right[1] = 5 + add;
	z_vertical_right[2] = 6 + add;
	z_vertical_right[3] = 10 + add * 2;
	if (tetrominos[x][i] == '1' && tetrominos[x][i + 5] == '2'
		&& tetrominos[x][i + 6] == '2' && tetrominos[x][i + 11] == '1')
		return (z_vertical_left);
	else if (tetrominos[x][i] == '1' && tetrominos[x][i + 4] == '2'
		&& tetrominos[x][i + 5] == '2' && tetrominos[x][i + 9] == '1')
		return (z_vertical_right);
	else
		return (tm_z_2(tetrominos, i, x, add));
}

static int	*tm_i(char **tetrominos, int i, int x, int add)
{
	static int	vertical_i[4];
	static int	horizontal_i[4];

	vertical_i[0] = 0;
	vertical_i[1] = 5 + add;
	vertical_i[2] = 10 + add * 2;
	vertical_i[3] = 15 + add * 3;
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
		return (tm_z_1(tetrominos, i, x, add));
}

static int	*small_map(char **tetrominos, int i, int x, int add)
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
		return (tm_i(tetrominos, i, x, add));
}

int	*what_shape(t_char_ptr ptr, int x)
{
	int			i;
	int			add;
	static int	square[4];

	i = 0;
	add = 0;
	while (ptr.map[i] != '\n')
		i++;
	if (i < 4)
		return (small_map(ptr.tm, i, x, add));
	if (i > 4)
		add = i - 4;
	square[0] = 0;
	square[1] = 1;
	square[2] = 5 + add;
	square[3] = 6 + add;
	i = 0;
	while (ptr.tm[x][i] == '.' || ptr.tm[x][i] == '\n')
		i++;
	if (ptr.tm[x][i] == '2' && ptr.tm[x][i + 1] == '2'
		&& ptr.tm[x][i + 5] == '2' && ptr.tm[x][i + 6] == '2')
		return (square);
	else
		return (tm_i(ptr.tm, i, x, add));
}
