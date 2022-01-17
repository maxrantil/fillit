/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_tetrominos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llonnrot <llonnrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:48:26 by llonnrot          #+#    #+#             */
/*   Updated: 2021/12/30 17:04:51 by llonnrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_malloc_tetrominos(int count)
{
	int		i;
	char	**tetrominos;

	if (count == -1)
		ft_putstr("error, reading failed, fd not valid\n");
	tetrominos = (char **)malloc(sizeof(char *) * (count));
	i = 0;
	while (i < count)
	{
		tetrominos[i] = ft_strnew(BUFF_SIZE);
		i++;
	}
	return (tetrominos);
}
