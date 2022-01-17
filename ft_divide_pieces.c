/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_pieces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llonnrot <llonnrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:09:35 by llonnrot          #+#    #+#             */
/*   Updated: 2022/01/06 13:39:33 by llonnrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_divide_pieces(char *pieces, char **tetrominos)
{
	t_ints0	index;

	index.i = 0;
	index.x = 0;
	index.y = 0;
	index.len = ft_strlen(pieces);
	while (index.i < index.len)
	{
		if (pieces[index.i] == '\n' && pieces[index.i + 1] == '\n')
		{
			index.i = index.i + 2;
			index.x++;
			index.y = 0;
		}
		tetrominos[index.x][index.y] = pieces[index.i];
		index.i++;
		index.y++;
	}
	tetrominos[index.x][index.y - 1] = '\0';
}
