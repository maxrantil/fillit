/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_pieces_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:49:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/01/18 15:44:01 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_cn(int x, int y, char **tm)
{
	if (tm[x][y] == '#' || tm[x][y] == '1'
		|| tm[x][y] == '2' || tm[x][y] == '3')
		return (1);
	else
		return (0);
}

int	ft_sides_check(t_ints sides, char *tm)
{
	if (sides.side_total == 6 || sides.side_total == 8)
	{
		if (sides.side_total == 8)
			return (ft_side_total_eight(tm));
		else if (sides.side_total == 6)
			return (ft_side_total_six(tm));
	}
	return (0);
}

int	ft_check(int x, int y, t_ints sides, char **tm)
{
	while (tm[x][y] != '\0')
	{
		if (tm[x][y] == '#')
		{
			if (ft_cn(x, y + 1, tm) == 1)
				sides.sides++;
			if (y != 0 && (ft_cn(x, y - 1, tm) == 1))
				sides.sides++;
			if (ft_strlen(&tm[x][y]) >= 4 && ft_cn(x, y + 5, tm) == 1)
				sides.sides++;
			if (y > 4 && (ft_cn(x, y - 5, tm) == 1))
				sides.sides++;
			if (sides.sides == 0)
				return (-1);
			tm[x][y] = sides.sides + '0';
			sides.side_total = sides.side_total + sides.sides;
		}
		sides.sides = 0;
		y++;
	}
	return (sides.side_total);
}

int	ft_verify_pieces_two(char **tm)
{
	t_ints	sides;
	int		x;
	int		y;

	x = 0;
	y = 0;
	sides.sides = 0;
	sides.side_total = 0;
	while (tm[x][0] != '\0')
	{
		sides.side_total = ft_check(x, y, sides, tm);
		if (sides.side_total == -1)
			return (-1);
		if (ft_sides_check(sides, tm[x]) == 1)
			sides.side_total = 0;
		else
			return (-1);
		x++;
		y = 0;
	}
	return (0);
}

int	ft_verify_pieces(char **tm)
{
	t_ints3	ix;

	ix.i = 0;
	ix.y = 0;
	ix.x = 0;
	while (tm[ix.x][0] != '\0')
	{
		while (tm[ix.x][ix.y] != '\0')
		{
			if (tm[ix.x][ix.y] != '.' && tm[ix.x][ix.y] != '#'
				&& tm[ix.x][ix.y] != '\n')
				return (-1);
			ix.y++;
		}
		if (tm[ix.x][4] != '\n' || tm[ix.x][9] != '\n' || tm[ix.x][14] != '\n'
			|| tm[ix.x][19] != '\0')
			return (-1);
		ix.y = 0;
		ix.x++;
	}
	return (0);
}
