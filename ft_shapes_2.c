/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:59:45 by mrantil           #+#    #+#             */
/*   Updated: 2022/01/18 16:59:49 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*ft_t_1(char **tetrominos, int i, int x, int add)
{
	static int	t[4];
	static int	flipped_t[4];

	t[0] = 0;
	t[1] = 1;
	t[2] = 2;
	t[3] = 6 + add;
	flipped_t[0] = 1;
	flipped_t[1] = 5 + add;
	flipped_t[2] = 6 + add;
	flipped_t[3] = 7 + add;
	if (tetrominos[x][i] == '1' && tetrominos[x][i + 1] == '3'
		&& tetrominos[x][i + 2] == '1' && tetrominos[x][i + 6] == '1')
		return (t);
	else if (tetrominos[x][i] == '1' && tetrominos[x][i + 4] == '1'
		&& tetrominos[x][i + 5] == '3' && tetrominos[x][i + 6] == '1')
		return (flipped_t);
	else
		return (ft_t_2(tetrominos, i, x, add));
}

int	*ft_l_4(char **tetrominos, int i, int x, int add)
{
	static int	l_2r_1u[4];
	static int	l_2l_1d[4];

	l_2r_1u[0] = 0;
	l_2r_1u[1] = 5 + add;
	l_2r_1u[2] = 6 + add;
	l_2r_1u[3] = 7 + add;
	l_2l_1d[0] = 0;
	l_2l_1d[1] = 1;
	l_2l_1d[2] = 2;
	l_2l_1d[3] = 7 + add;
	if (tetrominos[x][i] == '1' && tetrominos[x][i + 5] == '2'
		&& tetrominos[x][i + 6] == '2' && tetrominos[x][i + 7] == '1')
		return (l_2r_1u);
	else if (tetrominos[x][i] == '1' && tetrominos[x][i + 1] == '2'
		&& tetrominos[x][i + 2] == '2' && tetrominos[x][i + 7] == '1')
		return (l_2l_1d);
	else
		return (ft_t_1(tetrominos, i, x, add));
}

int	*ft_l_3(char **tetrominos, int i, int x, int add)
{
	static int	l_2r_1d[4];
	static int	l_2l_1u[4];

	l_2r_1d[0] = 0;
	l_2r_1d[1] = 1;
	l_2r_1d[2] = 2;
	l_2r_1d[3] = 5 + add;
	l_2l_1u[0] = 2;
	l_2l_1u[1] = 5 + add;
	l_2l_1u[2] = 6 + add;
	l_2l_1u[3] = 7 + add;
	if (tetrominos[x][i] == '2' && tetrominos[x][i + 1] == '2'
		&& tetrominos[x][i + 2] == '1' && tetrominos[x][i + 5] == '1')
		return (l_2r_1d);
	else if (tetrominos[x][i] == '1' && tetrominos[x][i + 3] == '1'
		&& tetrominos[x][i + 4] == '2' && tetrominos[x][i + 5] == '2')
		return (l_2l_1u);
	else
		return (ft_l_4(tetrominos, i, x, add));
}

int	*ft_l_2(char **tetrominos, int i, int x, int add)
{
	static int	l_1r_2u[4];
	static int	l_1l_2d[4];

	l_1r_2u[0] = 0;
	l_1r_2u[1] = 5 + add;
	l_1r_2u[2] = 10 + add + add;
	l_1r_2u[3] = 11 + add + add;
	l_1l_2d[0] = 0;
	l_1l_2d[1] = 1;
	l_1l_2d[2] = 6 + add;
	l_1l_2d[3] = 11 + add + add;
	if (tetrominos[x][i] == '1' && tetrominos[x][i + 5] == '2'
		&& tetrominos[x][i + 10] == '2' && tetrominos[x][i + 11] == '1')
		return (l_1r_2u);
	else if (tetrominos[x][i] == '1' && tetrominos[x][i + 1] == '2'
		&& tetrominos[x][i + 6] == '2' && tetrominos[x][i + 11] == '1')
		return (l_1l_2d);
	else
		return (ft_l_3(tetrominos, i, x, add));
}
