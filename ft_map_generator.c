/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:13:43 by llonnrot          #+#    #+#             */
/*   Updated: 2022/01/19 13:27:28 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_clear_last(char *map, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 4;
	while (count)
	{
		if (map[i] == c)
		{
			map[i] = '.';
			count--;
		}
		i++;
	}
	return (map);
}

static size_t	ft_get_nl(char *map, int a)
{
	int		i;
	size_t	count;

	i = 0;
	count = 2;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			count++;
		i++;
	}
	if (a == 1)
		return ((count * 2) - 1);
	else
		return (count);
}

static char	*ft_enlarge_map(char *map)
{
	int		y;
	size_t	i;
	size_t	len;
	size_t	counter;
	char	*newmap;

	i = ft_get_nl(map, 0);
	len = ft_strlen(map) + ft_get_nl(map, 1);
	newmap = ft_strnew(len);
	ft_strdel(&map);
	counter = 0;
	y = 0;
	while (len != 1)
	{
		newmap[y] = '.';
		counter++;
		if (counter == i)
		{
			newmap[y] = '\n';
			counter = 0;
		}
		y++;
		len--;
	}
	return (newmap);
}

void	ft_map_generator(char **tetrominos)
{
	t_ints3	ints;
	char	*map;

	ints.x = 0;
	ints.y = 0;
	while (tetrominos[ints.x][ints.y] != '\0')
		ints.x++;
	ints.i = 2;
	while (ints.i * ints.i < ints.x * 4)
		ints.i++;
	map = ft_strnew(ints.i * ints.i + ints.i);
	ints.x = 0;
	while (ints.y < ints.i * ints.i + ints.i)
	{
		map[ints.y] = '.';
		ints.x++;
		if (ints.x == ints.i + 1)
		{
			map[ints.y] = '\n';
			ints.x = 0;
		}
		ints.y++;
	}
	while (0 == ft_place_to_map(0, 0, map, tetrominos))
		map = ft_enlarge_map(map);
}
