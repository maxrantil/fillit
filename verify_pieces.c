/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:49:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/01 14:01:45 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_cn(int x, int y, char **tm)
{
	if (tm[x][y] == '#' || tm[x][y] == '1'
		|| tm[x][y] == '2' || tm[x][y] == '3')
		return (1);
	else
		return (0);
}

static int	ft_sides_check(int sides_total, char *tm)
{
	if (sides_total == 6 || sides_total == 8)
	{
		if (sides_total == 8)
			return (ft_side_total_eight(tm));
		else if (sides_total == 6)
			return (ft_side_total_six(tm));
	}
	return (0);
}

static int	ft_check(int sides, int x, int y, char **tm)
{
	int	sides_total;

	sides_total = 0;
	while (tm[x][y] != '\0')
	{
		if (tm[x][y] == '#')
		{
			if (ft_cn(x, y + 1, tm) == 1)
				sides++;
			if (y != 0 && (ft_cn(x, y - 1, tm) == 1))
				sides++;
			if (ft_strlen(&tm[x][y]) >= 4 && ft_cn(x, y + 5, tm) == 1)
				sides++;
			if (y > 4 && (ft_cn(x, y - 5, tm) == 1))
				sides++;
			if (sides == 0)
				return (-1);
			tm[x][y] = sides + '0';
			sides_total = sides_total + sides;
		}
		sides = 0;
		y++;
	}
	return (sides_total);
}

int	verify_pieces_two(int x, int y, int sides_total, char **tm)
{
	while (tm[x][0] != '\0')
	{
		sides_total = ft_check(0, x, y, tm);
		if (sides_total == -1)
			return (-1);
		if (ft_sides_check(sides_total, tm[x]) == 1)
			sides_total = 0;
		else
			return (-1);
		x++;
		y = 0;
	}
	return (0);
}

int	verify_pieces_one(int y, int x, char **tm)
{
	if (ft_strlen(tm[x]) != 19)
		return (-1);
	while (tm[x][0] != '\0')
	{
		while (tm[x][y] != '\0')
		{
			if (tm[x][y] != '.' && tm[x][y] != '#'
				&& tm[x][y] != '\n')
				return (-1);
			y++;
		}
		if (tm[x][4] != '\n' || tm[x][9] != '\n' || tm[x][14] != '\n'
			|| tm[x][19] != '\0')
			return (-1);
		y = 0;
		x++;
	}
	return (0);
}
