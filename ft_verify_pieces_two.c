/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_pieces_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilot <pilot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:16:19 by llonnrot          #+#    #+#             */
/*   Updated: 2022/01/12 11:37:25 by pilot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_side_total_eight(char *tetrominos)
{
	int	i;

	i = 0;
	while (tetrominos[i] != '\0')
	{
		if (tetrominos[i] == '2' || tetrominos[i] == '.'
			|| tetrominos[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_side_total_six(char *tetrominos)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tetrominos[i] != '\0')
	{
		if (tetrominos[i] == '2')
			count++;
		else if (tetrominos[i] == '3')
			count = 2;
		if (count == 2)
			return (1);
		i++;
	}
	return (0);
}

int	ft_sides_check(t_ints sides, char *tetrominos)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (sides.side_total == 6 || sides.side_total == 8)
	{
		if (sides.side_total == 8)
			return (ft_side_total_eight(tetrominos));
		else if (sides.side_total == 6)
			return (ft_side_total_six(tetrominos));
	}
	return (0);
}

int	ft_check_3(int x, int y, t_ints sides, char **tetrominos)
{
	while (tetrominos[x][y] != '\0')
	{
		if (tetrominos[x][y] == '#')
		{
			if (tetrominos[x][y + 1] == '#' || tetrominos[x][y + 1] == '1'
				|| tetrominos[x][y + 1] == '2' || tetrominos[x][y + 1] == '3')
				sides.sides++;
			if (tetrominos[x][y - 1] == '#' || tetrominos[x][y - 1] == '1'
				|| tetrominos[x][y - 1] == '2' || tetrominos[x][y - 1] == '3')
				sides.sides++;
			if (tetrominos[x][y - 5] == '#' || tetrominos[x][y - 5] == '1'
				|| tetrominos[x][y - 5] == '2' || tetrominos[x][y - 5] == '3')
				sides.sides++;
			if (sides.sides == 0)
				return (-1);
			tetrominos[x][y] = sides.sides + '0';
			sides.side_total = sides.side_total + sides.sides;
		}
		sides.sides = 0;
		y++;
	}
	return (sides.side_total);
}

int	ft_check_2(int x, int y, t_ints sides, char **tetrominos)
{
	while (tetrominos[x][y] != '\0')
	{
		if (tetrominos[x][y] == '#')
		{
			if (ft_strlen(&tetrominos[x][y]) <= 4)
				return (ft_check_3(x, y, sides, tetrominos));
			if (tetrominos[x][y + 1] == '#' || tetrominos[x][y + 1] == '1'
				|| tetrominos[x][y + 1] == '2' || tetrominos[x][y + 1] == '3')
				sides.sides++;
			if (y != 0 && (tetrominos[x][y - 1] == '#' || tetrominos[x][y - 1] == '1'
				|| tetrominos[x][y - 1] == '2' || tetrominos[x][y - 1] == '3'))
				sides.sides++;
			if (tetrominos[x][y + 5] == '#' || tetrominos[x][y + 5] == '1'
				|| tetrominos[x][y + 5] == '2' || tetrominos[x][y + 5] == '3')
				sides.sides++;
			if (y > 4 && (tetrominos[x][y - 5] == '#' || tetrominos[x][y - 5] == '1'
				|| tetrominos[x][y - 5] == '2' || tetrominos[x][y - 5] == '3'))
				sides.sides++;
			if (sides.sides == 0) // same, remove this for norm
				return (-1);
			tetrominos[x][y] = sides.sides + '0';
			sides.side_total = sides.side_total + sides.sides;
		}
		sides.sides = 0;
		y++;
	}
	return (sides.side_total);
}

int	ft_check(int x, int y, t_ints sides, char **tetrominos)
{
	while (tetrominos[x][y] != '\0')
	{
		if (tetrominos[x][y] == '#')
		{
			if (ft_strlen(&tetrominos[x][y]) <= 4 || y < 5)
				return (ft_check_2(x, y, sides, tetrominos));
			if (tetrominos[x][y + 1] == '#' || tetrominos[x][y + 1] == '1'
				|| tetrominos[x][y + 1] == '2' || tetrominos[x][y + 1] == '3')
				sides.sides++;
			if (tetrominos[x][y - 1] == '#' || tetrominos[x][y - 1] == '1'
				|| tetrominos[x][y - 1] == '2' || tetrominos[x][y - 1] == '3')
				sides.sides++;
			if (tetrominos[x][y + 5] == '#' || tetrominos[x][y + 5] == '1'
				|| tetrominos[x][y + 5] == '2' || tetrominos[x][y + 5] == '3')
				sides.sides++;
			if (tetrominos[x][y - 5] == '#' || tetrominos[x][y - 5] == '1'
				|| tetrominos[x][y - 5] == '2' || tetrominos[x][y - 5] == '3')
				sides.sides++;
			if (sides.sides == 0) // maybe get rid of this to pass norm
				return (-1);
			tetrominos[x][y] = sides.sides + '0';
			sides.side_total = sides.side_total + sides.sides;
		}
		sides.sides = 0;
		y++; // try y++ in while condition and remove this line;
	}
	return (sides.side_total);
}

int	ft_verify_pieces_two(char **tetrominos)
{
	t_ints	sides;
	int		x;
	int		y;

	x = 0;
	y = 0;
	sides.sides = 0;
	sides.side_total = 0;
	while (tetrominos[x][0] != '\0')
	{
		sides.side_total = ft_check(x, y, sides, tetrominos);
		if (sides.side_total == -1)
			return (-1);
		if (ft_sides_check(sides, tetrominos[x]) == 1)
			sides.side_total = 0;
		else
			return (-1);
		x++;
		y = 0;
	}
	return (0);
}
