/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_pieces_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:49:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/01/17 19:49:51 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_side_total_eight(char *tm)
{
	int	i;

	i = 0;
	while (tm[i] != '\0')
	{
		if (tm[i] == '2' || tm[i] == '.'
			|| tm[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_side_total_six(char *tm)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tm[i] != '\0')
	{
		if (tm[i] == '2')
			count++;
		else if (tm[i] == '3')
			count = 2;
		if (count == 2)
			return (1);
		i++;
	}
	return (0);
}

int	ft_sides_check(t_ints sides, char *tm)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (sides.side_total == 6 || sides.side_total == 8)
	{
		if (sides.side_total == 8)
			return (ft_side_total_eight(tm));
		else if (sides.side_total == 6)
			return (ft_side_total_six(tm));
	}
	return (0);
}

int	ft_check_3(int x, int y, t_ints sides, char **tm)
{
	while (tm[x][y] != '\0')
	{
		if (tm[x][y] == '#')
		{
			if (tm[x][y + 1] == '#' || tm[x][y + 1] == '1'
				|| tm[x][y + 1] == '2' || tm[x][y + 1] == '3')
				sides.sides++;
			if (tm[x][y - 1] == '#' || tm[x][y - 1] == '1'
				|| tm[x][y - 1] == '2' || tm[x][y - 1] == '3')
				sides.sides++;
			if (tm[x][y - 5] == '#' || tm[x][y - 5] == '1'
				|| tm[x][y - 5] == '2' || tm[x][y - 5] == '3')
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

int	ft_check_2(int x, int y, t_ints sides, char **tm)
{
	while (tm[x][y] != '\0')
	{
		if (tm[x][y] == '#')
		{
			if (ft_strlen(&tm[x][y]) <= 4)
				return (ft_check_3(x, y, sides, tm));
			if (tm[x][y + 1] == '#' || tm[x][y + 1] == '1'
				|| tm[x][y + 1] == '2' || tm[x][y + 1] == '3')
				sides.sides++;
			if (y != 0 && (tm[x][y - 1] == '#' || tm[x][y - 1] == '1'
				|| tm[x][y - 1] == '2' || tm[x][y - 1] == '3'))
				sides.sides++;
			if (tm[x][y + 5] == '#' || tm[x][y + 5] == '1'
				|| tm[x][y + 5] == '2' || tm[x][y + 5] == '3')
				sides.sides++;
			if (y > 4 && (tm[x][y - 5] == '#'
				|| tm[x][y - 5] == '1'
				|| tm[x][y - 5] == '2' || tm[x][y - 5] == '3'))
				sides.sides++;
			if (sides.sides == 0) // same, remove this for norm
				return (-1);
			tm[x][y] = sides.sides + '0';
			sides.side_total = sides.side_total + sides.sides;
		}
		sides.sides = 0;
		y++;
	}
	return (sides.side_total);
}

int	ft_check(int x, int y, t_ints sides, char **tm)
{
	while (tm[x][y] != '\0')
	{
		if (tm[x][y] == '#')
		{
			if (ft_strlen(&tm[x][y]) <= 4 || y < 5)
				return (ft_check_2(x, y, sides, tm));
			if (tm[x][y + 1] == '#' || tm[x][y + 1] == '1' || tm[x][y + 1] == '2' || tm[x][y + 1] == '3')
				sides.sides++;
			if (tm[x][y - 1] == '#' || tm[x][y - 1] == '1'
				|| tm[x][y - 1] == '2' || tm[x][y - 1] == '3')
				sides.sides++;
			if (tm[x][y + 5] == '#' || tm[x][y + 5] == '1'
				|| tm[x][y + 5] == '2' || tm[x][y + 5] == '3')
				sides.sides++;
			if (tm[x][y - 5] == '#' || tm[x][y - 5] == '1'
				|| tm[x][y - 5] == '2' || tm[x][y - 5] == '3')
				sides.sides++;
			if (sides.sides == 0) // maybe get rid of this to pass norm
				return (-1);
			tm[x][y] = sides.sides + '0';
			sides.side_total = sides.side_total + sides.sides;
		}
		sides.sides = 0;
		y++; // try y++ in while condition and remove this line;
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
