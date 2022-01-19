/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_to_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:59:27 by mrantil           #+#    #+#             */
/*   Updated: 2022/01/19 13:26:42 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_free_tm(char **tetrominos, int x, char *map)
{
	ft_putstr(map);
	while (x >= 0)
		ft_strdel(&tetrominos[x--]);
	ft_strdel(&map);
	free(tetrominos);
	return (1);
}

static int	ft_validspot(int i, t_ints4 ll, int *ret, char *map)
{
	if (i + ret[0] < ll.len && i + ret[1] < ll.len
		&& i + ret[2] < ll.len && i + ret[3] < ll.len
		&& map[i + ret[0]] == '.' && map[i + ret[1]] == '.'
		&& map[i + ret[2]] == '.' && map[i + ret[3]] == '.')
	{
		map[i + ret[0]] = ll.letter;
		map[i + ret[1]] = ll.letter;
		map[i + ret[2]] = ll.letter;
		map[i + ret[3]] = ll.letter;
		return (1);
	}
	else
		return (0);
}

int	ft_place_to_map(int x, int i, char *map, char **tetrominos)
{
	int			*ret;
	t_ints4		ll;

	if (tetrominos[x][0] == '\0')
		return (ft_free_tm(tetrominos, x, map));
	ll.letter = 'A';
	ret = ft_what_shape(tetrominos, map, x);
	ll.letter = ll.letter + x;
	x++;
	ll.len = (int)ft_strlen(map);
	while (map[i] != '\0')
	{
		if (ft_validspot(i, ll, ret, map))
		{
			if (ft_place_to_map(x, 0, map, tetrominos))
				return (1);
			else
				ft_clear_last(map, ll.letter);
		}
		i++;
	}
	return (0);
}
