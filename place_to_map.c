/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_to_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:59:27 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/01 17:48:35 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_clear_last(int i, int count, char *map, int c)
{
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

static int	free_tm_and_ret(char **tetrominos, int x, char *map)
{
	ft_putstr(map);
	while (x >= 0)
		ft_strdel(&tetrominos[x--]);
	ft_strdel(&map);
	free(tetrominos);
	return (1);
}

static int	validspot(size_t i, t_struct ll, int *ret, char *map)
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
	return (0);
}

int	place_to_map(int i, int x, t_char_ptr ptr, int *ret)
{
	t_struct	ll;

	if (ptr.tm[x][0] == '\0')
		return (free_tm_and_ret(ptr.tm, x, ptr.map));
	ll.letter = 'A';
	ll.letter += x;
	ll.len = (int)ft_strlen(ptr.map);
	x++;
	while (ptr.map[i] != '\0')
	{
		if (validspot(i, ll, ret, ptr.map))
		{
			if (place_to_map(0, x, ptr, what_shape(ptr, x)))
				return (1);
			else
				ft_clear_last(0, 4, ptr.map, ll.letter);
		}
		i++;
	}
	return (0);
}
