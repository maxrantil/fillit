/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:13:43 by llonnrot          #+#    #+#             */
/*   Updated: 2022/01/17 19:34:16 by max              ###   ########.fr       */
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

size_t	ft_get_nl(char *map, int a)
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

char	*ft_enlarge_map(char *map)
{
	int		y;
	int		i;
	size_t	len;
	int		counter;
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
	int		x;
	int		i;
	int		y;
	int		counter;
	char	*map;

	x = 0;
	y = 0;
	while (tetrominos[x][y] != '\0')
		x++;
	i = 2;
	while ((i * i) < (x * 4))
		i++;
	map = ft_strnew(i * i + i);
	counter = 0;
	while (y < (i * i + i))
	{
		map[y] = '.';
		counter++;
		if (counter == i + 1)
		{
			map[y] = '\n';
			counter = 0;
		}
		y++;
	}
	ft_place_to_map(0, 0, map, tetrominos);
}
