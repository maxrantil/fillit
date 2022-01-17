/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_pieces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llonnrot <llonnrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:49:58 by llonnrot          #+#    #+#             */
/*   Updated: 2021/12/30 17:02:46 by llonnrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_verify_pieces(char **tetrominos)
{
	t_ints3	index;

	index.i = 0;
	index.y = 0;
	index.x = 0;
	while (tetrominos[index.x][0] != '\0')
	{
		while (tetrominos[index.x][index.y] != '\0')
		{
			if (tetrominos[index.x][index.y] != '.'
				&& tetrominos[index.x][index.y] != '#'
				&& tetrominos[index.x][index.y] != '\n')
				return (-1);
			index.y++;
		}
		if (tetrominos[index.x][4] != '\n' || tetrominos[index.x][9] != '\n'
			|| tetrominos[index.x][14] != '\n'
			|| tetrominos[index.x][19] != '\0')
			return (-1);
		index.y = 0;
		index.x++;
	}
	return (0);
}
