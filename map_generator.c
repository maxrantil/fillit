/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:13:43 by llonnrot          #+#    #+#             */
/*   Updated: 2022/02/01 15:56:17 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	get_nl(int i, size_t count, int a, char *map)
{
	while (map[i++] != '\0')
	{
		if (map[i] == '\n')
			count++;
	}
	if (a == 1)
		return ((count * 2) - 1);
	return (count);
}

static char	*enlarge_map(int y, size_t counter, char *map)
{
	size_t	i;
	size_t	len;
	char	*newmap;

	i = get_nl(0, 0, 2, map);
	len = ft_strlen(map) + get_nl(0, 1, 2, map);
	newmap = ft_strnew(len);
	ft_strdel(&map);
	while (len-- != 1 && ++counter)
	{
		newmap[y] = '.';
		if (counter == i)
		{
			newmap[y] = '\n';
			counter = 0;
		}
		y++;
	}
	return (newmap);
}

void	map_generator(int i, int x, int y, char **tm)
{
	char		*map;

	while (tm[x][y] != '\0')
		x++;
	i = 2;
	while (i * i < x * 4)
		i++;
	map = ft_strnew(i * i + i);
	x = 0;
	while (y < i * i + i)
	{
		map[y] = '.';
		x++;
		if (x == i + 1)
		{
			map[y] = '\n';
			x = 0;
		}
		y++;
	}
	while (0 == place_to_map(0, 0, map, tm))
		map = enlarge_map(0, 0, map);
}
