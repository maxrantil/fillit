/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_to_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:34:49 by max               #+#    #+#             */
/*   Updated: 2022/01/17 19:35:33 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_tm(char **tetrominos, int x)
{
	while (x >= 0)
	{
		ft_strdel(&tetrominos[x--]);
	}
	free(tetrominos);
}

int	ft_validspot(int i, int len, int *ret, char *map)
{
	if (i + ret[0] < len && i + ret[1] < len
		&& i + ret[2] < len && i + ret[3] < len
		&& map[i + ret[0]] == '.' && map[i + ret[1]] == '.'
		&& map[i + ret[2]] == '.' && map[i + ret[3]] == '.')
	{
		map[i + ret[0]] = letter;
		map[i + ret[1]] = letter;
		map[i + ret[2]] = letter;
		map[i + ret[3]] = letter;
		return (1);
	}
	else
		return (0);
}

int	ft_place_to_map(int x, int i, char *map, char **tetrominos)
{
	int		*ret;
	char	letter;
	int		len;

	if (x == -1)
		x = 0;
	if (tetrominos[x][0] == '\0')
	{
		ft_putstr(map);
		ft_free_tm(tetrominos, x);
		ft_strdel(&map);
		return (1);
	}
	len = ft_strlen(map);
	if (x == 0 && i == 1 + len)
	{
		map = ft_enlarge_map(map);
		i = 0;
	}
	letter = 'A';
	ret = ft_what_shape(tetrominos, map, x);
	letter = letter + x;
	x++;
	while (map[i] != '\0')
	{
		if (ft_validspot(i, len, ret, map))
		{
			if (ft_place_to_map(x, 0, map, tetrominos))
				return (1);
			else
				ft_clear_last(map, letter);
		}
		i++;
	}
	return (0);
}
